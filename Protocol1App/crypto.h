#pragma once
extern "C" {
    #include "aes.h"
    #include "sha256.h"
}
#include <string>
#include <vector>
using namespace std;

class crypto
{
public:
	static void addFile(string filename, string content, string password);
	static string EncryptFile(string content, vector<BYTE> key);
	static string getHMAC(string content, vector<BYTE> key);
	static bool checkIntegrity();
	static void DecryptFile(string filename, string password);

	static vector<BYTE> generateKey(string password);
	static vector<BYTE> generateKey2(string password);

};


