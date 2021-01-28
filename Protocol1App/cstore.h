
#ifndef CSTORE_H
#define CSTORE_H

#include <stdlib.h>
#include <errno.h>
#include <inttypes.h>

#include "sha256.h"

#define MIN(a,b) (((a)<(b))?(a):(b))

#define PW_BUF_SIZE 1000
#define DATA_BUF_SIZE (AES_BLOCK_SIZE * 256)

#define HMAC_POS 0
#define FC_POS (HMAC_POS + SHA256_BLOCK_SIZE)

void die(char *msg){
        if(errno){
                perror(msg);
        }

        exit(1);
}

void clear_mem(char *mem, size_t len){

        FILE *fpn;
        char *err_msg;

        fpn = NULL;
        err_msg = NULL;

        memset(mem, 0, len);

        if((fpn = fopen("/dev/null", "w")) == NULL){
                err_msg = strerror(errno);
                goto cleanup;
        }

        if(fwrite(mem, 1, len, fpn) != len){
                err_msg = strerror(errno);
                goto cleanup;
        }

cleanup:

        if(fpn){
                fclose(fpn);
        }

        if(err_msg){
                fprintf(stderr, "cstore: %s\n", err_msg);
                exit(1);
        }
}

struct file_metadata{
        uint32_t name_len;
        uint32_t filesize;
        uint32_t encryption_size;
};

struct command {
	char *name;
	int minargs;
        int maxargs;
	int pw;
        int hmac;        
	int (*handler)(const char *, // archive name
		       BYTE [], // password
		       uint32_t, // number of files
		       char**); // files
};

int dedup(const char *archive, const char **filenames, 
                                        int file_count, char *checklist);

int init_handler(const char *archive, BYTE key[SHA256_BLOCK_SIZE], 
                                        uint32_t fileno, char **files);
int list_handler(const char *archive);
int list_handler_prime(const char *archive, BYTE key[SHA256_BLOCK_SIZE], 
                                             uint32_t fileno, char **files){
        return list_handler(archive);
}

int add_handler(const char *archive, BYTE key[SHA256_BLOCK_SIZE], 
                                                uint32_t fileno, char **files);

int extract_handler(const char *archive, BYTE key[SHA256_BLOCK_SIZE], 
                                                uint32_t fileno, char **files);

int delete_handler(const char *archive, BYTE key[SHA256_BLOCK_SIZE], 
                                                uint32_t fileno, char **files);

static struct command commands[] = { {.name="init", 
                                      .minargs=0, 
                                      .maxargs=-1, 
                                      .pw=1, 
                                      .hmac=0, 
                                      .handler=init_handler},
                                     {.name="list", 
                                      .minargs=0, 
                                      .maxargs=0, 
                                      .pw=0, 
                                      .hmac=0, 
                                      .handler=list_handler_prime}, 
       				     {.name="add", 
                                      .minargs=1, 
                                      .maxargs=-1, 
                                      .pw=1, 
                                      .hmac=1, 
                                      .handler=add_handler},
			             {.name="extract", 
                                      .minargs=1, 
                                      .maxargs=-1, 
                                      .pw=1, .hmac=1, 
                                      .handler=extract_handler},
			             {.name="delete", 
                                      .minargs=1, 
                                      .maxargs=-1, 
                                      .pw=1, 
                                      .hmac=1, 
                                      .handler=delete_handler} };

#endif
