#pragma once
class Vector
{
private:
	float x, y;
public:
	Vector(float _x, float _y);
	~Vector();
	float X();
	float Y();
	void X(float _x);
	void Y(float _y);
};

