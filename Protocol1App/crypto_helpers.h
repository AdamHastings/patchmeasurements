#ifndef CRYPTO_HELPERS_H
#define CRYPTO_HELPERS_H

#include "sha256.h"
#include "aes.h"

void randomize(BYTE data[], size_t len);
void encrypt_password(char *password, BYTE key[SHA256_BLOCK_SIZE]);

void extend_key(const BYTE key[SHA256_BLOCK_SIZE], 
                        BYTE auth_key[SHA256_BLOCK_SIZE], const char *ext);

size_t pad(size_t n, size_t blocksize);

int aes_cbc_encrypt(BYTE data[], BYTE encrypt[], size_t len, 
                           BYTE iv[AES_BLOCK_SIZE], WORD key_schedule[60]);

int aes_cbc_decrypt(BYTE data[], BYTE decrypt[], size_t len, 
                           BYTE iv[AES_BLOCK_SIZE], WORD key_schedule[60]);

int hmac_file(const char *path, const BYTE key[SHA256_BLOCK_SIZE], 
                                  BYTE out[SHA256_BLOCK_SIZE], int offset);
#endif
