#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#include "crypto_helpers.h"
#include "sha256.h"
#include "aes.h"

#define SHA_ITERS 10000
#define DATA_BUF_SIZE (AES_BLOCK_SIZE * 256)

void randomize(BYTE data[], size_t len){
        FILE *fp;

        if((fp = fopen("/dev/urandom", "r")) == NULL){
                perror("cstore");
                exit(1);
        }

        if(fread(data, 1, len, fp) != len){
                perror("cstore");
                fclose(fp);
                exit(1);
        }

        fclose(fp);
}


void encrypt_password(char *password, BYTE key[SHA256_BLOCK_SIZE]){
        SHA256_CTX ctx;
        int i;

        sha256_init(&ctx);
        sha256_update(&ctx, (BYTE *)password, strlen(password));
        sha256_final(&ctx, key);

        for(i = 0; i < SHA_ITERS; i++) {
                sha256_init(&ctx);
	        sha256_update(&ctx, key, SHA256_BLOCK_SIZE);
                sha256_final(&ctx, key);
        }
}

void extend_key(const BYTE key[SHA256_BLOCK_SIZE], 
                        BYTE auth_key[SHA256_BLOCK_SIZE], const char *ext){
        SHA256_CTX ctx;
        
        sha256_init(&ctx);
        sha256_update(&ctx, key, SHA256_BLOCK_SIZE);
        sha256_update(&ctx, (BYTE *)ext, strlen(ext));
        sha256_final(&ctx, auth_key);
}


size_t pad(size_t n, size_t blocksize){
        return n + ((n % blocksize == 0) ? 0 : blocksize - (n % blocksize));
}


int aes_cbc_encrypt(BYTE data[], BYTE encrypt[], size_t len, 
                                BYTE iv[AES_BLOCK_SIZE], WORD key_schedule[60]){

        int i,j,block_i;

        BYTE prev[AES_BLOCK_SIZE], xor[AES_BLOCK_SIZE];
        memcpy(prev, iv, AES_BLOCK_SIZE);

        if(len % AES_BLOCK_SIZE != 0){
              return -1;  
        }

        for(i = 0; i < len/AES_BLOCK_SIZE; i++){
                block_i = i * AES_BLOCK_SIZE;

                // XOR
                for(j = 0; j < AES_BLOCK_SIZE; j++){
                        xor[j] = data[block_i + j] ^ prev[j];
                }

                // Encrypt the block
                aes_encrypt(xor, encrypt + block_i, key_schedule, 256);
                
                // Update the IV
                memcpy(prev, encrypt + block_i, AES_BLOCK_SIZE);
                
        }

        return 0;
}

int aes_cbc_decrypt(BYTE data[], BYTE decrypt[], size_t len, 
                                BYTE iv[AES_BLOCK_SIZE], WORD key_schedule[60]){
        int i,j,block_i;

        BYTE prev[16];
        memcpy(prev, iv, AES_BLOCK_SIZE);

        if(len % AES_BLOCK_SIZE != 0){
                return -1;
        }

        for(i = 0; i < len/AES_BLOCK_SIZE; i++){
                block_i = i * AES_BLOCK_SIZE;

                aes_decrypt(data + block_i, 
                            decrypt + block_i, 
                            key_schedule, 256);

                for(j = 0; j < AES_BLOCK_SIZE; j++){
                        decrypt[block_i + j] ^= prev[j];
                }

                memcpy(prev, data + block_i, AES_BLOCK_SIZE);
        }

        return 0;
}

int hmac_file(const char *path, const BYTE key[SHA256_BLOCK_SIZE], 
                                      BYTE out[SHA256_BLOCK_SIZE], int offset){
        int i, n;
        FILE *fp;
        SHA256_CTX ctx;

        BYTE key_copy[SHA256_BLOCK_SIZE], 
             data[DATA_BUF_SIZE], 
             inner[SHA256_BLOCK_SIZE];

        memcpy(key_copy, key, SHA256_BLOCK_SIZE);
        for(i = 0; i < SHA256_BLOCK_SIZE; i++){
                key_copy[i] ^= 0x36;
        } 

        sha256_init(&ctx);
        sha256_update(&ctx, key_copy, SHA256_BLOCK_SIZE);

        if((fp = fopen(path, "r")) == NULL){
                return errno;
        }

        if(fseek(fp, offset, SEEK_SET) < 0){
                fclose(fp);
                return errno;
        }

        while((n = fread(data, 1, sizeof(data), fp)) > 0){
                sha256_update(&ctx, data, n);
        }
        if(n < 0){
                fclose(fp);
                return errno;
        }
        else{
                fclose(fp);
        }

        sha256_final(&ctx, inner);

        memcpy(key_copy, key, SHA256_BLOCK_SIZE);
        for(i = 0; i < SHA256_BLOCK_SIZE; i++){
                key_copy[i] ^= 0x5c;
        }

        sha256_init(&ctx);
        sha256_update(&ctx, key_copy, SHA256_BLOCK_SIZE);
        sha256_update(&ctx, inner, SHA256_BLOCK_SIZE);
        sha256_final(&ctx, out);

        return 0;
}
