/*
 *  Author: Gustaf Ahdritz
 *  UNI: gwa2107 
 *  HW1: Encrypted File Store
 */

#include <stdio.h>
#include <stdlib.h>
//#include <unistd.h>
//#include <libgen.h>
#include <ctype.h>
#include <string.h>
//#include <termios.h>
#include <memory.h>
#include <limits.h>
#include <sys/stat.h>
#include <inttypes.h>
//#include <sys/mman.h>

#include "cstore.h"
#include "crypto_helpers.h"

// Checks an archive and the inputted list of files for duplicate files
int dedup(const char *archive, const char **filenames, 
                                        int file_count, char *checklist) {
    
    int i, j, return_value;
    char *filename, *f1, *f2, *bs_name, *bs_name2;
    struct file_metadata meta;
    uint32_t archive_fc;
    FILE *fp;

    return_value = 0;

    if((fp = fopen(archive, "rb")) == NULL){
        return_value = errno;
        goto cleanup;
    }

    if(fseek(fp, FC_POS, SEEK_SET) < 0){
        return_value = errno;
        goto cleanup;
    }

    if(fread(&archive_fc, 1, sizeof(archive_fc), fp) != sizeof(archive_fc)){
        return_value = errno;
        goto cleanup;
    }

    for(i = 0; i < archive_fc; i++){
        if(fread(&meta, 1, sizeof(meta), fp) != sizeof(meta)){
            return_value = errno;
            goto cleanup;
        }

        if((filename = 
                (char *)malloc(sizeof(char)*(meta.name_len + 1))) == NULL){
            return_value = errno;
            goto cleanup;
        }

        if(fread(filename, 1, meta.name_len, fp) != meta.name_len){
            return_value = errno;
            free(filename);
            goto cleanup;
        }
        filename[meta.name_len] = '\0';

        for(j = 0; j < file_count; j++){
            if((f1 = (char *)malloc(sizeof(char)*(strlen(filenames[j]) + 1))) 
                == NULL){
                return_value = errno;
                free(filename);
                goto cleanup;
            }

            memcpy(f1, filenames[j], strlen(filenames[j]) + 1);
            bs_name = basename(f1);
            if(strlen(bs_name) == meta.name_len &&
               strncmp(filename, 
                   bs_name, 
                   meta.name_len) == 0){
                checklist[j] = 1;
            }

            free(f1);
        }

        free(filename);

        if(fseek(fp, meta.encryption_size, SEEK_CUR)){
            return_value = errno;
            goto cleanup;
        }
    }

    // Check for duplicates within the list of files
    for(i = 0; i < file_count - 1; i++){
        if(checklist[i] == 0){

            if((f1 = (char *)malloc(sizeof(char)*(strlen(filenames[i]) + 1))) 
                == NULL){
                return_value = errno;
                goto cleanup;
            }

            memcpy(f1, filenames[i], strlen(filenames[i]) + 1);
            bs_name = basename(f1);
            for(j = i + 1; j < file_count; j++){
                if(checklist[j] == 0){

                    if((f2 = 
                        (char *)malloc(sizeof(char)*(strlen(filenames[j]) + 1)))
                         == NULL){
                        return_value = errno;
                        free(f1);
                        goto cleanup;
                    }

                    memcpy(f2, filenames[j], strlen(filenames[j]) + 1); 
                    bs_name2 = basename(f2);
                    if(strlen(bs_name) == strlen(bs_name2) &&
                        strncmp(bs_name, bs_name2, strlen(bs_name)) == 0){
                        checklist[j] = 1;
                    }

                    free(f2);
                }
            }

            free(f1);
        }
    }

cleanup:

    if(fp){
        fclose(fp);
    }

    return return_value;
}


