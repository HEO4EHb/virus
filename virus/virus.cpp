#include <iostream>
#include <Windows.h>
 
using namespace std;
 
int main()
{
    LPCWSTR window_title = L"Untitled - Paint";
    HWND hWND = FindWindow(NULL, window_title);
    /*
    while (hWND == NULL) 
    {
        hWND = FindWindow(NULL, window_title);
        cout << "Start Paint!" << endl;
        Sleep(100);
    }*/
    while (true) {
        Sleep(50);
        if (GetAsyncKeyState(VK_NUMPAD0)) { // Exit
            return 0;
        }
        if (1) {//Mouseposition
            POINT p;
            GetCursorPos(&p);
            ScreenToClient(hWND, &p);
            cout << "x-position: " << p.x << " | y-position: " << p.y << endl;
            Sleep(1000);
        }
        if (1) { // leftclick
            INPUT iNPUT = { 0 };
            iNPUT.type = INPUT_MOUSE;
            iNPUT.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
            SendInput(1, &iNPUT, sizeof(iNPUT));
            ZeroMemory(&iNPUT, sizeof(iNPUT));
            iNPUT.type = INPUT_MOUSE;
            iNPUT.mi.dwFlags = MOUSEEVENTF_LEFTUP;
            SendInput(1, &iNPUT, sizeof(iNPUT));
        }
        if (1) { //write a
            INPUT Input = { 0 };
            Input.type = INPUT_KEYBOARD;
            Input.ki.wVk = VkKeyScanA('a');
            SendInput(1, &Input, sizeof(Input));
            ZeroMemory(&Input, sizeof(Input));
            Input.ki.dwFlags = KEYEVENTF_KEYUP;
            SendInput(1, &Input, sizeof(Input));
 
        }
        if (GetAsyncKeyState(VK_NUMPAD4)) { // Set mouse position using SendInput
            int x = 100;
            int y = 100;
 
            // Get total screen coordinates
            int screen_x = GetSystemMetrics(SM_CXSCREEN);
            int screen_y = GetSystemMetrics(SM_CYSCREEN);
 
            WINDOWPLACEMENT wp;
            GetWindowPlacement(hWND, &wp);
 
            long xConverted = (65535 * (x + wp.rcNormalPosition.left)) / screen_x;
            long yConverted = (65535 * (y + wp.rcNormalPosition.top)) / screen_y;
 
            INPUT iNPUT = { 0 };
            iNPUT.type = INPUT_MOUSE;
            iNPUT.mi.dwFlags = (MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE);
            iNPUT.mi.dx = xConverted;
            iNPUT.mi.dy = yConverted;
            SendInput(1, &iNPUT, sizeof(iNPUT));
 
        }
    }
}