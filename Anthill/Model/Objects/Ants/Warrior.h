#pragma once
#include "BaseAnt.h"

class KillEnemiesStrategy;

class Warrior : public BaseAnt
{
private:
	float attack;
	float attacking;
public:
	Warrior(Vector * _position, Anthill * _home);
	~Warrior();
	void Update(float _deltaTime);
	friend KillEnemiesStrategy;
};

