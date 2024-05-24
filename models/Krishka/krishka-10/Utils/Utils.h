#pragma once

#include <sstream>

/// <summary>
/// Конвертирует double в C-подобную строку
/// </summary>
/// <param name="value">Значение double</param>
/// <returns>Строка в C стиле</returns>
inline __declspec(dllexport) const char* doubleToConstChar(double value);