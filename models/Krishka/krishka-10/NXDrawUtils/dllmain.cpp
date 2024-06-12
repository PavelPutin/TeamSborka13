// dllmain.cpp : Определяет точку входа для приложения DLL.
#include "pch.h"
#include "NXDrawUtils.h"

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

void drawRamp(const std::string& name, double orig_x, double orig_y, double orig_z, double outter_r, double inner_r, double height)
{
	double points[4][3] = {
		{orig_x, orig_y + outter_r, orig_z},
		{orig_x, orig_y + inner_r, orig_z},
		{orig_x, orig_y + outter_r, orig_z + height},
		{orig_x, orig_y + outter_r, orig_z},
	};

	tag_t lines[3];
	UF_CURVE_line_t lines_coords[3];

	for (int i = 0; i < 3; i++)
	{
		lines_coords[i].start_point[0] = points[i][0];
		lines_coords[i].start_point[1] = points[i][1];
		lines_coords[i].start_point[2] = points[i][2];

		lines_coords[i].end_point[0] = points[i + 1][0];
		lines_coords[i].end_point[1] = points[i + 1][1];
		lines_coords[i].end_point[2] = points[i + 1][2];
		UF_CURVE_create_line(&lines_coords[i], &lines[i]);
	}

	tag_t sketch = NULL_TAG;
	UF_SKET_initialize_sketch((char*)name.c_str(), &sketch);

	double ramp_matrix[9] = { 0, 1, 0, 0, 0, 1, 0, 0, 0 };
	tag_t ramp_object[2];
	int ramp_reference[2];
	UF_SKET_create_sketch((char*)name.c_str(), 2, ramp_matrix, ramp_object, ramp_reference, 2, &sketch);
	UF_SKET_add_objects(sketch, 3, lines);
	UF_SKET_terminate_sketch();

	uf_list_p_t revolved;
	UF_MODL_create_list(&revolved);
	UF_MODL_put_list_item(revolved, sketch);
	double revolve_point[3] = { orig_x, orig_y, orig_z };
	char revolve_start[15] = "0";
	char revolve_end[15] = "360";
	char* revolve_limit[2] = { revolve_start, revolve_end };
	double revolve_direction[3] = { 0, 0, 1 };
	uf_list_p_t revolve_feature_list;
	UF_MODL_create_revolved(revolved, revolve_limit, revolve_point, revolve_direction, subtract, &revolve_feature_list);
	UF_MODL_delete_list(&revolved);
	UF_MODL_delete_list(&revolve_feature_list);
}

void drawRampHorizontal(const std::string& name, double orig_x, double orig_y, double orig_z, double outter_r, double inner_r, double height)
{
	double points[4][3] = {
		{orig_x, orig_y, orig_z + outter_r},
		{orig_x, orig_y, orig_z + inner_r},
		{orig_x, orig_y + height, orig_z + outter_r},
		{orig_x, orig_y, orig_z + outter_r},
	};

	tag_t lines[3];
	UF_CURVE_line_t lines_coords[3];

	for (int i = 0; i < 3; i++)
	{
		lines_coords[i].start_point[0] = points[i][0];
		lines_coords[i].start_point[1] = points[i][1];
		lines_coords[i].start_point[2] = points[i][2];

		lines_coords[i].end_point[0] = points[i + 1][0];
		lines_coords[i].end_point[1] = points[i + 1][1];
		lines_coords[i].end_point[2] = points[i + 1][2];
		UF_CURVE_create_line(&lines_coords[i], &lines[i]);
	}

	tag_t sketch = NULL_TAG;
	UF_SKET_initialize_sketch((char*)name.c_str(), &sketch);

	double ramp_matrix[9] = { 0, 1, 0, 0, 0, 1, 0, 0, 0 };
	tag_t ramp_object[2];
	int ramp_reference[2];
	UF_SKET_create_sketch((char*)name.c_str(), 2, ramp_matrix, ramp_object, ramp_reference, 2, &sketch);
	UF_SKET_add_objects(sketch, 3, lines);
	UF_SKET_terminate_sketch();

	uf_list_p_t revolved;
	UF_MODL_create_list(&revolved);
	UF_MODL_put_list_item(revolved, sketch);
	double revolve_point[3] = { orig_x, orig_y, orig_z };
	char revolve_start[15] = "0";
	char revolve_end[15] = "360";
	char* revolve_limit[2] = { revolve_start, revolve_end };
	double revolve_direction[3] = { 0, 1, 0 };
	uf_list_p_t revolve_feature_list;
	UF_MODL_create_revolved(revolved, revolve_limit, revolve_point, revolve_direction, subtract, &revolve_feature_list);
	UF_MODL_delete_list(&revolved);
	UF_MODL_delete_list(&revolve_feature_list);
}

void drawBlock(UF_FEATURE_SIGN sign, double x, double y, double z, const char len[10], const char wid[10], const char hei[10], tag_t* tag)
{
	double orig[3] = { x, y, z };
	char* size[3] = { (char*)len, (char*)wid, (char*)hei };
	UF_MODL_create_block1(sign, orig, size, tag);
}

void drawCyl(UF_FEATURE_SIGN sign, double x, double y, double z, const char hei[10], const char diam[10], double dx, double dy, double dz, tag_t* tag)
{
	double orig[3] = { x, y, z };
	double direction[3] = { dx, dy, dz };
	UF_MODL_create_cyl1(sign, orig, (char*)hei, (char*)diam, direction, tag);
}