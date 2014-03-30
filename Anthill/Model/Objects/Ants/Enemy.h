#pragma once
#include "BaseAnt.h"

class KillAllAntsStrategy;

class Enemy : public BaseAnt
{
private:
	float attack;
public:
	Enemy(Vector * _position, Anthill * _home);
	~Enemy();
	void Update(float  _deltaTime);
	friend KillAllAntsStrategy;
};

