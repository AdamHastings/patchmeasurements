#include "crypto.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>  
#include <stdio.h>  
#include <time.h> 
using namespace std;


string crypto::EncryptFile(string content, vector<BYTE> key) {

    string retbuf = "";
    
    
    BYTE bytekey[32];
    WORD key_schedule[60];
    for (size_t i = 0; i < 32; i++) {
        bytekey[i] = key[i];
    }

    aes_key_setup(bytekey, key_schedule, 256);

    // Seed the random-number generator with the current time so that  
    // the numbers will be different every time we run.  
    srand((unsigned)time(NULL));

    BYTE iv[16]; // = rand()
    for (size_t i = 0; i < 16; i++) {
        iv[i] = rand() % sizeof(BYTE);
    }

    BYTE toXor[16];
    //ofstream myfile(writeToFile, std::ios_base::app);
    //if (myfile.is_open()) {
    for (size_t i = 0; i < 16; i++) {
        //myfile << iv[i];
        retbuf += iv[i];
        toXor[i] = iv[i];
    }
    //    myfile << "\n";
    retbuf += "\n";
    //    myfile.close();
    //}

    
    bool padding = false;
    for (size_t i = 0; i < content.length(); i += 16) {
        // plaintext set up
        BYTE plaintext[16];
        size_t j = 0;
        size_t k = i;
        for (k = i; k < content.length() && j < 16; j++) {
            plaintext[j] = content[k];
            k++;
        }
        if (j != 16) { // j = 3, need to pad from index 3-15
            padding = true;
            int bytesLeft = 16 - j;
            for (size_t h = j; h < 16; h++) {
                plaintext[h] = bytesLeft;
            }
        }
        // xor
        for (size_t k = 0; k < 16; k++) {
            plaintext[k] = plaintext[k] ^ toXor[k];
        }
        BYTE out[16];
        // encrypt
        aes_encrypt(plaintext, out, key_schedule, 256);
        // ciphertext
        //ofstream myfile(writeToFile, std::ios_base::app);
        //if (myfile.is_open()) {
            for (size_t m = 0; m < 16; m++) {
                //myfile << out[m];
                retbuf += out[m];
                toXor[m] = out[m];
            }
            //myfile << "\n";
            retbuf += "\n";
            //myfile.close();
        //}
    }
    // Add more padding if no padding was done
    if (!padding) {
        BYTE plaintext[16];
        for (size_t k = 0; k < 16; k++) {
            plaintext[k] = 16;
        }
        for (size_t k = 0; k < 16; k++) {
            plaintext[k] = plaintext[k] ^ toXor[k];
        }
        BYTE out[16];
        aes_encrypt(plaintext, out, key_schedule, 256);
        //ofstream myfile(writeToFile, std::ios_base::app);
        //if (myfile.is_open()) {
            for (size_t i = 0; i < 16; i++) {
                //myfile << out[i];
                retbuf += out[i];
                toXor[i] = out[i];
            }
            //myfile << "\n";
            retbuf += "\n";
            //myfile.close();
        //}
    }
    

    return retbuf;
}

string crypto::getHMAC(string contents, vector<BYTE> key) {

    string retbuf = "";
    return retbuf;
}

void crypto::addFile(string filename, string content, string password) {
    vector<BYTE> enc_key = generateKey(password);
    vector<BYTE> mac_key = generateKey2(password);

    string encrypted_contents = EncryptFile(content, enc_key);
    string hmac_contents = getHMAC(content, mac_key);

    ofstream myfile;
    myfile.open(filename);
    myfile << hmac_contents;
    myfile << "\n";
    myfile << encrypted_contents;
    myfile.close();
    //std::ofstream file
}

vector<BYTE> crypto::generateKey(string password) {
    SHA256_CTX ctx;
    BYTE buf[SHA256_BLOCK_SIZE];

    const unsigned char* byte = reinterpret_cast<const unsigned char*>(password.c_str());


    sha256_init(&ctx);
    sha256_update(&ctx, byte, password.size());
    sha256_final(&ctx, buf);

    for (int i = 0; i < 11000; i++) {
        byte = buf;
        sha256_init(&ctx);
        sha256_update(&ctx, byte, password.size());
        sha256_final(&ctx, buf);
    }

    vector<BYTE> bytes;
    for (char c : buf) {
        bytes.push_back(c);
    }
    return bytes;
}

vector<BYTE> crypto::generateKey2(string password) {
    SHA256_CTX ctx;
    BYTE buf[SHA256_BLOCK_SIZE];

    const unsigned char* byte = reinterpret_cast<const unsigned char*>(password.c_str());


    sha256_init(&ctx);
    sha256_update(&ctx, byte, password.size());
    sha256_final(&ctx, buf);

    for (int i = 0; i < 21000; i++) {
        byte = buf;
        sha256_init(&ctx);
        sha256_update(&ctx, byte, password.size());
        sha256_final(&ctx, buf);
    }

    vector<BYTE> bytes;
    for (char c : buf) {
        bytes.push_back(c);
    }
    return bytes;
}
