#ifndef PROGRES_H
#define PROGRES_H

#include <mathVector.h>

// Структура для хранения вводимых данных пользователем и резульатов вычислений
struct Calculations
{
    MathVector A, B;
    MathVector Sum, Diff, CrossProd;
    float cosinus, angle, sumLength, diffLength, dotProd;

    Calculations();
};

#endif // PROGRES_H
