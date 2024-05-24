#include <uf.h>
#include <iostream>
#include <uf_curve.h>
#include <uf_sket.h>
#include <uf_modl.h>
#include <string>
#include <cstring>

#include "things/gaika_m20_gost_5915_70/gaika_m20_gost_5915_70.h"

void ufusr(char* param, int* retcode, int paramLen) {
    UF_initialize();

    double center[3] = { 0,0,0 };

    draw_gaika_m20_gost_5915_70(center[0], center[1], center[2]);

    UF_terminate();
}

int ufusr_ask_unload(void) {
    return (UF_UNLOAD_IMMEDIATELY);
}



