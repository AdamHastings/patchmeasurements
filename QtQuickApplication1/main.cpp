#include <QGuiApplication>
//#include <QQmlApplicationEngine>
//
//int main(int argc, char *argv[])
//{
//#if defined(Q_OS_WIN)
//    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
//#endif
//
//    QGuiApplication app(argc, argv);
//
//    QQmlApplicationEngine engine;
//    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
//    if (engine.rootObjects().isEmpty())
//        return -1;
//
//    return app.exec();
//}

#include <Windows.h>
#include <iostream>
#include <fstream>




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

    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return msg.wParam;
}