int list_handler(const char *archive) {
       
    uint32_t filecount;
    struct file_metadata meta;
    FILE *fp;

    char *filename, *err_msg;

    fp = NULL;
    filename = NULL;
    err_msg = NULL;

    // Open the archvie
    if((fp = fopen(archive, "rb")) == NULL){
        err_msg = strerror(errno);
        goto cleanup;
    }

    // Skip the HMAC
    if(fseek(fp, FC_POS, SEEK_SET) < 0){
        err_msg = strerror(errno);
        goto cleanup;
    }

    if(fread(&filecount, 1, sizeof(filecount), fp) != sizeof(filecount)){
        err_msg = strerror(errno);
        if(feof(fp)){
            err_msg = "Invalid archive";
        }
        goto cleanup;
    }

    while((filecount--) > 0){

        // Read the filename into memory
        if(fread(&meta, 1, sizeof(meta), fp) != sizeof(meta)){
            err_msg = strerror(errno);
            if(feof(fp)){
                err_msg = "Invalid archive";
            }
            goto cleanup;
        }

        if(meta.name_len > NAME_MAX){
            err_msg = "Invalid archive";
            goto cleanup;
        }

        if((filename = 
              (char *)malloc(sizeof(char)*(meta.name_len + 1))) == NULL){
            err_msg = strerror(errno);
            goto cleanup;
        }
        filename[meta.name_len] = '\0';

        if(fread(filename, 1, meta.name_len, fp) != meta.name_len){
            err_msg = strerror(errno);
            if(feof(fp)){
                err_msg = "Invalid archive";
            }
            free(filename);
            goto cleanup;    
        }

        // Skip the rest of the file
        if(fseek(fp, meta.encryption_size, SEEK_CUR) < 0){
            err_msg = strerror(errno);
            free(filename);
            goto cleanup; 
        }

        printf("%s\n", filename);
        free(filename);
    }

cleanup:

    if(fp){
        fclose(fp);
    }

    if(err_msg){
        fprintf(stderr, "cstore list: %s\n", err_msg);
        return -1;
    }

    return 0;
}


int init_handler(const char *archive, BYTE key[SHA256_BLOCK_SIZE], 
                                        uint32_t fileno, char **files){
    
    uint32_t zero;
    FILE *fp_arch;
    
    WORD key_schedule[60];
    aes_key_setup(key, key_schedule, 256);
    char *err_msg = NULL;

    // Create a new archive
    if((fp_arch = fopen(archive, "wb")) == NULL){
        err_msg = strerror(errno);
        goto cleanup;
    }

    // Set its filecount to zero
    if(fseek(fp_arch, FC_POS, SEEK_SET) < 0){
        err_msg = strerror(errno);
        fclose(fp_arch);
        goto cleanup;
    }

    zero = 0;
    if(fwrite(&zero, 1, sizeof(zero), fp_arch) != sizeof(zero)){
        err_msg = strerror(errno);
        fclose(fp_arch);
        goto cleanup;
    }

    fclose(fp_arch);

    // Add the desired files
    if(fileno > 0){
        add_handler(archive, key, fileno, files);
    }

cleanup:

    if(err_msg){
        remove(archive);
        fprintf(stderr, "cstore init: %s\n", err_msg);
        return -1;
    }

    return 0;
}


