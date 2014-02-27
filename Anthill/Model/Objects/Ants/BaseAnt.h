#pragma once
#include "..\..\GameObject.h"

class BaseAnt : public GameObject
{
protected:
	float health;
	float speed;
	float defence;
	float eating;
	float satiety;
public:
	BaseAnt(Vector * _position, float _size, float _speed, float _eating, float _defence);
	~BaseAnt();
	void Update();
	float GetHealth();
};

