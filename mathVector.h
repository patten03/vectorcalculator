#ifndef MATHVECTOR_H
#define MATHVECTOR_H

#include <cmath>

class MathVector
{
    // Координаты вектора
public:
    float x, y, z;

    // Математические операции для работы с векторами
    // Операции, которые возвращают векторные значения
    MathVector operator+(MathVector const& obj);
    MathVector operator-(MathVector const& obj);
    MathVector crossProd(MathVector const& obj);
    // Операции, которые возвращают скалярные значения
    float dotProd(MathVector const& obj) const;
    float len() const;
    float cosBetween(MathVector const& obj) const;
    float angle(MathVector const& obj) const;

    // Конструкторы
    MathVector(float xParam = 0, float yParam = 0, float zParam = 0);
    MathVector(MathVector &copy);
};

#endif // MATHVECTOR_H