int add_handler(const char *archive, BYTE key[SHA256_BLOCK_SIZE], 
                                                uint32_t fileno, char **files){
    
    int i, n, arch_fc, files_added, err;
    FILE *fp_arch, *fp_file;
    struct stat buffer;
    struct file_metadata meta;

    BYTE data[DATA_BUF_SIZE], encrypted[DATA_BUF_SIZE], iv[AES_BLOCK_SIZE];
    WORD key_schedule[60];
    
    char *checklist, *filename_copy, *bs_name, *err_msg;

    err_msg = NULL;
    checklist = NULL;
    
    aes_key_setup(key, key_schedule, 256);

    // Prepare to check for duplicates
    if((checklist = (char *)malloc(sizeof(char)*fileno)) == NULL){
        die("cstore add");
    }

    memset(checklist, 0, fileno);
    if((err = dedup(archive, (const char **)files, fileno, checklist))){
        err_msg = strerror(err);
        goto cleanup;
    }

    if((fp_arch = fopen(archive, "r+b")) == NULL){
        err_msg = strerror(errno);
        goto cleanup;
    }

    if(fseek(fp_arch, 0, SEEK_END)){
        err_msg = strerror(errno);
        goto cleanup;
    }

    files_added = 0;
    for(i = 0; i < fileno; i++){
        
        // If the file is not a duplicate
        if(checklist[i] == 0){

            // Gather the file metadata
            if((filename_copy = 
                 (char *)malloc(sizeof(char)*(strlen(files[i]) + 1))) == NULL){
                err_msg = strerror(errno);
                goto cleanup;

            }

            memcpy(filename_copy, files[i], strlen(files[i]) + 1);
            bs_name = basename(filename_copy);

            meta.name_len = strlen(bs_name);

            if(!stat(files[i], &buffer)){
                meta.filesize = buffer.st_size;
            }
            else{
                free(filename_copy);
                printf("Skipping %s (file does not exist)...\n", files[i]);
                continue;
            }

            meta.encryption_size = AES_BLOCK_SIZE + 
                                   pad(meta.filesize, AES_BLOCK_SIZE);

            // And write it to the archive
            if(fwrite(&meta, 1, sizeof(meta), fp_arch) != sizeof(meta) ||
               fwrite(bs_name, 1, meta.name_len, fp_arch) != meta.name_len){
                err_msg = strerror(errno);
                free(filename_copy);
                goto cleanup;
            }

            free(filename_copy);

            // Write an IV
            randomize(iv, AES_BLOCK_SIZE);
            if(fwrite(iv, 1, AES_BLOCK_SIZE, fp_arch) != AES_BLOCK_SIZE){
                err_msg = strerror(errno);
                goto cleanup;
            }

            if((fp_file = fopen(files[i], "r")) == NULL){
                err_msg = strerror(errno);
                goto cleanup;
            }

            // We'll need to read potentially uninitialized bytes as padding
            memset(data, 0, sizeof(data));

            // Now write the (encrypted) file
            while((n = fread(data, 1, sizeof(data), fp_file)) > 0){

                n = pad(n, AES_BLOCK_SIZE);

                aes_cbc_encrypt(data, encrypted, n, iv, key_schedule);

                if(fwrite(encrypted, 1, n, fp_arch) != n){
                    err_msg = strerror(errno);
                    fclose(fp_file);
                    goto cleanup;
                }

                memcpy(iv, encrypted + n - AES_BLOCK_SIZE, AES_BLOCK_SIZE);
            }

            fclose(fp_file);

            files_added += 1;
        }
        else{
            printf("cstore add: Skipping %s (name conflict)\n", files[i]);
        }
    }

    // Fix the file counter
    if(fseek(fp_arch, FC_POS, SEEK_SET)){
        err_msg = strerror(errno);
        goto cleanup;
    }

    if(fread(&arch_fc, 1, sizeof(arch_fc), fp_arch) != sizeof(arch_fc)){
        err_msg = strerror(errno);
        goto cleanup;
    }

    arch_fc += files_added;

    if(fseek(fp_arch, FC_POS, SEEK_SET)){
        err_msg = strerror(errno);
        goto cleanup;
    }

    if(fwrite(&arch_fc, 1, sizeof(arch_fc), fp_arch) != sizeof(arch_fc)){
        err_msg = strerror(errno);
        goto cleanup;
    }
  
cleanup:

    if(checklist){
        free(checklist);
    }

    if(fp_arch){
        fclose(fp_arch);
    }

    if(err_msg){
        fprintf(stderr, "cstore add: %s\n", err_msg);
        return -1;
    }

    return 1;
}


