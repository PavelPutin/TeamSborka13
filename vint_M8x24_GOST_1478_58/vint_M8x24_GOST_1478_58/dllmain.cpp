#include "pch.h"
#include "vint_M8x24_GOST_1478_58.h"

BOOL APIENTRY DllMain(HMODULE hModule,
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

void vint_M8x24_GOST_1478_58(double orig_x, double orig_y, double orig_z) {
    tag_t cyl = NULL_TAG;
    drawCyl(create, orig_x, orig_y, orig_z + 4, "24", "8", 0, 0, 1, &cyl);

    drawCyl(create, orig_x, orig_y, orig_z, "4", "13", 0, 0, 1, &cyl);

    tag_t sub = NULL_TAG;
    drawBlock(subtract, orig_x - 0.5, orig_y - 15, orig_z, "1", "26", "1", &sub);

    
}

void ufusr(char* param, int* retcode, int paramLen) {
    UF_initialize();

    vint_M8x24_GOST_1478_58(0, 0, 0);

    UF_terminate();
}