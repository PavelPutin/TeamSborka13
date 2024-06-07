// dllmain.cpp : Определяет точку входа для приложения DLL.
#include "pch.h"
#include <uf_defs.h>
#include <NXDrawUtils.h>

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

void drawPrismatiSponka(double x, double y, double z) {
    tag_t block = NULL_TAG;
    drawBlock(create, x - 4, y, z, "8", "20", "7", &block);

    for (int i = 0; i < 2; i++) {
        tag_t cyl = NULL_TAG;
        drawCyl(add, x, y + i * 20, z, "7", "8", 0, 0, 1, &cyl);
    }
}