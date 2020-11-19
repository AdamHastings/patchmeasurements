extern "C" {
    #include "aes.h"
    #include "sha256.h"
}

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
//#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>
using namespace std;
using std::cin;
using std::cout;

bool checkIfFile (string name) {
    if (FILE *file = fopen(name.c_str(), "r")) {
        fclose(file);
        return true;
    } else {
        return false;
    }
}

bool checkIfDir(string foldername) {
    struct stat info;

    const char* pathname = foldername.c_str();

    if( stat( pathname, &info ) != 0 ) {
        return false;
        //printf( "No file or directory named %s\n", pathname );
    } else if( info.st_mode & S_IFDIR ) {
        return true;
        //printf( "%s is a directory.\n", pathname );
    }
    else {
        return false;
        //printf( "%s is not a directory.\n", pathname );
    }
}

bool checkExtension(string filename) {
    const size_t last_slash_idx = filename.find_last_of("\\/");
    if (std::string::npos != last_slash_idx)
    {
        return false;
    }

    if (filename.compare("filenames.txt") == 0) {   
        return false;
    }

    std::string::size_type idx;
    idx = filename.rfind('.');

    if(idx != std::string::npos) {
        std::string extension = filename.substr(idx+1);
        if (extension.compare("hmac") == 0) {
            return false;
        }
    }
    else {
        return true;
    }
    return true;
}

class Cstore {
    public:
        // Constructor initializes folder archives
        Cstore () {

 /*           archives = "archives";
            const char* pathname = archives.c_str();

            if (!checkIfDir(archives)) {
                if (mkdir(pathname, 0777) != 0) {
                    printf("Error creating folder %s\n", pathname);
                    exit(0);
                }
            }*/
        }

        // void get_options(int argc, char** argv);

        bool checkIntegrity(string archivename, vector<BYTE> key);

        void redoHMAC(string archivename, vector<BYTE> key);

        void listArchive(string archivename);

        void addFile(string archivename, string password, string filename);

        void extractFile(string archivename, string password, string filename);

        void deleteFile(string archivename, string password, string filename);

        void encryptFile(string archivename, vector<BYTE> key, string filename, string content);
        
        vector<char> decryptFile(vector<BYTE> key, vector<string> content);

        vector<string> getFileContents(string filepath);
        vector<string> getEncryptContents(string filepath);

        vector<BYTE> hmac(vector<BYTE> key, string message);

        vector<BYTE> generateKey(string password);
        vector<BYTE> generateKey2(string password);

    private:
        string archives;
};

// ----------------------------------
//           MAIN DRIVER
// ----------------------------------
//int main (int argc, char** argv) {
//    
//    // Strings
//    ios_base::sync_with_stdio(false);
//
//    // Initializing a cstore class
//    Cstore cstore;
//
//    // Checking for arguments
//    // cstore.get_options(argc, argv);
//
//    // Exiting the program
//    return 0;
//}

// Check integrity of archive
bool Cstore::checkIntegrity(string archivename, vector<BYTE> key) {
    string archivedir = archives + "/" + archivename;
    if (!checkIfDir(archivedir)) {
        printf("Archive %s doesn't exist.\n", archivename.c_str());
        return false;
    }

    string filenames = "archives/" + archivename + "/filenames.txt";

    vector<string> filenamesText = getFileContents(filenames);

    string finalMessage = "";
    // Check HMAC of each file
    for (size_t i = 0; i < filenamesText.size(); i++) {
        string eachFile = "archives/" + archivename + "/" + filenamesText[i];
        if (!checkIfFile(eachFile)) {
            cout << "File in archive doesn't exist\n";
            return false;
        }
        vector<string> fileContents = getEncryptContents(eachFile);
        string all = filenamesText[i];
        for (size_t j = 0; j < fileContents.size(); j++) {
            all += fileContents[j];
        }

        // final hmac
        finalMessage += all;
        vector<BYTE> hmacBytes = hmac(key, all);

        string rawname = filenamesText[i].substr(0, filenamesText[i].find_last_of(".")) + ".hmac";
        string hmacPath = "archives/" + archivename + "/" + rawname;

        if (!checkIfFile(hmacPath)) {
            cout << "Hmac file doesn't exist\n";
            return false;
        }
        // get hmac contents
        std::ifstream input(hmacPath, std::ios::binary);

        std::vector<char> bytes(
            (std::istreambuf_iterator<char>(input)),
            (std::istreambuf_iterator<char>()));

        input.close();

        if (hmacBytes.size() != bytes.size()) {
            cout << "Hmac file bytes size don't match\n";
            return false;
        }

        for (size_t k = 0; k < bytes.size(); k++) {
            BYTE filebytes = static_cast<unsigned char>(bytes[k]);
            if (hmacBytes[k] != filebytes) {
                cout << "Hmac file bytes don't match\n";
                return false;
            }
            finalMessage += hmacBytes[k]; // for final hmac
        }
    }

    vector<BYTE> hmacBytes = hmac(key, finalMessage);
    string hmacPath = "archives/" + archivename + "/archive.hmac";

    if (!checkIfFile(hmacPath)) {
        cout << "Hmac file for archive doesn't exist\n";
        return false;
    }

    // get hmac contents
    std::ifstream input(hmacPath, std::ios::binary);

    std::vector<char> bytes(
        (std::istreambuf_iterator<char>(input)),
        (std::istreambuf_iterator<char>()));

    input.close();

    if (hmacBytes.size() != bytes.size()) {
        cout << "Hmac file bytes don't match\n";
        return false;
    }

    for (size_t k = 0; k < bytes.size(); k++) {
        BYTE filebytes = static_cast<unsigned char>(bytes[k]);
        if (hmacBytes[k] != filebytes) {
            cout << "Hmac file bytes don't match\n";
            return false;
        }
    }

    // for each text file, check if the hmac of file matches corresponding hmac file
    // keep a count of text files
    // make sure theres an hmac file for archive
    // if there are more files or no matching hmac, reject
    // this is where we verify password too i guess
    return true;
}

