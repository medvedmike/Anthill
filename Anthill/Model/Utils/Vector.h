#pragma once
class Vector
{
private:
	float x, y;
public:
	Vector(float _x, float _y);
	Vector();
	~Vector();
	float X();
	float Y();
	void X(float _x);
	void Y(float _y);
	float DistanceTo(Vector * target);
	void Normalize();
	friend const Vector& operator+(const Vector& left, const Vector& right);
	friend const Vector& operator-(const Vector& left, const Vector& right);
	friend Vector& operator+=(Vector& left, const Vector& right);
	friend Vector& operator-=(Vector& left, const Vector& right);
	friend const Vector& operator*(const Vector& left, const float right);
	Vector& operator=(const Vector& right);
	friend bool operator==(const Vector& left, const Vector& right);
	friend bool operator!=(const Vector& left, const Vector& right);
	static Vector * RandomAround(float x, float y, float radius);
};

