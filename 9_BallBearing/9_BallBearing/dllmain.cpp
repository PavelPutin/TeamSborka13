// dllmain.cpp : Определяет точку входа для приложения DLL.
#include "pch.h"
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

void drawBallBearing(double x, double y, double z) {
	double center = 16.75;
	double radius = 2.72;

	double p1[3] = { x + center, y + 5.5 + 2.72, z };
	double p2[3] = { x + center + 2.72, y + 5.5, z };
	double p3[3] = { x + center, y + 5.5 + -2.72, z };
	tag_t circle = NULL_TAG;
	UF_CURVE_create_arc_thru_3pts(2, p1, p2, p3, &circle);

	// рисую выемку под шарики
	std::string name = "gutter";
	tag_t sketch = NULL_TAG;
	UF_SKET_initialize_sketch((char*)name.c_str(), &sketch);

	double ramp_matrix[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 0 };
	tag_t ramp_object[2];
	int ramp_reference[2];
	UF_SKET_create_sketch((char*)name.c_str(), 2, ramp_matrix, ramp_object, ramp_reference, 2, &sketch);
	UF_SKET_add_objects(sketch, 1, &circle);
	UF_SKET_terminate_sketch();

	// цикл нужен, чтобы вращения вычлось из обоих цилиндров
	for (int i = 0; i < 2; i++) 
	{
		tag_t ballBearing = NULL_TAG;
		drawCyl(create, x, y + i * 7.5, z, "3.5", "42", 0, 1, 0, &ballBearing);

		tag_t neg = NULL_TAG;
		drawCyl(subtract, x, y + i * 7.5, z, "3.5", "25", 0, 1, 0, &neg);

		uf_list_p_t revolved;
		UF_MODL_create_list(&revolved);
		UF_MODL_put_list_item(revolved, sketch);
		double revolve_point[3] = { x, y, z };
		char revolve_start[15] = "0";
		char revolve_end[15] = "360";
		char* revolve_limit[2] = { revolve_start, revolve_end };
		double revolve_direction[3] = { 0, 1, 0 };
		uf_list_p_t revolve_feature_list;
		UF_MODL_create_revolved(revolved, revolve_limit, revolve_point, revolve_direction, subtract, &revolve_feature_list);
		UF_MODL_delete_list(&revolved);
		UF_MODL_delete_list(&revolve_feature_list);
	}

	for (int i = 0; i < 12; i++)
	{
		tag_t ball = NULL_TAG;
		double r = 16.75;
		double step = 30 * PI / 180.0; // radians
		double yAxe = 5.5;
		double center[3] = { x + r * cos(step * i), y + yAxe, z + r * sin(step * i) };
		char diam[5] = "5.44";
		UF_MODL_create_sphere1(create, center, diam, &ball);
	}
	
}
