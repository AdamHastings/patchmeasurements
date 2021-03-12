#include <windows.h>
#include <string>
#include <stdio.h>
#include <tchar.h>


#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS

int main() {
    // additional information
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    // set the size of the structures
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    std::string cmd_line = "HastingsExperiment\\Protocol1App.exe";

    TCHAR tszCmdLine[1024] = { 0 };
    mbstowcs(tszCmdLine, cmd_line.c_str(), 1024);
    _tprintf(tszCmdLine);

    //LPCWSTR commandline = "C:\Program Files\My Company\doit.exe";


    // start the program up
    CreateProcess(NULL, // the path
        tszCmdLine,     // Command line
        NULL,           // Process handle not inheritable
        NULL,           // Thread handle not inheritable
        FALSE,          // Set handle inheritance to FALSE
        0,              // No creation flags
        NULL,           // Use parent's environment block
        NULL,           // Use parent's starting directory 
        &si,            // Pointer to STARTUPINFO structure
        &pi             // Pointer to PROCESS_INFORMATION structure (removed extra parentheses)
    );
    // Close process and thread handles. 
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
	return 0;
}