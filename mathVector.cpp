#include "mathVector.h"


//Операция сложения
MathVector MathVector::operator+(MathVector const& obj)
{
    MathVector res;
    res.x = this->x + obj.x;
    res.y = this->y + obj.y;
    res.z = this->z + obj.z;

    return res;
}

// Операция вычитания
MathVector MathVector::operator-(MathVector const& obj)
{
    MathVector res;
    res.x = this->x - obj.x;
    res.y = this->y - obj.y;
    res.z = this->z - obj.z;

    return res;
}

// Операция векторное умножение
MathVector MathVector::crossProd(MathVector const& obj)
{
    MathVector res;
    res.x = this->y * obj.z - this->z * obj.y;
    res.y = this->z * obj.x - this->x * obj.z;
    res.z = this->x * obj.z - this->z * obj.x;

    return res;
}

// Операция скалярного умножения
float MathVector::dotProd(MathVector const& obj) const
{
    float res(0.0);
    res += this->x * obj.x;
    res += this->y * obj.y;
    res += this->z * obj.z;

    return res;
}

// Операция определения длины вектора
float MathVector::len()
const
{
    float res(0.0);
    res += this->x * this->x;
    res += this->y * this->y;
    res += this->z * this->z;

    return sqrt(res);
}

// Операция определния косинуса между векторами
float MathVector::cosBetween(MathVector const& obj) const
{
    return this->dotProd(obj) / this->len() / obj.len();
}

// Операция определения угла между векторами
float MathVector::angle(MathVector const& obj) const
{
    return acos(this->cosBetween(obj));
}

// Конструктор базовый
MathVector::MathVector(float xParam, float yParam, float zParam)
{
    this->x = xParam;
    this->y = yParam;
    this->z = zParam;
}

// Конструктор копирования
MathVector::MathVector(MathVector &copy)
{
    this->x = copy.x;
    this->y = copy.y;
    this->z = copy.z;
}
