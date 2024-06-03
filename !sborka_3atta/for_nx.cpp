#include <uf.h>
#include <iostream>
#include <uf_curve.h>
#include <uf_sket.h>
#include <uf_modl.h>
#include <string>
#include <cstring>
#include <uf_sket.h>
#include <uf_defs.h>


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

char** getCharArrForLengths(double x, double y, double z) {
    // Преобразуем double в char*
    char x_str[20], y_str[20], z_str[20];
    sprintf_s(x_str, 20, "%.2f", x);
    sprintf_s(y_str, 20, "%.2f", y);
    sprintf_s(z_str, 20, "%.2f", z);

    // Создаем динамический массив char*
    char** size = new char* [3];
    size[0] = new char[strlen(x_str) + 1];
    strcpy_s(size[0], strlen(x_str) + 1, x_str);
    size[1] = new char[strlen(y_str) + 1];
    strcpy_s(size[1], strlen(y_str) + 1, y_str);
    size[2] = new char[strlen(z_str) + 1];
    strcpy_s(size[2], strlen(z_str) + 1, z_str);

    return size;
}

tag_t create_line(double start_point[3], double end_point[3]) {
    UF_CURVE_line_t line_coords;
    for (int i = 0; i < 3; i++) {
        line_coords.start_point[i] = start_point[i];
        line_coords.end_point[i] = end_point[i];
    }

    tag_t line_tag = NULL_TAG;
    UF_CURVE_create_line(&line_coords, &line_tag);
    return line_tag;
}

void create_extrusion(tag_t sketch, double distance) {
    // Создание списка объектов для вытягивания
    uf_list_p_t Ext3;
    UF_MODL_create_list(&Ext3);
    UF_MODL_put_list_item(Ext3, sketch);

    // Параметры для вытягивания
    UF_FEATURE_SIGN extsign3 = UF_POSITIVE;
    char tapang3[5] = "0.0";
    char ext3s[15] = "0.0";
    std::string temp3 = std::to_string(distance);
    char ext3e[15];
    strcpy_s(ext3e, sizeof(ext3e), temp3.c_str());
    char* ExtLimit3[2] = { ext3s, ext3e };
    double extpoint3[3] = { 0.0, 0.0, 0.0 };
    double extdir3[3] = { 0.0, 1.0, 0.0 };

    // Создание вытягивания
    uf_list_p_t ExtFeatureList3;
    UF_MODL_create_extruded(Ext3, tapang3, ExtLimit3, extpoint3, extdir3, extsign3, &ExtFeatureList3);

    // Очистка списков
    UF_MODL_delete_list(&ExtFeatureList3);
    UF_MODL_delete_list(&Ext3);
}





double finalStartMainCylZ = 140;
double finalSideHolesDistance = 170;
double finalDepthHolesDistance = 156;

//главный блок
double mainKorpusX = 200;
double mainKorpusY = 210;
double mainKorpusZ = 175;


//внутренняя полость
double widthInDepth = 60;
double widthToTheSide = 25;
double widthOfWall = 15;
double cavityZ = 70;
double cavityY = 210 - widthOfWall * 2 - widthToTheSide * 2;
double cavityX = 200 - widthOfWall * 2 - widthInDepth * 2;


//ножки
double legHeight = 20;


//перегородка
double widthPartition = 15;