void Cstore::redoHMAC(string archivename, vector<BYTE> key) {
    string archivedir = archives + "/" + archivename;
    if (!checkIfDir(archivedir)) {
        printf("Archive %s doesn't exist.\n", archivename.c_str());
        exit(0);
    }

    string filenames = "archives/" + archivename + "/filenames.txt";

    vector<string> filenamesText = getFileContents(filenames);

    string finalMessage = "";
    // Check HMAC of each file
    for (size_t i = 0; i < filenamesText.size(); i++) {
        string eachFile = "archives/" + archivename + "/" + filenamesText[i];
        if (!checkIfFile(eachFile)) {
            cout << "File in archive doesn't exist\n";
            exit(0);
        }
        vector<string> fileContents = getEncryptContents(eachFile);
        string all = filenamesText[i];
        for (size_t j = 0; j < fileContents.size(); j++) {
            all += fileContents[j];
        }

        // final hmac
        finalMessage += all;

        vector<BYTE> hmacBytes = hmac(key, all);

        string rawname = filenamesText[i].substr(0, filenamesText[i].find_last_of(".")) + ".hmac";
        string hmacPath = "archives/" + archivename + "/" + rawname;

        vector<char> writeToFile;
        for (size_t k = 0; k < hmacBytes.size(); k++) {
            finalMessage += hmacBytes[k]; // for final hmac
            writeToFile.push_back((char) hmacBytes[k]);
        }

        ofstream outfile(hmacPath, ios::out | ios::binary);
        outfile.write(&writeToFile[0], writeToFile.size());
        outfile.close();
    }

    vector<BYTE> hmacBytes = hmac(key, finalMessage);
    string hmacPath = "archives/" + archivename + "/archive.hmac";

    // get hmac contents
    vector<char> writeToFile;
    for (size_t k = 0; k < hmacBytes.size(); k++) {
        writeToFile.push_back((char) hmacBytes[k]);
    }

    ofstream outfile(hmacPath, ios::out | ios::binary);
    outfile.write(&writeToFile[0], writeToFile.size());
    outfile.close();
}

