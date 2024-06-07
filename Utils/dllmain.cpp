// dllmain.cpp : Определяет точку входа для приложения DLL.
#include "pch.h"
#include "Utils.h"

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

const char* doubleToConstChar(double value) {
    std::stringstream ss;
    ss << value;
    char* result = new char[15];
    strncpy_s(result, 15, ss.str().c_str(), 15);
    return (const char*) result;
}