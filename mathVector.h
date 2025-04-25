#ifndef MATHVECTOR_H
#define MATHVECTOR_H

#include <cmath>

class MathVector
{
public:
    // Координаты вектора
    float x, y, z;

    // Математические операции для работы с векторами
    // Операции, которые возвращают векторные значения
    MathVector operator+(MathVector const& obj);   // операция сложения
    MathVector operator-(MathVector const& obj);   // операция вычитания
    MathVector crossProd(MathVector const& obj);   // операция вектороного умножения
    // Операции, которые возвращают скалярные значения
    float dotProd(MathVector const& obj) const;    // операция скалаярного умножения
    float len() const;                             //
    float cosBetween(MathVector const& obj) const; // операция определения косинуса между векторами
    float angle(MathVector const& obj) const;      // операция определения угла между векторами

    // Конструкторы
    MathVector(float xParam = 0, float yParam = 0, float zParam = 0);
    MathVector(MathVector &copy);
};

#endif // MATHVECTOR_H
