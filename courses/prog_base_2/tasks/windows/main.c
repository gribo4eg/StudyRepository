#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <commctrl.h>

#include "worker.h"

#define WORKERS_COUNT 5
#define TIMER_TICK 1000

enum {TIMER_CB = 333,
      LABLE_ID,
      BUTTON_EX,
      STATIC_INDEX_S,
      STATIC_NAME_S,
      STATIC_SURNAME_S,
      STATIC_EXP_S,
      STATIC_SALARY_S,
      STATIC_NAME,
      STATIC_SURNAME,
      STATIC_EXP,
      STATIC_SALARY
      };

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(
                   HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine,
                   int nCmdShow
                   )
{
    srand(time(NULL));
    const char * WindowClass = "Window Class";

    WNDCLASSEX wc;
    HWND hwnd;
    MSG msg;

    //1:WINDOW CLASS
    wc.cbSize           = sizeof(WNDCLASSEX);
    wc.style            = NULL;
    wc.lpfnWndProc      = WndProc;
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
                          "Workers Timer",
                          WS_OVERLAPPEDWINDOW,
                          CW_USEDEFAULT,
                          CW_USEDEFAULT,
                          350, 300,
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

    while(GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    HINSTANCE hInstance = GetModuleHandle(NULL);

    static HINSTANCE hInst;

    static HWND hButtonEx, hLable;
    static HWND hStaticIndS, hStaticNameS, hStaticSurnameS, hStaticExpS, hStaticSalarS;
    static HWND hStaticName, hStaticSurname, hStaticExp, hStaticSalar;

    static worker_t * worker[WORKERS_COUNT];

    static int index;
    static char buffer[10];
    static int tick;

    switch(msg)
    {
    case WM_CREATE:
        CreateWindowW(
                    L"button",
                    L"Timer",
                    WS_CHILD|WS_VISIBLE|BS_CHECKBOX|BS_AUTOCHECKBOX,
                    90, 150, 130, 23,
                    hwnd,
                    (HMENU)TIMER_CB,
                    NULL,
                    NULL);

        hButtonEx = CreateWindowEx(0,
                    WC_BUTTON,
                    "Exit",
                    WS_CHILD|WS_VISIBLE|WS_TABSTOP|BS_DEFPUSHBUTTON,
                    90, 190, 130, 23,
                    hwnd,
                    (HMENU)BUTTON_EX,
                    hInst,
                    NULL);

        hStaticIndS = CreateWindowEx(0,
                    WC_STATIC,
                    "Index:",
                    WS_CHILD|WS_VISIBLE,
                    10, 20, 130, 23,
                    hwnd,
                    (HMENU)STATIC_INDEX_S,
                    hInst,
                    NULL);

        hStaticNameS = CreateWindowEx(0,
                    WC_STATIC,
                    "Name:",
                    WS_CHILD|WS_VISIBLE,
                    10, 44, 130, 23,
                    hwnd,
                    (HMENU)STATIC_NAME_S,
                    hInst,
                    NULL);

        hStaticSurnameS = CreateWindowEx(0,
                    WC_STATIC,
                    "Surname:",
                    WS_CHILD|WS_VISIBLE,
                    10, 68, 130, 23,
                    hwnd,
                    (HMENU)STATIC_SURNAME_S,
                    hInst,
                    NULL);

        hStaticExpS = CreateWindowEx(0,
                    WC_STATIC,
                    "Experience:",
                    WS_CHILD|WS_VISIBLE,
                    10, 92, 130, 23,
                    hwnd,
                    (HMENU)STATIC_EXP_S,
                    hInst,
                    NULL);

        hStaticSalarS = CreateWindowEx(0,
                    WC_STATIC,
                    "Salary:",
                    WS_CHILD|WS_VISIBLE,
                    10, 116, 130, 23,
                    hwnd,
                    (HMENU)STATIC_SALARY_S,
                    hInst,
                    NULL);

        index = rand() % WORKERS_COUNT;

        worker[0] = worker_new(0, "George", "Horn", 6, 6000);
        worker[1] = worker_new(1, "Emily", "Wiggins", 2, 2000);
        worker[2] = worker_new(2, "Claude", "Jefferson", 3, 3000);
        worker[3] = worker_new(3, "Ursula", "Miller", 1, 1000);
        worker[4] = worker_new(4, "Damian", "Fields", 4, 4500);

        tick = worker_getIndex(worker[index]);

        hLable = CreateWindowEx(0,
                    "STATIC",
                    itoa(worker_getIndex(worker[index]), buffer, 10),
                    WS_CHILD|WS_VISIBLE,
                    150, 20, 130, 23,
                    hwnd,
                    (HMENU)LABLE_ID,
                    hInstance,
                    NULL);
        int ret = SetTimer(hwnd, TIMER_CB, TIMER_TICK, NULL);
        if(ret == 0)
            MessageBox(hwnd, "Could not set timer", "ERROR", MB_OK|MB_ICONEXCLAMATION);

        hStaticName = CreateWindowEx(0,
                    WC_STATIC,
                    worker_getName(worker[index]),
                    WS_CHILD|WS_VISIBLE,
                    150, 44, 130, 23,
                    hwnd,
                    (HMENU)STATIC_NAME,
                    hInst,
                    NULL);

        hStaticSurname = CreateWindowEx(0,
                    WC_STATIC,
                    worker_getSurname(worker[index]),
                    WS_CHILD|WS_VISIBLE,
                    150, 68, 130, 23,
                    hwnd,
                    (HMENU)STATIC_SURNAME,
                    hInst,
                    NULL);

        hStaticExp = CreateWindowEx(0,
                    WC_STATIC,
                    itoa(worker_getExp(worker[index]), buffer, 10),
                    WS_CHILD|WS_VISIBLE,
                    150, 92, 130, 23,
                    hwnd,
                    (HMENU)STATIC_EXP,
                    hInst,
                    NULL);

        hStaticSalar = CreateWindowEx(0,
                    WC_STATIC,
                    itoa(worker_getSalary(worker[index]), buffer, 10),
                    WS_CHILD|WS_VISIBLE,
                    150, 116, 130, 23,
                    hwnd,
                    (HMENU)STATIC_SALARY,
                    hInst,
                    NULL);

        break;
    case WM_TIMER:
        {
            int checked = IsDlgButtonChecked(hwnd, TIMER_CB);
            if(checked)
            {
                tick++;
                sprintf(buffer, "%i", tick);

                HWND hIndex = GetDlgItem(hwnd, LABLE_ID);
                SendMessage(hIndex, WM_SETTEXT, (WPARAM)256, (LPARAM)buffer);
            }
        }
        break;
    case WM_COMMAND:
        {
            switch(LOWORD(wParam))
            {
            case BUTTON_EX:
                {
                    for(int i = 0; i<WORKERS_COUNT; i++)
                    worker_free(worker[i]);

                    DestroyWindow(hwnd);
                    break;
                }
            }

            break;
        }
    case WM_CLOSE:

        for(int i = 0; i<WORKERS_COUNT; i++)
            worker_free(worker[i]);

        DestroyWindow(hwnd);
        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    default:
        return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}
