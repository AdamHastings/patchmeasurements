#include <string>
#include <stdio.h>
#include <tchar.h>
#include <windows.h>
#include <iostream>
#include <filesystem>



#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS



int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, char*, int nShowCmd) {

    std::filesystem::current_path("C:/Program Files/HastingsExperiment"); //setting path


    /*std::wstring cmd_line = L".\Experiment.exe";
    std::wstring open = L"open";
    std::cout << ShellExecute(NULL, open.c_str(), cmd_line.c_str(), NULL, NULL, SW_SHOW);*/


    std::string cmd_line = "Experiment.exe";

    // additional information
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    // set the size of the structures
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));


    TCHAR tszCmdLine[1024] = { 0 };
    mbstowcs(tszCmdLine, cmd_line.c_str(), 1024);
    _tprintf(tszCmdLine);

    //LPCWSTR commandline = "C:\Program Files\My Company\doit.exe";


    //// start the program up
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

    // Wait until child process exits.
   //  WaitForSingleObject(pi.hProcess, INFINITE);

    // Close process and thread handles. 
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
	return 0;
}