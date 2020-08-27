//int main(int argc, char* argv[])
//{
//    QApplication a(argc, argv);
//    QtWidgetsApplication1 w;
//    w.show();
//    return a.exec();
//}



#include "QtWidgetsApplication1.h"
#include <QtWidgets/QApplication>
#include <Windows.h>
#include <iostream>
#include <fstream>
//#include "MainWindow.h"
#include <QApplication>




using namespace std;

HHOOK mouseHook;

LRESULT __stdcall MouseHookCallback(int nCode, WPARAM wParam, LPARAM lParam)
{
    if (nCode >= 0)
    {
        switch (wParam)
        {
        case WM_LBUTTONDOWN:
            cout << "Left Button Down" << endl;
            break;

        case WM_LBUTTONUP:
            cout << "Left Button Up" << endl;
            break;
        }
    }
    return CallNextHookEx(mouseHook, nCode, wParam, lParam);
}

void SetHook()
{
    if (!(mouseHook = SetWindowsHookEx(WH_MOUSE_LL, MouseHookCallback, NULL, 0)))
    {
        cout << "Failed to install mouse hook!" << endl;
    }
}

void ReleaseHook()
{
    UnhookWindowsHookEx(mouseHook);
}


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

    std::ofstream file;
    file.open("cout.txt");
    std::streambuf* sbuf = std::cout.rdbuf();
    std::cout.rdbuf(file.rdbuf());


    SetHook();
    MSG msg;

 /*   QApplication app(argc, argv);
    MainWindow mw;
    mw.show();*/

    int argc = 0;
    char* argv[] = { NULL };

    QApplication a(argc, argv);
    QtWidgetsApplication1 w;
    w.show();

    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return a.exec();
    //return app.exec();
}