#pragma once

#include <string>
#include <uf.h>
#include <uf_curve.h>
#include <uf_csys.h>
#include <uf_modl.h>
#include <uf_sket.h>

// Использовать для создания отдельного объекта
UF_FEATURE_SIGN create = UF_NULLSIGN;
// Использовать для создания объекта, объединяющегося с другими
UF_FEATURE_SIGN add = UF_POSITIVE;
// Использовать для  создания объекта, вычитающего объём из других
UF_FEATURE_SIGN subtract = UF_NEGATIVE;
// Использовать для создания объекта, оставляющего только то, что пересекается с ним
UF_FEATURE_SIGN intersected = UF_INTERSECT;

/// <summary>
/// Рисует скос для поверхности
/// </summary>
/// <param name="name">Имя скетча, на основе которого рисуется скос</param>
/// <param name="orig_x">Координата orig_x центра нижней грани болта</param>
/// <param name="orig_y">Координата orig_y центра нижней грани болта</param>
/// <param name="orig_z">Координата orig_z центра нижней грани болта</param>
/// <param name="outter_r">Внешний радиус скоса</param>
/// <param name="inner_r">Внутренний радиус скоса</param>
/// <param name="height">Высота скоса. Если положительная, то рисует вдоль Oz. Если отрицательная, то рисует в противоположную сторону.</param>
inline void __declspec(dllexport) drawRamp(
    const std::string& name, 
    double orig_x, double orig_y, double orig_z, 
    double outter_r, double inner_r, double height);

inline void __declspec(dllexport) drawRampHorizontal(
    const std::string& name, 
    double orig_x, double orig_y, double orig_z,
    double outter_r, double inner_r, double height);

/// <summary>
/// Обёртка для рисования блока
/// </summary>
/// <param name="sign">Булева операция для блока</param>
/// <param name="orig_x">Координата orig_x "левого" нижнего угла блока</param>
/// <param name="orig_y">Координата orig_y "левого" нижнего угла блока</param>
/// <param name="orig_z">Координата orig_z "левого" нижнего угла блока</param>
/// <param name="len">Размер блока по оси Ox</param>
/// <param name="wid">Размер блока по оси Oy</param>
/// <param name="hei">Размер блока по оси Oz</param>
/// <param name="tag">Тег блока</param>
inline void __declspec(dllexport) drawBlock(
    UF_FEATURE_SIGN sign,
    double orig_x, double orig_y, double orig_z,
    const char len[10], const char wid[10], const char hei[10], tag_t* tag);

/// <summary>
/// Обёртка для рисования цилиндра
/// </summary>
/// <param name="sign">Булева операция для цилиндра</param>
/// <param name="orig_x">Координата orig_x центра нижней грани цилиндра</param>
/// <param name="orig_y">Координата orig_y центра нижней грани цилиндра</param>
/// <param name="orig_z">Координата orig_z центра нижней грани цилиндра</param>
/// <param name="hei">Высота цилиндра</param>
/// <param name="diam">Диаметр блока</param>
/// <param name="dx">X координата вектора направления цилиндра</param>
/// <param name="dy">Y координата вектора направления цилиндра</param>
/// <param name="dz">Z координата вектора направления цилиндра</param>
/// <param name="tag">Тег цилиндра</param>
inline void __declspec(dllexport) drawCyl(
    UF_FEATURE_SIGN sign, 
    double orig_x, double orig_y, double orig_z, 
    const char hei[10], const char diam[10], double dx, double dy, double dz, tag_t* tag);