int extract_handler(const char *archive, BYTE key[SHA256_BLOCK_SIZE], 
                                               uint32_t fileno, char **files){
    
    int j, n, bytes_read, bytes_to_read, 
        bytes_written, bytes_to_write, file_read;
    uint32_t arch_fc;
    struct file_metadata meta;
    FILE *fp_arch, *fp_file;

    BYTE data[DATA_BUF_SIZE], decrypted[DATA_BUF_SIZE], iv[AES_BLOCK_SIZE];
    WORD key_schedule[60];

    char *err_msg, *filename, *checklist;

    err_msg = NULL;
    checklist = NULL;

    aes_key_setup(key, key_schedule, 256); 

    // Open the archive
    if((fp_arch = fopen(archive, "rb")) == NULL){
        err_msg = strerror(errno);
        goto cleanup;
    }

    // Skip the HMAC
    if(fseek(fp_arch, FC_POS, SEEK_SET) < 0){
        err_msg = strerror(errno);
        goto cleanup;
    }

    if(fread(&arch_fc, 1, sizeof(arch_fc), fp_arch) != sizeof(arch_fc)){
        err_msg = strerror(errno);
        goto cleanup;
    }

    if((checklist = (char *)malloc(sizeof(char)*fileno)) == NULL){
        err_msg = strerror(errno);
        goto cleanup;
    }
    memset(checklist, 0, sizeof(char)*fileno);

    while(arch_fc--){

        if(fread(&meta, 1, sizeof(meta), fp_arch) != sizeof(meta)){
            err_msg = strerror(errno);
            goto cleanup;
        }

        if((filename = 
                (char *)malloc(sizeof(char)*(meta.name_len + 1))) == NULL){
            err_msg = strerror(errno);
            goto cleanup;
        }

        if(fread(filename, 1, meta.name_len, fp_arch) != meta.name_len){
            err_msg = strerror(errno);
            free(filename);
            goto cleanup;
        }
        filename[meta.name_len] = '\0';

        file_read = 0;
        for(j = 0; j < fileno; j++){

            // If the file matches, we extract it
            if(meta.name_len == strlen(files[j]) &&
               strncmp(filename, files[j], meta.name_len) == 0){
                checklist[j] = 1;
                file_read = 1;
                   
                if((fp_file = fopen(filename, "wb")) == NULL){
                    err_msg = strerror(errno);
                    free(filename);
                    goto cleanup;
                }

                if((n = fread(iv, 1, sizeof(iv), fp_arch)) != sizeof(iv)){
                    err_msg = strerror(errno);
                    free(filename);
                    goto cleanup;
                }

                bytes_read = sizeof(iv);
                bytes_written = 0;
                while(bytes_read < meta.encryption_size){
                    bytes_to_read = MIN(sizeof(data), 
                                         meta.encryption_size - bytes_read);
                    if((n = fread(data, 1, bytes_to_read, fp_arch)) 
                                                            != bytes_to_read){
                        err_msg = strerror(errno);
                        free(filename);
                        fclose(fp_file);
                        goto cleanup; 
                    }
                    bytes_read += n;

                    aes_cbc_decrypt(data, decrypted, n, iv, key_schedule); 

                    memcpy(iv, data + n - AES_BLOCK_SIZE, AES_BLOCK_SIZE);

                    bytes_to_write = MIN(n, meta.filesize - bytes_written);
                    if((n = fwrite(decrypted, 1, bytes_to_write, fp_file) 
                                                          != bytes_to_write)){
                        err_msg = strerror(errno);
                        free(filename);
                        fclose(fp_file);
                        goto cleanup;
                    }
                    bytes_written += n;
                }

                fclose(fp_file);

                break;
            }
        }

        free(filename);

        // The file did not match any inputted filenames---skip the file
        if(!file_read){
            if(fseek(fp_arch, meta.encryption_size, SEEK_CUR)){
                die("cstore");
            }
        }
    }

    for(j = 0; j < fileno; j++){
        if(!checklist[j]){
            printf("cstore extract: Skipping %s (file not found)...\n", 
                                                                 files[j]);
        }
    }

cleanup:

    if(checklist){
        free(checklist);
    }

    if(fp_arch){
        fclose(fp_arch);
    }

    if(err_msg){
        fprintf(stderr, "cstore extract: %s\n", err_msg);
        return -1;
    }

    return 0;
}


