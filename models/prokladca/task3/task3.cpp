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

    double c_hole_in_korpus_above[3] = {
        coordinates_of_center[0],
        coordinates_of_center[1],
        coordinates_of_center[2]
    };
    char height_above[125] = "1";
    char diam_above[125] = "75";
    double direction_above[3] = { 0, 0, 1.0 };
    tag_t hole_in_korpus_above;
    UF_MODL_create_cyl1(UF_NULLSIGN, c_hole_in_korpus_above, height_above, diam_above, direction_above, &hole_in_korpus_above);

    double c_hole_in_korpus_above2[3] = {
        coordinates_of_center[0],
        coordinates_of_center[1],
        coordinates_of_center[2]
    };
    char height_above2[125] = "1";
    char diam_above2[125] = "65";
    double direction_above2[3] = { 0, 0, 1.0 };
    tag_t hole_in_korpus_above2;
    UF_MODL_create_cyl1(UF_NEGATIVE, c_hole_in_korpus_above2, height_above2, diam_above2, direction_above2, &hole_in_korpus_above2);

    UF_terminate();
}


int ufusr_ask_unload(void) {
    return (UF_UNLOAD_IMMEDIATELY);
}


