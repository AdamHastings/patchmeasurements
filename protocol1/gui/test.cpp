#ifdef _WIN32
    #include <windows.h>
    #pragma comment(lib, "user32.lib")
#endif
#include <iostream>
 
using namespace std;
 
HHOOK mouseHook;
 
LRESULT __stdcall MouseHookCallback(int nCode, WPARAM wParam, LPARAM lParam)
{
    cout << "in callback" << endl;
    if (nCode >= 0)
    {
        switch(wParam)
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
    SetHook();
    MSG msg;
 
    cout << "setup" << endl;

    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return msg.wParam;
}