vector<BYTE> Cstore::generateKey(string password) {
    SHA256_CTX ctx;
    BYTE buf[SHA256_BLOCK_SIZE];
    
    const unsigned char* byte = reinterpret_cast<const unsigned char *>(password.c_str());


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

vector<BYTE> Cstore::generateKey2(string password) {
    SHA256_CTX ctx;
    BYTE buf[SHA256_BLOCK_SIZE];
    
    const unsigned char* byte = reinterpret_cast<const unsigned char *>(password.c_str());


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

void Cstore::listArchive(string archivename) {
    string archivedir = archives + "/" + archivename;
    if (checkIfDir(archivedir)) {
        printf("Files in archive %s:\n", archivename.c_str());

        string filenames = "archives/" + archivename + "/filenames.txt";

        vector<string> filenamesText = getFileContents(filenames);

        for (size_t i = 0; i < filenamesText.size(); i++) {
            cout << filenamesText[i] << endl;
        }
    } else {
        printf("Archive %s doesn't exist.\n", archivename.c_str());
        exit(0);
    }
}

void Cstore::encryptFile(string archivename, vector<BYTE> key, string filename, string content) {
    string writeToFile = "archives/" + archivename + "/" + filename;
    if (checkIfFile(writeToFile)) {
        cout << "File already exists\n";
        exit(0);
    }

    string filenames = "archives/" + archivename + "/filenames.txt";

    std::ofstream file {filenames, std::ios_base::app};

    vector<string> filenamesText = getFileContents(filenames);

    for (size_t i = 0; i < filenamesText.size(); i++) {
        if (filename.compare(filenamesText[i]) == 0) {
            cout << "File already exists in archive\n";
            exit(0);
        }
    }

    BYTE bytekey[32];
    WORD key_schedule[60];
    for (size_t i = 0; i < 32; i++) {
        bytekey[i] = key[i];
    }

    aes_key_setup(bytekey, key_schedule, 256);

    // get 16 random bytes for IV
    BYTE iv[16];

    size_t size = sizeof(iv); //Declare size of data
    ifstream urandom("/dev/urandom", ios::in|ios::binary); //Open stream
    if(urandom) //Check if stream is open
    {
        urandom.read(reinterpret_cast<char*>(&iv), size); //Read from urandom
        if(!urandom) {
            cout << "Failed to read from urandom\n";
            exit(0);
        }
        urandom.close(); //close stream
    }
    else {
        cout << "Faild to open urandom\n";
        exit(0);
    }

    BYTE toXor[16];
    ofstream myfile (writeToFile, std::ios_base::app);
    if (myfile.is_open()) {
        for (size_t i = 0; i < 16; i++) {
            myfile << iv[i];
            toXor[i] = iv[i];
        }
        myfile << "\n";
        myfile.close();
    }

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
        ofstream myfile (writeToFile, std::ios_base::app);
        if (myfile.is_open()) {
            for (size_t m = 0; m < 16; m++) {
                myfile << out[m];
                toXor[m] = out[m];
            }
            myfile << "\n";
            myfile.close();
        }
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
        ofstream myfile (writeToFile, std::ios_base::app);
        if (myfile.is_open()) {
            for (size_t i = 0; i < 16; i++) {
                myfile << out[i];
                toXor[i] = out[i];
            }
            myfile << "\n";
            myfile.close();
        }
    }
}

vector<char> Cstore::decryptFile(vector<BYTE> key, vector<string> content) {
    BYTE bytekey[32];
    WORD key_schedule[60];
    for (size_t i = 0; i < 32; i++) {
        bytekey[i] = key[i];
    }
    
    aes_key_setup(bytekey, key_schedule, 256);

    vector<char> plaintext;

    for (size_t i = content.size() - 1; i > 0; i--) {
        BYTE lastcipher[16];
        BYTE previous[16];
        
        for (size_t j = 0; j < content[i].length(); j++) {
           lastcipher[j] = static_cast<unsigned char>(content[i][j]);
           previous[j] = static_cast<unsigned char>(content[i - 1][j]);
        }

        BYTE out[16];
        aes_decrypt(lastcipher, out, key_schedule, 256);
        vector<char> result;
        if (i == content.size() - 1) {

            BYTE plain[16];
            for (size_t k = 0; k < 16; k++) {
                plain[k] = out[k] ^ previous[k];
            }
            int num_pad = plain[15];

            for (size_t k = 0; k < size_t(16 - num_pad); k++) {
                char letter = plain[k];
                result.push_back(letter);
            }
        } else {
            BYTE plain[16];
            for (size_t k = 0; k < 16; k++) {
                plain[k] = out[k] ^ previous[k];
            }
            for (size_t k = 0; k < 16; k++) {
                char letter = plain[k];
                result.push_back(letter);
            }
        }
        if (result.size() != 0) {
            for (size_t l = result.size(); l > 0; l--) {
                plaintext.push_back(result[l - 1]);
            }
        }
    }

    vector<char> contents;
    for (size_t l = plaintext.size(); l > 0; l--) {
        cout << plaintext[l - 1];
        contents.push_back(plaintext[l - 1]);
    }

    return contents;
}

vector<string> Cstore::getFileContents(string filepath) {
    ifstream fin;
    fin.open(filepath, ios::in);

    char my_character = 'a';

    vector<string> filenames;

    string filename = "";
    while (!fin.eof() ) {
        fin.get(my_character);
        if (my_character != '\n'){
            filename += my_character;
        } else {
            if (filename != "") {
                filenames.push_back(filename);
                filename = "";
            }
        }
    }

    fin.close();

    return filenames;
}

vector<string> Cstore::getEncryptContents(string filepath) {
    ifstream fin;
    fin.open(filepath, ios::in);

    char my_character;

    vector<string> filenames;

    string filename = "";
    int j = 0;
    while (!fin.eof() ) {
        fin.get(my_character);
        if (j == 16) {
            if (filename != "") {
                filenames.push_back(filename);
                filename = "";
            }
            j = 0;
        } else {
            filename += my_character;
            j++;
        }
    }

    fin.close();

    return filenames;
}

void Cstore::extractFile(string archivename, string password, string filename) {
    if (!checkExtension(filename)) {
        cout << "Invalid type." << endl;
        exit(0);
    }

    string archivedir = archives + "/" + archivename;
    if (!checkIfDir(archivedir)) {
        printf("Archive %s doesn't exist.\n", archivename.c_str());
        exit(0);
    }

    vector<BYTE> key = generateKey(password);
    if (!checkIntegrity(archivename, generateKey2(password))) {
        exit(0);
    }

    string filenames = "archives/" + archivename + "/filenames.txt";
    vector<string> filenamesText = getFileContents(filenames);
    if (find(filenamesText.begin(), filenamesText.end(), filename) == filenamesText.end()) {
        cout << "File is not in archive.\n";
        exit(0);
    }

    string eachFile = "archives/" + archivename + "/" + filename;
    if (!checkIfFile(eachFile)) {
        cout << "File in archive doesn't exist.\n";
        exit(0);
    }

    vector<string> content = getEncryptContents(eachFile);

    vector<char> decrypted = decryptFile(key, content);
    
    string archives1 = "extracted-files";
    const char* pathname = archives1.c_str();

    //if (!checkIfDir(archives1)) {
    //    if (mkdir(pathname, 0777) != 0) {
    //        printf("Error creating folder %s\n", pathname);
    //        exit(0);
    //    }
    //}

    string filePath = archives1 + "/" + filename;
    ofstream outfile(filePath, ios::out | ios::binary);
    outfile.write(&decrypted[0], decrypted.size());
    outfile.close();

}

void Cstore::deleteFile(string archivename, string password, string filename) {
    if (!checkExtension(filename)) {
        cout << "Invalid type." << endl;
        exit(0);
    }

    string archivedir = archives + "/" + archivename;
    if (!checkIfDir(archivedir)) {
        printf("Archive %s doesn't exist.\n", archivename.c_str());
        exit(0);
    }

    vector<BYTE> key = generateKey(password);
    if (!checkIntegrity(archivename, generateKey2(password))) {
        cout << "Integrity bad." << endl;
        exit(0);
    }

    string filenames = "archives/" + archivename + "/filenames.txt";
    vector<string> filenamesText = getFileContents(filenames);
    if (find(filenamesText.begin(), filenamesText.end(), filename) == filenamesText.end()) {
        cout << "File is not in archive.\n";
        exit(0);
    }

    string eachFile = "archives/" + archivename + "/" + filename;
    if (!checkIfFile(eachFile)) {
        cout << "File in archive doesn't exist.\n";
        exit(0);
    }

    string rawname = filename.substr(0, filename.find_last_of(".")) + ".hmac";
    string hmacPath = "archives/" + archivename + "/" + rawname;

    ofstream myfile (filenames);
    if (myfile.is_open()) {
        for (size_t i = 0; i < filenamesText.size(); i++) {
            if (filenamesText[i].compare(filename) != 0) {
                myfile << filenamesText[i] << "\n";
            }
        }
        myfile.close();
    }


    if( remove(eachFile.c_str()) != 0 )
        printf( "Error deleting file\n" );
    else
        printf( "File successfully deleted\n" );
    
    if( remove(hmacPath.c_str()) != 0 )
        printf( "Error deleting hmac\n" );
    else
        printf( "Hmac successfully deleted\n" );

    redoHMAC(archivename, generateKey2(password));
}

void Cstore::addFile(string archivename, string password, string filename) {
    if (!checkExtension(filename)) {
        cout << "Invalid type." << endl;
        exit(0);
    }

    // open file, read it, encrypt it
    string content;
    std::ifstream infile (filename);
    if (!infile) {
        cout << "Invalid Filename" << endl;
        exit(0);
    } else {
        content.assign(std::istreambuf_iterator<char>(infile), std::istreambuf_iterator<char>());
    }
    infile.close();
    
    string archives1 = "archives/" + archivename;
    const char* pathname = archives1.c_str();

    bool justCreated = false;
    //if (!checkIfDir(archives1)) {
    //    justCreated = true;
    //    if (mkdir(pathname, 0777) != 0) {
    //        printf("Error creating folder %s\n", pathname);
    //        exit(0);
    //    }
    //}

    vector<BYTE> key = generateKey(password);

    // Check integrity
    //if (!justCreated) {
        if (!checkIntegrity(archivename, generateKey2(password))) {
            exit(0);
        }
    //}

    string filenames = "archives/" + archivename + "/filenames.txt";
    std::ofstream file {filenames, std::ios_base::app};

    encryptFile(archivename, key, filename, content);

    ofstream myfile (filenames, std::ios_base::app);
    if (myfile.is_open()) {
        myfile << filename << "\n";
        myfile.close();
    }
    cout << filename << " encrypted.\n";

    // redo hmac
    redoHMAC(archivename, generateKey2(password));
}

vector<BYTE> Cstore::hmac(vector<BYTE> key, string message) {
    if (key.size() != 32) {
        cout << "Error creating key\n";
        exit(0);
    }

    string inner;
    string outer;
    for (size_t i = 0; i < 32; i++) {
        char xori = (char) (key[i] ^ '\x36');
        inner += xori;
        char xoro = (char) (key[i] ^ '\x5C');
        outer += xoro;
    }
    inner += message;

    SHA256_CTX ctx;
    BYTE buf[SHA256_BLOCK_SIZE];
    
    const unsigned char* byte = reinterpret_cast<const unsigned char *>(inner.c_str());

    sha256_init(&ctx);
    sha256_update(&ctx, byte, inner.size());
    sha256_final(&ctx, buf);

    for (char c : buf) {
        outer += c;
    }

    SHA256_CTX ctx2;
    BYTE buf2[SHA256_BLOCK_SIZE];
    
    const unsigned char* byte2 = reinterpret_cast<const unsigned char *>(outer.c_str());

    sha256_init(&ctx2);
    sha256_update(&ctx2, byte2, outer.size());
    sha256_final(&ctx2, buf2);

    vector<BYTE> bytes;
    for (char c : buf2) {
        bytes.push_back(c);
    }

    return bytes;
}


//// Read and process command line options
//void Cstore::get_options(int argc, char** argv) {
//    if (argc < 3) {
//        return;
//    }
//    string command = argv[1];
//    if (command.compare("list") == 0) {
//        if (argc != 3) {
//            return;
//        }
//        string archivename = argv[2];
//        listArchive(archivename);
//    }
//    else if (command.compare("add") == 0) {
//        if (argc < 4) {
//            return;
//        }
//        string hyphen = argv[2];
//        if (hyphen.compare("-p") == 0) {
//            if (argc < 6) {
//                return;
//            }
//            for (int i = 5; i < argc; i++) {
//                addFile(argv[4], argv[3], argv[i]);
//            }
//        } else {
//            char *charpass=getpass("Enter password: ");
//            string password(charpass);
//            for (int i = 3; i < argc; i++) {
//                addFile(argv[2], password, argv[i]);
//            }
//        }
//    }
//    else if (command.compare("extract") == 0) {
//        if (argc < 4) {
//            return;
//        }
//        string hyphen = argv[2];
//        if (hyphen.compare("-p") == 0) {
//            if (argc < 6) {
//                return;
//            }
//            for (int i = 5; i < argc; i++) {
//                extractFile(argv[4], argv[3], argv[i]);
//            }
//        } else {
//            char *charpass=getpass("Enter password: ");
//            string password(charpass);
//            for (int i = 3; i < argc; i++) {
//                extractFile(argv[2], password, argv[i]);
//            }
//        }
//    }
//    else if (command.compare("delete") == 0) {
//        if (argc < 4) {
//            return;
//        }
//        string hyphen = argv[2];
//        if (hyphen.compare("-p") == 0) {
//            if (argc < 6) {
//                return;
//            }
//            for (int i = 5; i < argc; i++) {
//                deleteFile(argv[4], argv[3], argv[i]);
//            }
//        } else {
//            char *charpass=getpass("Enter password: ");
//            string password(charpass);
//            for (int i = 3; i < argc; i++) {
//                deleteFile(argv[2], password, argv[i]);
//            }
//        }
//    }
//}