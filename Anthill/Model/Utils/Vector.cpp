#include "Vector.h"
#include <math.h>
#include <random>
#include <sstream>
#include "..\..\Log.h"

const Vector Vector::zero(0, 0);

Vector::Vector(float _x, float _y) : x(_x), y(_y)
{

}

Vector::Vector()
{
	this->x = 0;
	this->y = 0;
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

float Vector::DistanceTo(Vector * target)
{
	return sqrt(pow(x - target->x, 2) + pow(y - target->y, 2));
}

void Vector::Normalize()
{
	float len = sqrt(x*x + y*y);
	if (len != 0)
	{
		x /= len;
		y /= len;
	}
}

const Vector * operator+(const Vector& left, const Vector& right)
{
	//!!утечки памяти!!
	return new Vector(left.x + right.x, left.y + right.y);
}

const Vector * operator-(const Vector& left, const Vector& right)
{
	return new Vector(left.x - right.x, left.y - right.y);
}

Vector& operator+=(Vector& left, const Vector& right)
{
	left.x += right.x;
	left.y += right.y;
	return left;
}

Vector& operator-=(Vector& left, const Vector& right)
{
	left.x -= right.x;
	left.y -= right.y;
	return left;
}

const Vector * operator*(const Vector& left, const float right)
{
	return new Vector(left.x * right, left.y * right);
}

Vector& Vector::operator=(const Vector& right)
{
	if (this == &right) {
		return *this;
	}
	this->x = right.x;
	this->y = right.y;
	return *this;
}

bool operator==(const Vector& left, const Vector& right) {
	return left.x == right.x && left.y == right.y;
}

bool operator!=(const Vector& left, const Vector& right) {
	return left.x != right.x || left.y != right.y;
}

Vector * Vector::RandomAround(float x, float y, float radius)
{
	std::ostringstream buf;
	Vector * v = new Vector(rand() % (int)(radius * 2) - radius + x, rand() % (int)(radius * 2) - radius + y);
	buf << "new vector: " << v->x << ';' << v->y;
	Log::Message(buf.str());
	return v;
}

void Vector::Noize()
{
	this->x += (rand() % 2 - 0.5) / 2;
	this->y += (rand() % 2 - 0.5) / 2;
}