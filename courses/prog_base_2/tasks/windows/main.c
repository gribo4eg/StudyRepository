#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <commctrl.h>

int WINAPI WinMain(
                   HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine,
                   int nCmdShow
                   )
{
    const char * WindowClass = "My Window Class";
    WNDCLASSEX wc;
    HWND hwnd;
    MSG Msg;

    //1:WINDOW CLASS
    wc.cbSize           = sizeof(WNDCLASSEX);
    wc.style            = NULL;
    wc.lpfnWndProc      = WNDPROC;
    wc.cbClsExtra       = NULL;
    wc.cbWndExtra       = NULL;
    wc.hInstance        = hInstance;
    wc.hIcon            = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor          = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground    = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszMenuName     = NULL;
    wc.lpszClassName    = WindowClass;
    wc.hIconSm          = LoadIcon(NULL, IDI_APPLICATION);

    if(!RegisterClassEx(&wc))
    {
        MessageBox(NULL, "Window Registration Failed!", "ERROR!",
                   MB_ICONEXCLAMATION | MB_OK);
                   return 0;
    }

    //2: CREATE WINDOW
    hwnd = CreateWindowEx(
                          WS_EX_CLIENTEDGE,
                          WindowClass,
                          "My Window Name",
                          WS_OVERLAPPEDWINDOW,
                          CW_USEDEFAULT,
                          CW_USEDEFAULT,
                          300, 300,
                          NULL, NULL, hInstance, NULL
                          );

    if(hwnd == NULL)
    {
        MessageBox(NULL, "Window Creation Failed!", "ERROR!",
                   MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

}
