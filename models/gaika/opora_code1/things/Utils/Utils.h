#pragma once

#include <sstream>

/// <summary>
/// ������������ double � C-�������� ������
/// </summary>
/// <param name="value">�������� double</param>
/// <returns>������ � C �����</returns>
inline __declspec(dllexport) const char* doubleToConstChar(double value);