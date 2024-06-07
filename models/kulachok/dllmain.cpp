// dllmain.cpp : Определяет точку входа для приложения DLL.
#include "pch.h"
#include "kulachok.h"

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

void kulachok(double orig_x, double orig_y, double orig_z) {

    tag_t lines[9];
    UF_CURVE_line_t line_coords[8];

    double points[9][3] = {
        {orig_x, orig_y + 15, orig_z},
        {orig_x, orig_y + 15 + 4, orig_z},
        {orig_x - 4, orig_y + 15 + 4, orig_z},
        {orig_x - 4, orig_y + 15 + 4 + 50, orig_z},
        {orig_x - 4 - 22, orig_y + 15 + 4 + 50, orig_z},
        {orig_x - 4 - 22, orig_y + 15 + 4 + 50 - 4, orig_z},
        {orig_x - 4 - 22 + 18, orig_y + 15 + 4 + 50 - 4, orig_z},
        {orig_x - 4 - 22 + 18, orig_y + 15 + 4 + 50 - 4 - 50, orig_z},
        {orig_x - 4 - 22 + 18 + 8, orig_y + 15 + 4 + 50 - 4 - 50, orig_z},
    };

    for (int i = 0; i < 8; i++)
    {
        line_coords[i].start_point[0] = points[i][0];
        line_coords[i].start_point[1] = points[i][1];
        line_coords[i].start_point[2] = points[i][2];

        line_coords[i].end_point[0] = points[i + 1][0];
        line_coords[i].end_point[1] = points[i + 1][1];
        line_coords[i].end_point[2] = points[i + 1][2];
        UF_CURVE_create_line(&line_coords[i], &lines[i]);
    }

    tag_t sketch = NULL_TAG;
    char name[129] = "kulachok_sketch";
    UF_SKET_initialize_sketch(name, &sketch);

    double matrix[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 0 };
    tag_t object[2];
    int reference[2];
    UF_SKET_create_sketch(name, 2, matrix, object, reference, 2, &sketch);
    UF_SKET_add_objects(sketch, 9, lines);
    UF_SKET_terminate_sketch();

    uf_list_p_t revolved;
    UF_MODL_create_list(&revolved);
    UF_MODL_put_list_item(revolved, sketch);
    double revolve_point[3] = { orig_x, orig_y, orig_z };
    char revolve_start[27] = "0";
    char revolve_end[27] = "360";
    char* revolve_limit[2] = { revolve_start, revolve_end };
    double revolve_direction[3] = { -1, 0, 0 };
    uf_list_p_t revolve_feature_list;
    UF_MODL_create_revolved(revolved, revolve_limit, revolve_point, revolve_direction, UF_NULLSIGN, &revolve_feature_list);
    UF_MODL_delete_list(&revolved);
    UF_MODL_delete_list(&revolve_feature_list);
}

void ufusr(char* param, int* retcode, int paramLen) {
    UF_initialize();

    kulachok(0, 0, 0);

    UF_terminate();
}
