#pragma once

#include <string>
#include <uf.h>
#include <uf_curve.h>
#include <uf_csys.h>
#include <uf_modl.h>
#include <uf_sket.h>

// ������������ ��� �������� ���������� �������
UF_FEATURE_SIGN create = UF_NULLSIGN;
// ������������ ��� �������� �������, ��������������� � �������
UF_FEATURE_SIGN add = UF_POSITIVE;
// ������������ ���  �������� �������, ����������� ����� �� ������
UF_FEATURE_SIGN subtract = UF_NEGATIVE;
// ������������ ��� �������� �������, ������������ ������ ��, ��� ������������ � ���
UF_FEATURE_SIGN intersected = UF_INTERSECT;

/// <summary>
/// ������ ���� ��� �����������
/// </summary>
/// <param name="name">��� ������, �� ������ �������� �������� ����</param>
/// <param name="orig_x">���������� orig_x ������ ������ ����� �����</param>
/// <param name="orig_y">���������� orig_y ������ ������ ����� �����</param>
/// <param name="orig_z">���������� orig_z ������ ������ ����� �����</param>
/// <param name="outter_r">������� ������ �����</param>
/// <param name="inner_r">���������� ������ �����</param>
/// <param name="height">������ �����. ���� �������������, �� ������ ����� Oz. ���� �������������, �� ������ � ��������������� �������.</param>
inline void __declspec(dllexport) drawRamp(const std::string& name, double orig_x, double orig_y, double orig_z, double outter_r, double inner_r, double height);
inline void __declspec(dllexport) drawRampHorizontal(const std::string& name, double orig_x, double orig_y, double orig_z, double outter_r, double inner_r, double height);

/// <summary>
/// ������ ��� ��������� �����
/// </summary>
/// <param name="sign">������ �������� ��� �����</param>
/// <param name="orig_x">���������� orig_x "������" ������� ���� �����</param>
/// <param name="orig_y">���������� orig_y "������" ������� ���� �����</param>
/// <param name="orig_z">���������� orig_z "������" ������� ���� �����</param>
/// <param name="len">������ ����� �� ��� Ox</param>
/// <param name="wid">������ ����� �� ��� Oy</param>
/// <param name="hei">������ ����� �� ��� Oz</param>
/// <param name="tag">��� �����</param>
inline void __declspec(dllexport) drawBlock(UF_FEATURE_SIGN sign, double orig_x, double orig_y, double orig_z, const char len[10], const char wid[10], const char hei[10], tag_t* tag);

/// <summary>
/// ������ ��� ��������� ��������
/// </summary>
/// <param name="sign">������ �������� ��� ��������</param>
/// <param name="orig_x">���������� orig_x ������ ������ ����� ��������</param>
/// <param name="orig_y">���������� orig_y ������ ������ ����� ��������</param>
/// <param name="orig_z">���������� orig_z ������ ������ ����� ��������</param>
/// <param name="len">������ ����� �� ��� Ox</param>
/// <param name="wid">������ ����� �� ��� Oy</param>
/// <param name="hei">������ ����� �� ��� Oz</param>
/// <param name="tag">��� �����</param>


/// <summary>
/// ������ ��� ��������� ��������
/// </summary>
/// <param name="sign">������ �������� ��� ��������</param>
/// <param name="orig_x">���������� orig_x ������ ������ ����� ��������</param>
/// <param name="orig_y">���������� orig_y ������ ������ ����� ��������</param>
/// <param name="orig_z">���������� orig_z ������ ������ ����� ��������</param>
/// <param name="hei">������ ��������</param>
/// <param name="diam">������� �����</param>
/// <param name="dx">X ���������� ������� ����������� ��������</param>
/// <param name="dy">Y ���������� ������� ����������� ��������</param>
/// <param name="dz">Z ���������� ������� ����������� ��������</param>
/// <param name="tag">��� ��������</param>
inline void __declspec(dllexport) drawCyl(UF_FEATURE_SIGN sign, double orig_x, double orig_y, double orig_z, const char hei[10], const char diam[10], double dx, double dy, double dz, tag_t* tag);
