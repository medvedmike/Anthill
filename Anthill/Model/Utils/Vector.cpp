#include "Vector.h"

Vector::Vector(float _x, float _y) : x(_x), y(_y)
{

}

Vector::~Vector()
{
}

float Vector::X()
{
	return x;
}

float Vector::Y()
{
	return y;
}

void Vector::X(float _x)
{
	this->x = _x;
}

void Vector::Y(float _y)
{
	this->y = _y;
}
