#ifndef __MAIN_H__
#define __MAIN_H__

#include <windows.h>

/*  To use this exported function of dll, include this header
 *  in your project.
 */

#ifdef BUILD_DLL
    #define DLL_EXPORT __declspec(dllexport)
#else
    #define DLL_EXPORT __declspec(dllimport)
#endif


#ifdef __cplusplus
extern "C"
{
#endif

#include "list.h"

int DLL_EXPORT check_foo(list_t * list);

void DLL_EXPORT reaction(int check);

#ifdef __cplusplus
}
#endif

#endif // __MAIN_H__
