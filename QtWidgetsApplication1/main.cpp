#include "QtWidgetsApplication1.h"
#include "MainWindow.h"
#include <QtWidgets/QApplication>
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <QApplication>

//#include "sendfile.h"

#define CURL_STATICLIB
#include <curl\curl.h>





using namespace std;

HHOOK mouseHook;
HHOOK keyboardHook;

vector<long long> lbuttondown_timestamps;
vector<long long> lbuttonup_timestamps;
vector<long long> mousemove_timestamps;
vector<long long> mousewheel_timestamps;
vector<long long> mousehwheel_timestamps;
vector<long long> rbuttondown_timestamps;
vector<long long> rbuttonup_timestamps;

vector<long long> keybd_timestamps;
FILETIME fileTime;

LRESULT __stdcall MouseHookCallback(int nCode, WPARAM wParam, LPARAM lParam) {
    if (nCode >= 0) {
        long long ll_now = (LONGLONG)fileTime.dwLowDateTime + ((LONGLONG)(fileTime.dwHighDateTime) << 32LL);
        GetSystemTimeAsFileTime(&fileTime);
        switch (wParam) {
            case WM_LBUTTONDOWN:
                lbuttondown_timestamps.push_back(ll_now);
                //cout << "Left Button Down " << ll_now <<  endl;
                //MainWindow::click_timestamps.push_back(ll_now);
                break;
            case WM_LBUTTONUP: 
                lbuttonup_timestamps.push_back(ll_now);
                break;
            case WM_MOUSEMOVE:
                mousemove_timestamps.push_back(ll_now);
                break;
            case WM_MOUSEWHEEL:
                mousewheel_timestamps.push_back(ll_now);
                break;
            case WM_MOUSEHWHEEL:
                mousehwheel_timestamps.push_back(ll_now);
                break;
            case WM_RBUTTONDOWN:
                rbuttondown_timestamps.push_back(ll_now);
                break;
            case WM_RBUTTONUP:
                rbuttonup_timestamps.push_back(ll_now);
                break;
        }
    }
    return CallNextHookEx(mouseHook, nCode, wParam, lParam);
}

LRESULT __stdcall KeyboardHookCallback(int nCode, WPARAM wParam, LPARAM lParam) {
    if (nCode >= 0) {
        switch (wParam) {
            case WM_KEYDOWN:
                GetSystemTimeAsFileTime(&fileTime);
                long long ll_now = (LONGLONG)fileTime.dwLowDateTime + ((LONGLONG)(fileTime.dwHighDateTime) << 32LL);
                keybd_timestamps.push_back(ll_now);
                cout << "Key Down " << ll_now << endl;
                break;

        }
    }
    return CallNextHookEx(mouseHook, nCode, wParam, lParam);
}

void SetHook() {
    if (!(mouseHook = SetWindowsHookEx(WH_MOUSE_LL, MouseHookCallback, NULL, 0))) {
        cout << "Failed to install mouse hook!" << endl;
    }
    if (!(keyboardHook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardHookCallback, NULL, 0))) {
        cout << "Failed to install keyboard hook!" << endl;
    }
}

void ReleaseHook() {
    UnhookWindowsHookEx(mouseHook);
    UnhookWindowsHookEx(keyboardHook);
}

void printResults(MainWindow mw) {

}


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

    std::ofstream file;
    file.open("cout.txt");
    std::streambuf* sbuf = std::cout.rdbuf();
    std::cout.rdbuf(file.rdbuf());

    /*CURL* curl;

    curl = curl_easy_init();
    curl_easy_cleanup(curl);

    return 0;*/


    SetHook();
    MSG msg;

    int argc = 0;
    char* argv[] = { NULL };

    QApplication a(argc, argv);
    MainWindow mw;
    mw.show();

    //while (GetMessage(&msg, NULL, 0, 0)) {
    //    TranslateMessage(&msg);
    //    DispatchMessage(&msg);
    //}

    return a.exec();
    
}