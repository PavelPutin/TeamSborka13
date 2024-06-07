// dllmain.cpp : Определяет точку входа для приложения DLL.
#include "pch.h"
#include "krishka_3.h"
#include <Utils.h>
#include <iostream>
#include <vector>
#include <cmath>
#define _USE_MATH_DEFINES
#include <math.h>

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

struct Point {
    double x, y;
};

std::vector<Point> calculateRotatedPoints(double x, int numPoints) {
    std::vector<Point> points;
    double angle = 2 * M_PI / numPoints;

    for (int i = 0; i < numPoints; ++i) {
        double x_new = x * cos(i * angle);
        double y_new = x * sin(i * angle);
        points.push_back({ x_new, y_new });
    }

    return points;
}

void draw_krishka_3(double orig_x, double orig_y, double orig_z, double len, double width) {
    // len 20
    // width 90
    const char* len_s = doubleToConstChar(len);
    const char* len_00 = doubleToConstChar(len / 4);
    const char* width_s = doubleToConstChar(width);
    const char* width_o = doubleToConstChar(width / 3);
    const char* width_oo = doubleToConstChar(width / 3 * 2);

    tag_t krishka_3 = NULL_TAG;
    drawCyl(create, orig_x, orig_y, orig_z, len_s, width_s, 0, 1, 0, &krishka_3);

    tag_t krishka_3_1 = NULL_TAG;
    drawCyl(subtract, orig_x, orig_y, orig_z, len_s, width_o, 0, 1, 0, &krishka_3_1);

    tag_t krishka_3_5 = NULL_TAG;
    drawCyl(subtract, orig_x, orig_y + (len / 4  + ((len - (len / 4)) / 2) - 0.5), orig_z, doubleToConstChar(2), doubleToConstChar(width / 3 + 2), 0, 1, 0, &krishka_3_5);
    
    tag_t krishka_3_2 = NULL_TAG;
    drawCyl(subtract, orig_x, orig_y, orig_z, len_00, width_oo, 0, 1, 0, &krishka_3_2);

    auto points = calculateRotatedPoints(width / 2 - 8, 6);
    tag_t krishka_3_3 = NULL_TAG;
    tag_t krishka_3_4 = NULL_TAG;

    for (const auto& p : points) {
        drawCyl(subtract, orig_x + p.x, orig_y + len - 8, orig_z + p.y, doubleToConstChar(8), doubleToConstChar(14), 0, 1, 0, &krishka_3_3);
        drawCyl(subtract, orig_x + p.x, orig_y, orig_z + p.y, doubleToConstChar(orig_y + len - 8), doubleToConstChar(9), 0, 1, 0, &krishka_3_4);
    }
    
    delete[] len_s;
    delete[] width_s;
}