#pragma once
//extern "C" {

//}
#include <string>
#include <vector>
#include "typedefs.h"
#include "aes.h"
#include "sha256.h"
#include <QString>

using namespace std;

class crypto
{
public:
	static void addFile(string filename, string content, string password);
	static tuple<string, string, string>  EncryptFile(string content, vector<BYTE> key);
	static string getHMAC(string content, vector<BYTE> key);
	static bool checkIntegrity();
	static void DecryptFile(string filename, string password);

	static QString encodeWorkerID(QString WorkerID);

	static vector<BYTE> generateKey(string password);
	static vector<BYTE> generateKey2(string password);

};


