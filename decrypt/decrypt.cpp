// decrypt.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <tuple>
#include <vector>
#include "sha256.h"
#include "aes.h"
#include "typedefs.h"
using namespace std;



tuple<string, string, string, string> parse_input(string filename) {
    string length;
    string iv;
    string hmac;
    //string contents;

    ifstream myfile;
    myfile.open("results.txt", ios::in);
    getline(myfile, length);
    //cout << "Length: " <<  length << endl;
    getline(myfile, hmac);
    //cout << "MAC: " << hmac << endl;
    getline(myfile, iv);
    //cout << "IV: " << iv << endl;

    string contents((std::istreambuf_iterator<char>(myfile)), std::istreambuf_iterator<char>());

    //cout << "Contents: " << contents << endl;

    return { length, iv, hmac, contents };
}

string getHMAC(string contents, vector<BYTE> key) {



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

vector<BYTE> generateKey(string password) {
    SHA256_CTX ctx;
    BYTE buf[32];

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

vector<BYTE> generateKey2(string password) {
    SHA256_CTX ctx;
    BYTE buf[32];

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

string decrypt(int length, string iv, string content, vector<BYTE> key) {
        //string retbuf = "";
        //string enc_contents = "";
        //string iv_str = "";
        //string num_blocks_str = "";

        BYTE bytekey[32];
        unsigned int key_schedule[60];
        for (size_t i = 0; i < 32; i++) {
            bytekey[i] = key[i];
        }

        aes_key_setup(bytekey, key_schedule, 256);


        int num_blocks = (length / AES_BLOCK_SIZE) + 1;

        vector<BYTE> contents_vec;
        istringstream hex_chars_stream(content);
        BYTE c;
        int i = 0;
        /*while (hex_chars_stream >> hex >> c) {
            contents_vec.push_back(c);
            i++;
        }*/
        int offset = 0;
        stringstream ss;
        unsigned int buffer;
        while (offset < content.length()) {
            ss.clear();
            ss << hex << content.substr(offset, 2);
            ss >> buffer;
            contents_vec.push_back(static_cast<BYTE>(buffer));
            i++;
            offset += 2;
        }
        //cout << i << endl;
        cout << contents_vec.size() << endl;

        BYTE block_output[AES_BLOCK_SIZE];
        BYTE plaintext_block[AES_BLOCK_SIZE];
        BYTE block_input[AES_BLOCK_SIZE];
        BYTE iv_block[AES_BLOCK_SIZE];

        cout << "Getting IV: " << endl;

        offset = 0;
        i = 0;
        while (offset < iv.length()) {
            ss.clear();
            ss << hex << iv.substr(offset, 2);
            ss >> buffer;
            iv_block[i] = static_cast<BYTE>(buffer);
            cout << iv_block[i];
            offset += 2;
            i += 1;
        }

        cout << endl << "assigning block input" << endl;

        for (int j = 0; j < AES_BLOCK_SIZE; j++) {
            block_input[j] = contents_vec[j];
        }

        cout << "Decrypting" << endl;

        aes_decrypt(block_input, block_output, key_schedule, 256);


        string output = "";
        for (int j = 0; j < AES_BLOCK_SIZE; j++) {
            //cout << (BYTE)block_output[j];
            output += (BYTE) (block_output[j] ^ iv_block[j]);
        }


        for (int i = 1; i < num_blocks; i++) {
            for (int j = 0; j < AES_BLOCK_SIZE; j++) {
                block_input[j] = contents_vec[(i*AES_BLOCK_SIZE) + j];
            }

            aes_decrypt(block_input, block_output, key_schedule, 256);

            for (int j = 0; j < AES_BLOCK_SIZE; j++) {
                output += (BYTE)(block_output[j] ^ contents_vec[((i-1) * AES_BLOCK_SIZE) + j]);
            }
        }

        return output;
}

int main()
{

    vector<BYTE> enc_key = generateKey("q49b0LfAlwP994jbqQf");
    vector<BYTE> mac_key = generateKey2("q49b0LfAlwP994jbqQf");

    cout << "Parsing input" << endl;
    auto [length, iv, hmac, encrypted_contents ] = parse_input("results.txt");
    string mac_content = length + iv + encrypted_contents;

    /*ofstream copy;
    copy.open("copy.txt");

    for (BYTE b : mac_key) {
        copy << hex << setw(2) << setfill('0') << (int)b;
    }
    copy << endl;
    copy << length << endl;
    copy << hmac << endl;
    copy << iv << endl;
    copy << encrypted_contents;
    copy.close();*/

    string recomputed_hmac = getHMAC(mac_content, mac_key);
    cout << "Recomputed MAC: " << recomputed_hmac << endl;

    if (hmac != recomputed_hmac) {
        cout << "ERROR! MACs don't match" << endl;
        //return 1;
    }
    else {
        cout << "MACs match" << endl;;
    }

    string output = decrypt(stoi(length), iv, encrypted_contents, enc_key);
    ofstream decrypted;
    decrypted.open("decrypted.txt");
    decrypted << output;
    decrypted.close();


    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

