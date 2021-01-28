#include "crypto.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>  
#include <sstream>
#include <stdio.h>  
#include <time.h> 
#include <iomanip>
#include "aes.h"
#include "sha256.h"
#include <QDebug>
using namespace std;


tuple<string, string, string> crypto::EncryptFile(string content, vector<BYTE> key) {

    //string retbuf = "";
    string enc_contents = "";
    string iv_str = "";
    string num_blocks_str = "";
    
    BYTE bytekey[32];
    unsigned int key_schedule[60];
    for (size_t i = 0; i < 32; i++) {
        bytekey[i] = key[i];
    }

    aes_key_setup(bytekey, key_schedule, 256);
    
    BYTE iv[AES_BLOCK_SIZE];
    for (int i = 0; i < AES_BLOCK_SIZE; i++) {
        iv[i] = (BYTE)rand() % 256;
        // comment out later!!
        iv[i] = 'a';
        //iv_str += iv[i];
        stringstream ss;
        ss << hex << setw(2) << setfill('0') << (int)iv[i];
        iv_str += ss.str();
    }

    //int plaintext_length = content.length();
    //BYTE* plaintext = &content[0];

    // aes_encryp_cbc isn't going to work, because you need to a priori know the size of the array to pass in in C++. Not going to work
    //aes_encrypt_cbc()


    // So instead we are going to chaing together ECB mode
  

    int num_blocks = (content.length() / (AES_BLOCK_SIZE * sizeof(BYTE))) + 1;
    num_blocks_str = to_string(num_blocks);
    /*int remainder = content.length() % (AES_BLOCK_SIZE * sizeof(BYTE));*/

    BYTE block_output[AES_BLOCK_SIZE];
    BYTE plaintext_block[AES_BLOCK_SIZE];
    BYTE block_input[AES_BLOCK_SIZE];

    for (int j = 0; j < AES_BLOCK_SIZE; j++) {
        block_output[j] = iv[j];
    }

    for (int i = 0; i < num_blocks; i++) {

        for (int j = 0; j < AES_BLOCK_SIZE; j++) {
            if (((i * 16) + j) < content.length()) {
                plaintext_block[j] = content[(i * 16) + j];
            }
            else {
                plaintext_block[j] = 0;
            }
            
        }

        //xor plaintext block and block_output
        for (int j = 0; j < AES_BLOCK_SIZE; j++) {
            block_input[j] = block_output[j] ^ plaintext_block[j];
        }
        
        aes_encrypt(block_input, block_output, key_schedule, 256);

        // add to buffer
        for (int j = 0; j < AES_BLOCK_SIZE; j++) {
            stringstream ss;
            ss << hex << setw(2) << setfill('0') << (int)block_output[j];
            //ss << std::hex << std::setfill('0') << block_output[j];
            //sprintf(h)
            //enc_contents += block_output[j];
            enc_contents += ss.str();
        }
    }

    return { enc_contents, iv_str, num_blocks_str };
} 

string crypto::getHMAC(string contents, vector<BYTE> key) {



    BYTE i_key_pad[64];
    BYTE o_key_pad[64];

    for (int i = 0; i < key.size(); i++) {
        i_key_pad[i] = key[i] ^ 0x36;
        o_key_pad[i] = key[i] ^ 0x5c;
    }

    for (int i = key.size(); i < 64; i++) {
        i_key_pad[i] = 0x36;
        o_key_pad[i] = 0x5c;
    }

    SHA256_CTX ctx;
    BYTE buf[SHA256_BLOCK_SIZE];

    const unsigned char* message = reinterpret_cast<const unsigned char*>(contents.c_str());

    sha256_init(&ctx);
    sha256_update(&ctx, message, contents.size());
    sha256_final(&ctx, buf);

    //string test = "abc";
    //BYTE message2[] = { (unsigned) test.c_str() };
    BYTE message2[64 + SHA256_BLOCK_SIZE];
    for (int i = 0; i < 64 + SHA256_BLOCK_SIZE; i++) {
        if (i < 64) {
            message2[i] = o_key_pad[i];
        }
        else {
            message2[i] = buf[i - 64];
        }
    }


    sha256_init(&ctx);
    sha256_update(&ctx, message2, 96);
    sha256_final(&ctx, buf);
    
    string retbuf = "";

    for (int i = 0; i < SHA256_BLOCK_SIZE; i++) {
        stringstream ss;
        ss << hex << setw(2) << setfill('0') << (int)buf[i];
        retbuf += ss.str();
    }
    return retbuf;
}

void crypto::addFile(string filename, string content, string password) {
    vector<BYTE> enc_key = generateKey(password);
    vector<BYTE> mac_key = generateKey2(password);

    auto [encrypted_contents, iv_str, num_blocks] = EncryptFile(content, enc_key);
    string mac_content = to_string(content.length()) + iv_str + encrypted_contents;
    string hmac = getHMAC(mac_content, mac_key);

    ofstream myfile;
    myfile.open(filename);
    myfile << content.length() << endl;
    myfile << hex << hmac << endl;
    myfile << hex << iv_str << endl;
    myfile << std::hex << encrypted_contents;
    myfile.close();
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
