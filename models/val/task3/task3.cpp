#include <uf.h>
#include <iostream>
#include <uf_curve.h>
#include <uf_sket.h>
#include <uf_modl.h>
#include <string>
#include <cstring>


char** getCharArrForLengths(const char* x, const char* y, const char* z) {
    char* x_copy = new char[strlen(x) + 1];
    strcpy_s(x_copy, strlen(x) + 1, x);

    char* y_copy = new char[strlen(y) + 1];
    strcpy_s(y_copy, strlen(y) + 1, y);

    char* z_copy = new char[strlen(z) + 1];
    strcpy_s(z_copy, strlen(z) + 1, z);

    char** size = new char* [3];
    size[0] = x_copy;
    size[1] = y_copy;
    size[2] = z_copy;

    return size;
}

void ufusr(char* param, int* retcode, int paramLen) {
    UF_initialize();

    double coordinates_of_center[3] = { 0,0,0 };

    double cylinder1_coor[3] = {
        coordinates_of_center[0],
        coordinates_of_center[1],
        coordinates_of_center[2]
    };
    char height_cylinder1[125] = "120";
    char diam_cylinder1[125] = "29";
    double direction_cylinder1[3] = { 0, 0, 1.0 };
    tag_t cylinder1;
    UF_MODL_create_cyl1(UF_NULLSIGN, cylinder1_coor, height_cylinder1, diam_cylinder1, direction_cylinder1, &cylinder1);

    double cylinder2_coor[3] = {
        coordinates_of_center[0],
        coordinates_of_center[1],
        coordinates_of_center[2] + 120
    };
    char height_cylinder2[125] = "60";
    char diam_cylinder2[125] = "30";
    double direction_cylinder2[3] = { 0, 0, 1.0 };
    tag_t cylinder2;
    UF_MODL_create_cyl1(UF_NULLSIGN, cylinder2_coor, height_cylinder2, diam_cylinder2, direction_cylinder2, &cylinder2);

    double cylinder3_coor[3] = {
        coordinates_of_center[0],
        coordinates_of_center[1],
        coordinates_of_center[2] + 120 + 60
    };
    char height_cylinder3[125] = "100";
    char diam_cylinder3[125] = "50";
    double direction_cylinder3[3] = { 0, 0, 1.0 };
    tag_t cylinder3;
    UF_MODL_create_cyl1(UF_NULLSIGN, cylinder3_coor, height_cylinder3, diam_cylinder3, direction_cylinder3, &cylinder3);

    double cylinder4_coor[3] = {
        coordinates_of_center[0],
        coordinates_of_center[1],
        coordinates_of_center[2] + 120 + 60 + 100
    };
    char height_cylinder4[125] = "40";
    char diam_cylinder4[125] = "35";
    double direction_cylinder4[3] = { 0, 0, 1.0 };
    tag_t cylinder4;
    UF_MODL_create_cyl1(UF_NULLSIGN, cylinder4_coor, height_cylinder4, diam_cylinder4, direction_cylinder4, &cylinder4);

    double cylinder5_coor[3] = {
        coordinates_of_center[0],
        coordinates_of_center[1],
        coordinates_of_center[2] + 120 + 60 + 100
    };
    char height_cylinder5[125] = "70";
    char diam_cylinder5[125] = "25";
    double direction_cylinder5[3] = { 0, 0, 1.0 };
    tag_t cylinder5;
    UF_MODL_create_cyl1(UF_NULLSIGN, cylinder5_coor, height_cylinder5, diam_cylinder5, direction_cylinder5, &cylinder5);

    double cylinder6_coor[3] = {
        coordinates_of_center[0],
        coordinates_of_center[1],
        coordinates_of_center[2] + 120 + 60 + 100
    };
    char height_cylinder6[125] = "70";
    char diam_cylinder6[125] = "25";
    double direction_cylinder6[3] = { 0, 0, 1.0 };
    tag_t cylinder6;
    UF_MODL_create_cyl1(UF_NULLSIGN, cylinder6_coor, height_cylinder6, diam_cylinder6, direction_cylinder6, &cylinder6);


    tag_t korpus_block_negative1;
    UF_MODL_create_block1(UF_NEGATIVE, coordinates_of_center, getCharArrForLengths("7", "8", "20"), &cylinder5);

    UF_terminate();
}


int ufusr_ask_unload(void) {
    return (UF_UNLOAD_IMMEDIATELY);
}


