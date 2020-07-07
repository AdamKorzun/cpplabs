// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include <iostream>

/*
int _stdcall assignment2(int a[], int size) {
	int s = 0;
	int i = 0;
	s += a[i] * a[i];
	if (i > size) {
		cout << s;
		return s;
	}
	else if (size / 3 >= i) {
		return assignment2(a, size);
	}
	else if (size / 3 < i) {
		return assignment2(a, size);
	}
	i++;
	
	return assignment2(a,size);
}
*/
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}