int delete_handler(const char *archive, BYTE key[SHA256_BLOCK_SIZE], 
                                                uint32_t fileno, char **files){
    int i, j, n, temp_descriptor, bytes_read, bytes_to_read, match;
    struct file_metadata meta;
    uint32_t arch_fc, file_counter;
    FILE *fp_arch, *fp_temp;

    char data[DATA_BUF_SIZE];

    char *checklist, *temp_name, *name_extension, *err_msg, *filename;

    err_msg = NULL;
    temp_name = NULL;
    checklist = NULL;
    fp_arch = NULL;
    fp_temp = NULL;
    
    if((fp_arch = fopen(archive, "rb")) == NULL){
        err_msg = strerror(errno);
        goto cleanup;
    }

    // Define the name extension required by mkstemp
    name_extension = "XXXXXX";

    if((checklist = (char *)malloc(sizeof(char)*fileno)) == NULL ||
        (temp_name = 
           (char *)malloc(sizeof(char)*(strlen(archive) + 
                                        strlen(name_extension) + 1))) == NULL){
        err_msg = strerror(errno);
        goto cleanup;
    }
    memset(checklist, 0, sizeof(char)*fileno);

    snprintf(temp_name, 
             strlen(archive) + strlen(name_extension) + 1, "%s%s", 
             archive, name_extension);

    // Create a temporary file
    if((temp_descriptor = mkstemp(temp_name)) < 0){
        err_msg = strerror(errno);
        goto cleanup;
    }

    if((fp_temp = fdopen(temp_descriptor, "r+b")) == NULL){
        err_msg = strerror(errno);
        goto cleanup;
    }

    if(fseek(fp_arch, FC_POS, SEEK_SET) < 0){
        err_msg = strerror(errno);
        goto cleanup;
    } 
    
    if(fread(&arch_fc, 1, sizeof(arch_fc), fp_arch) != sizeof(arch_fc)){
        err_msg = strerror(errno);
        goto cleanup;
    }

    // Write a temporary placeholder value for the filecount
    if(fseek(fp_temp, FC_POS + sizeof(arch_fc), SEEK_SET) < 0){
        err_msg = strerror(errno);
        goto cleanup;
    }

    file_counter = 0;
    for(i = 0; i < arch_fc; i++){
        if(fread(&meta, 1, sizeof(meta), fp_arch) != sizeof(meta)){
            err_msg = strerror(errno);
            goto cleanup;
        }

        if((filename = 
                (char *)malloc(sizeof(char)*(meta.name_len + 1))) == NULL){ 
            err_msg = strerror(errno);
            goto cleanup;
        }
        filename[meta.name_len] = '\0';

        if(fread(filename, 1, meta.name_len, fp_arch) != meta.name_len){
            err_msg = strerror(errno);
            free(filename);
            goto cleanup;
        }

        match = 0;
        for(j = 0; j < fileno; j++){
            if(meta.name_len == strlen(files[j]) &&
                 strncmp(filename, files[j], meta.name_len) == 0){
                match = 1;
                checklist[j] = 1;
                break;
            }
        }

        // If the file does not match any input names, we write it to the temp 
        // archive
        if(!match){
            if(fwrite(&meta, 1, sizeof(meta), fp_temp) != sizeof(meta) ||
               fwrite(filename, 1, meta.name_len, fp_temp) != meta.name_len) {
                err_msg = strerror(errno);
                free(filename);
                goto cleanup;
            }

            bytes_read = 0;
            while(bytes_read < meta.encryption_size){
                bytes_to_read = MIN(meta.encryption_size - bytes_read, 
                                     sizeof(data));
                if((n = fread(data, 1, bytes_to_read, fp_arch)) 
                                                   != bytes_to_read){
                    err_msg = strerror(errno);
                    free(filename);
                    goto cleanup;      
                }
                bytes_read += n;

                if(fwrite(data, 1, n, fp_temp) != n){
                    err_msg = strerror(errno);
                    free(filename);
                    goto cleanup; 
                }
            }
            file_counter += 1;
        }
        // Else, we ignore it ("deleting" it)
        else{
            if(fseek(fp_arch, meta.encryption_size, SEEK_CUR) < 0){
                err_msg = strerror(errno);
                free(filename);
                goto cleanup;
            }
        }

        free(filename);
    }

    // Update the file counter of the temporary archive
    if(fseek(fp_temp, FC_POS, SEEK_SET)){
        err_msg = strerror(errno);
        goto cleanup;
    }


    if(fwrite(&file_counter, 1, sizeof(file_counter), fp_temp) 
                                                     != sizeof(file_counter)){
        err_msg = strerror(errno);
        goto cleanup;
    }


    for(j = 0; j < fileno; j++){
        if(!checklist[j]){
            printf("cstore delete: Skipping %s (file not found)...\n", 
                      files[j]);
        } 
    }


cleanup:

    if(fp_arch){
        fclose(fp_arch);
    }

    if(fp_temp){
        fclose(fp_temp);
    }

    if(checklist){
        free(checklist);
    }

    if(err_msg){
        fprintf(stderr, "cstore delete: %s\n", err_msg);
        remove(temp_name);
        free(temp_name);
        return -1;
    }
    else{
        // Replace the real archive with the temporary one
        rename(temp_name, archive);
        free(temp_name);
    }

    return 0;
}


