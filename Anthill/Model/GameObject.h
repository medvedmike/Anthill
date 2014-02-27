#pragma once
#include "Utils\Vector.h"

class GameObject
{
protected:
	Vector * position;
	float size;
public:
	GameObject(Vector * _position, float _size);
	virtual ~GameObject();
	Vector * Position();
	void Position(Vector * value);
	float Size();
	virtual void Update(float _deltaTime);
};