void ufusr(char* param, int* retcode, int paramLen) {
    UF_initialize();

    double centerCoordinates[3] = { 0,0,0 }; //Coordinates
    double leftStartPoint[3] = 
    { 
        centerCoordinates[0] - mainKorpusX / 2,
        centerCoordinates[1],
        centerCoordinates[2]
    };


    //Главный корпус
    tag_t mainKorpus;
    UF_MODL_create_block1(UF_NULLSIGN, leftStartPoint, getCharArrForLengths(mainKorpusX, mainKorpusY, mainKorpusZ), &mainKorpus);
    ///


    ////Полость
    //tag_t subtractionBetweenLegs;
    //double subtractionBetweenLegsCoordinates[3] =
    //{
    //    centerCoordinates[0] - cavityX / 2,
    //    centerCoordinates[1] + widthToTheSide + widthOfWall,
    //    centerCoordinates[2]
    //};
    //UF_MODL_create_block1(UF_NEGATIVE, subtractionBetweenLegsCoordinates, getCharArrForLengths(cavityX, cavityY, cavityZ), &subtractionBetweenLegs);
    /////


    //Вычитание из левой части корпуса
    tag_t subtractionFromLeftKorpusPart;
    double subtractionFromLeftKorpusPartCoordinates[3] =
    {
        leftStartPoint[0],
        leftStartPoint[1],
        leftStartPoint[2] + legHeight
    };
    tag_t subtractionBetweenLegsRight;
    UF_MODL_create_block1(UF_NEGATIVE, subtractionFromLeftKorpusPartCoordinates, getCharArrForLengths(500, widthToTheSide, 500), &subtractionFromLeftKorpusPart);
    ///


    //Вычитание из правой части корпуса
    tag_t subtractionFromRightKorpusPart;
    double subtractionFromRightKorpusPartCoordinates[3] =
    {
        leftStartPoint[0],
        leftStartPoint[1] + widthToTheSide + widthOfWall + widthOfWall + cavityY,
        leftStartPoint[2] + legHeight
    };
    UF_MODL_create_block1(UF_NEGATIVE, subtractionFromRightKorpusPartCoordinates, getCharArrForLengths(500, widthToTheSide, 500), &subtractionFromRightKorpusPart);
    ///


    //Вычитание из дальнего полупространства
    tag_t subtractionFromFarSpace;
    double subtractionFromFarSpaceCoordinates[3] =
    {
        leftStartPoint[0],
        leftStartPoint[1],
        leftStartPoint[2] + legHeight
    };
    UF_MODL_create_block1(UF_NEGATIVE, subtractionFromFarSpaceCoordinates, getCharArrForLengths(widthInDepth, 500, 500), &subtractionFromFarSpace);
    ///


    //Вычитание из ближнего полупространства
    tag_t subtractionFromNearSpace;
    double subtractionFromNearSpaceCoordinates[3] =
    {
        leftStartPoint[0] + widthInDepth + cavityX + widthOfWall * 2,
        leftStartPoint[1],
        leftStartPoint[2] + legHeight
    };
    UF_MODL_create_block1(UF_NEGATIVE, subtractionFromNearSpaceCoordinates, getCharArrForLengths(widthInDepth, 500, 500), &subtractionFromNearSpace);
    ///


    //Вычитание всё сверху
    tag_t subtractionFromAllAbove;
    double subtractionFromAllAboveCoordinates[3] =
    {
        leftStartPoint[0],
        leftStartPoint[1],
        leftStartPoint[2] + 100
    };
    UF_MODL_create_block1(UF_NEGATIVE, subtractionFromAllAboveCoordinates, getCharArrForLengths(500, 500, 500), &subtractionFromAllAbove);
    ///


    //Главный цилиндр
    tag_t mainCyl;
    double mainCylCoordinates[3] = {
        centerCoordinates[0],
        centerCoordinates[1] + 10,
        centerCoordinates[2] + finalStartMainCylZ
    };
    char h1[125] = "190";
    char d1[125] = "115";
    double mainCylDiameter = 115;
    double dir1[3] = { 0, 1.0, 0 };
    UF_MODL_create_cyl1(UF_POSITIVE, mainCylCoordinates, h1, d1, dir1, &mainCyl);
    ///


    //левое дальнее отверстие
    tag_t firstHole;
    double firstHoleCoordinates[3] = {
        leftStartPoint[0] + 20,
        leftStartPoint[1] + 20,
        leftStartPoint[2]
    };
    char h2[125] = "20";
    char d2[125] = "20";
    double dir2[3] = { 0, 0, 1.0 };
    UF_MODL_create_cyl1(UF_NEGATIVE, firstHoleCoordinates, h2, d2, dir2, &firstHole);
    ///


    //левое ближнее отверстие
    tag_t secondHole;
    double secondHoleCoordinates[3] = {
        leftStartPoint[0] + mainKorpusX - 20,
        leftStartPoint[1] + 20,
        leftStartPoint[2]
    };
    char h3[125] = "20";
    char d3[125] = "20";
    double dir3[3] = { 0, 0, 1.0 };
    UF_MODL_create_cyl1(UF_NEGATIVE, secondHoleCoordinates, h3, d3, dir3, &secondHole);
    ///


    //правое дальнее отверстие
    tag_t thirdHole;
    double thirdHoleCoordinates[3] = {
        leftStartPoint[0] + 20,
        leftStartPoint[1] + mainKorpusY - 20,
        leftStartPoint[2]
    };
    char h4[125] = "20";
    char d4[125] = "20";
    double dir4[3] = { 0, 0, 1.0 };
    UF_MODL_create_cyl1(UF_NEGATIVE, thirdHoleCoordinates, h4, d4, dir4, &thirdHole);
    ///


    //правое ближнее отверстие
    tag_t fourthHole;
    double fourthHoleCoordinates[3] = {
        leftStartPoint[0] + mainKorpusX - 20,
        leftStartPoint[1] + mainKorpusY - 20,
        leftStartPoint[2]
    };
    char h5[125] = "20";
    char d5[125] = "20";
    double dir5[3] = { 0, 0, 1.0 };
    UF_MODL_create_cyl1(UF_NEGATIVE, fourthHoleCoordinates, h5, d5, dir5, &fourthHole);
    ///


    //эскиз - перегородки
    double line1_start[3] = 
    { 
        leftStartPoint[0],
        leftStartPoint[1] + (mainKorpusY - 15) / 2.0,
        leftStartPoint[2] + legHeight
    };
    double line1_end[3] =
    {
        leftStartPoint[0] + widthInDepth,
        leftStartPoint[1] + (mainKorpusY - 15) / 2.0,
        leftStartPoint[2] + finalStartMainCylZ - 10
    };
    double line2_end[3] =
    {
        leftStartPoint[0] + mainKorpusX - widthInDepth,
        leftStartPoint[1] + (mainKorpusY - 15) / 2.0,
        leftStartPoint[2] + finalStartMainCylZ - 10
    };
    double line3_end[3] =
    {
        leftStartPoint[0] + mainKorpusX,
        leftStartPoint[1] + (mainKorpusY - 15) / 2.0,
        leftStartPoint[2] + legHeight
    };

    // Создание линий
    tag_t line1_tag = create_line(line1_start, line1_end);
    tag_t line2_tag = create_line(line1_end, line2_end);
    tag_t line3_tag = create_line(line2_end, line3_end);
    tag_t line4_tag = create_line(line3_end, line1_start);

    // Создание эскиза
    tag_t sketch1 = NULL_TAG;
    char scn[129] = "scname1";
    UF_SKET_initialize_sketch(scn, &sketch1);

    // Настройки для создания эскиза
    int option = 2;
    double matrix[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };
    tag_t object[2] = { NULL_TAG, NULL_TAG };
    int reference[2] = { 0, 0 };
    int plane_dir = 2;
    UF_SKET_create_sketch(scn, option, matrix, object, reference, plane_dir, &sketch1);

    // Добавление линий в эскиз
    tag_t sketch_lines[4] = { line1_tag, line2_tag, line3_tag, line4_tag };
    UF_SKET_add_objects(sketch1, 4, sketch_lines);

    create_extrusion(sketch1, 15.0);

    //Полость
    tag_t subtractionBetweenLegs;
    double subtractionBetweenLegsCoordinates[3] =
    {
        centerCoordinates[0] - cavityX / 2,
        centerCoordinates[1] + widthToTheSide + widthOfWall,
        centerCoordinates[2]
    };
    UF_MODL_create_block1(UF_NEGATIVE, subtractionBetweenLegsCoordinates, getCharArrForLengths(cavityX, cavityY, cavityZ), &subtractionBetweenLegs);
    ///


    //Сквозное отверстие в главном цилиндре
    tag_t holeInMainCyl;
    double holeInMainCylCoordinates[3] = {
        centerCoordinates[0],
        centerCoordinates[1] + 10,
        centerCoordinates[2] + finalStartMainCylZ
    };
    char h6[125] = "190";
    char d6[125] = "46";
    double dir6[3] = { 0, 1.0, 0 };
    UF_MODL_create_cyl1(UF_NEGATIVE, holeInMainCylCoordinates, h6, d6, dir6, &holeInMainCyl);
    ///
    

    //Левое углубление под подшипники в главном цилиндре
    tag_t leftInMainCyl;
    double leftInMainCylCoordinates[3] = {
        centerCoordinates[0],
        centerCoordinates[1] + 10,
        centerCoordinates[2] + finalStartMainCylZ
    };
    char h7[125] = "22";
    char d7[125] = "62";
    double dir7[3] = { 0, 1.0, 0 };
    UF_MODL_create_cyl1(UF_NEGATIVE, leftInMainCylCoordinates, h7, d7, dir7, &leftInMainCyl);
    ///


    //Правое углубление под подшипники в главном цилиндре
    tag_t rightInMainCyl;
    double rightInMainCylCoordinates[3] = {
        centerCoordinates[0],
        centerCoordinates[1] + mainKorpusY - 10,
        centerCoordinates[2] + finalStartMainCylZ
    };
    char h8[125] = "11";
    char d8[125] = "62";
    double dir8[3] = { 0, -1.0, 0 };
    UF_MODL_create_cyl1(UF_NEGATIVE, rightInMainCylCoordinates, h8, d8, dir8, &rightInMainCyl);
    ///


    UF_terminate();
}

int ufusr_ask_unload(void) {
    return (UF_UNLOAD_IMMEDIATELY);
}