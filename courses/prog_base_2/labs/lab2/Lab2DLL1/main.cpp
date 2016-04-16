#include "main.h"

int check_foo(list_t * list)
{
    register int i;
    int sum = 0;

    for(i = 0; i<list_getSize(list); i++)
        sum+=list_getData(list, i);

    return sum/list_getSize(list);
}

void reaction(int check)
{
    if(check >= 0)
        puts("\nPositive\n");
    else
        puts("\nNegative\n");
}

extern "C" DLL_EXPORT BOOL APIENTRY DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    switch (fdwReason)
    {
        case DLL_PROCESS_ATTACH:
            // attach to process
            // return FALSE to fail DLL load
            break;

        case DLL_PROCESS_DETACH:
            // detach from process
            break;

        case DLL_THREAD_ATTACH:
            // attach to thread
            break;

        case DLL_THREAD_DETACH:
            // detach from thread
            break;
    }
    return TRUE; // successful
}
