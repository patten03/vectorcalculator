#ifndef PROGRES_H
#define PROGRES_H

#include <mathVector.h>

// Структура для хранения вводимых данных пользователем и резульатов вычислений
struct Calculations
{
    MathVector A, B; // Векторы A и B
    MathVector       // Векторы суммы, разности и вектороного произведения
        Sum,
        Diff,
        CrossProd;
    float
        cosinus,     // значения косинуса
        angle,       // значение угла между векторами
        sumLength,   // длина вектора суммы
        diffLength,  // длина вектора разности
        dotProd;     // значение скалярного произведения

    Calculations();
};

#endif // PROGRES_H