int main(int argc, char **argv) {
    
    char c;
    int index, fileind, pw_len, return_val, err, pw;
    char *archive_path;
    FILE *fp_arch;
    BYTE key[SHA256_BLOCK_SIZE], 
	 auth_key[SHA256_BLOCK_SIZE], 
	 hmac[SHA256_BLOCK_SIZE], 
	 stored_hmac[SHA256_BLOCK_SIZE];
    char password[PW_BUF_SIZE];

    char *optstring, *pw_temp, *usage; 
    
    struct command *cur_command = NULL;
    
    usage = "usage: cstore [-p=<password>] <command> <archivename> [<files>]" 
            "\n\n"
            "Available commands are init, list, add, extract, and delete.\n"; 
    return_val = EXIT_SUCCESS;

    // Prep to accept a password
    mlock(password, PW_BUF_SIZE);
    pw = 0;

    opterr = 0; // suppress getopt's own error messages
    optstring = "p:";
    while((c = getopt(argc, argv, optstring)) != -1) {
        switch (c) {
            case 'p':
                snprintf(password, PW_BUF_SIZE, "%s", optarg);
                        password[PW_BUF_SIZE - 1] = '\0'; 
                        pw = 1;
                break;
            case '?':
                if (optopt == 'p') {
                    fprintf(stderr, 
			    "cstore: Option -%c requires an argument.\n", 
                                                                     optopt);
                }
                else if (isprint(optopt)) {
                    fprintf(stderr, 
		            "cstore: Unknown option `-%c'.\n\n%s", 
                                                              optopt, usage);
                }
                else {
                    fprintf(stderr, 
		            "cstore: Unknown option character `\\x%x'.\n\n%s", 
                                                                        optopt, 
			    						usage);
                }

                fprintf(stderr, "%s", usage);

                return EXIT_FAILURE;

            default:
                abort();
        }
    }

    // There need to be at least two more arguments: <command> and <archivename>
    if(optind >= argc - 1) {
        fprintf(stderr, "%s", usage);
        return EXIT_FAILURE;
    }

    for(index = 0; index < sizeof(commands)/sizeof(struct command); index++){
        if(strncmp(commands[index].name, 
		   argv[optind], 
		   strlen(commands[index].name)) == 0){
            cur_command = commands + index;
            break;
        }
    }
    if(cur_command == NULL){
        fprintf(stderr, "%s", usage);
        return EXIT_FAILURE;
    }

    // Collect a password if we 1) need one 2) haven't collected it already
    if(!pw && cur_command->pw){
        pw_temp = getpass("Enter password: ");
        snprintf(password, PW_BUF_SIZE, "%s", pw_temp);
        password[PW_BUF_SIZE - 1] = '\0';
        clear_mem(pw_temp, strlen(pw_temp));
        free(pw_temp);
        pw = 1;
    }

    // If the current command requires a password, create a key
    if(cur_command->pw){
        pw_len = strlen(password);

        mlock(key, sizeof(key));
        encrypt_password(pw_len  > 0 ? password : password, key);

        mlock(auth_key, sizeof(auth_key));
        extend_key(key, auth_key, "auth");
    }

    // Clear the password buffer
    clear_mem(password, PW_BUF_SIZE);

    // Read the remaining arguments
    archive_path = argv[optind + 1];
    fileind = optind + 2;

    if(fileind > argc - cur_command->minargs){
        fprintf(stderr, 
		"cstore: Too few arguments for the %s command.\n\n%s", 
                                                        cur_command->name, 
		                                        usage);
        return_val = EXIT_FAILURE;
        goto cleanup;
    }
    else if(cur_command->maxargs >= 0 && fileind < argc - cur_command->maxargs){
        fprintf(stderr, 
		"cstore: Too many arguments for the %s command.\n\n%s", 
                                                              cur_command->name, 
		                                              usage);
        return_val = EXIT_FAILURE;
        goto cleanup;
    }

    // Authenticate the archive
    if(cur_command->hmac){
        if((err = hmac_file(archive_path, key, hmac, SHA256_BLOCK_SIZE))){
            fprintf(stderr, "cstore: %s\n", strerror(err));
            return_val = EXIT_FAILURE;
            goto cleanup;
        }

        if((fp_arch = fopen(archive_path, "r")) == NULL){
            perror("cstore");
            return_val = EXIT_FAILURE;
            goto cleanup;
        }

        if(fread(stored_hmac, 1, SHA256_BLOCK_SIZE, fp_arch) 
			!= SHA256_BLOCK_SIZE){
            perror("cstore");
            return_val = EXIT_FAILURE;
            fclose(fp_arch);
            goto cleanup;
        }

        fclose(fp_arch);

        if(memcmp(hmac, stored_hmac, SHA256_BLOCK_SIZE) != 0){
            fprintf(stderr, "cstore: Authentication failed\n");
            return_val = EXIT_FAILURE;
            goto cleanup;
        }
    }
 
    // We're ready to be dispatched
    if(cur_command->handler(archive_path, 
			    cur_command->pw ? key : NULL, 
                                          argc - fileind, argv + fileind) < 0){
        return_val = EXIT_FAILURE;
        goto cleanup;
    }

    // If the command worked, we reauthenticate the archive
    if(cur_command->pw){   
        if((err = hmac_file(archive_path, key, hmac, SHA256_BLOCK_SIZE))){
            fprintf(stderr, "cstore: %s\n", strerror(err));
            return_val = EXIT_FAILURE;
            goto cleanup;
        }

        if((fp_arch = fopen(archive_path, "r+b")) == NULL){
            perror("cstore");
            return_val = EXIT_FAILURE;
            goto cleanup;
        }

        if(fseek(fp_arch, HMAC_POS, SEEK_SET) < 0){
            perror("cstore");
            return_val = EXIT_FAILURE;
            fclose(fp_arch);
            goto cleanup;
        }

        if(fwrite(hmac, 1, SHA256_BLOCK_SIZE, fp_arch) != SHA256_BLOCK_SIZE){
            perror("cstore");
            return_val = EXIT_FAILURE;
            fclose(fp_arch);
            goto cleanup;
        }

        fclose(fp_arch);
    }


cleanup:

    munlock(password, PW_BUF_SIZE);
    
    if(cur_command->pw){
        clear_mem((char *)key, sizeof(key));
        munlock(key, sizeof(key));

        clear_mem((char *)auth_key, sizeof(auth_key));
        munlock(auth_key, sizeof(key));
    }

    return return_val;
}
