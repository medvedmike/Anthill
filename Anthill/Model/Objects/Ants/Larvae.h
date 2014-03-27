#pragma once
#include "BaseAnt.h"

class Anthill;

class Larvae : public BaseAnt
{
private:
	float timeToGrown;
public:
	Larvae(Vector * _position, Anthill * _home);
	~Larvae();
	void Update(float _deltaTime);
	bool IsGrowned();
};

