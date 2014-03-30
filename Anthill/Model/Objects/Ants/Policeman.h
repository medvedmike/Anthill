#pragma once

#include "BaseAnt.h"

class Policeman : public BaseAnt
{
public:
	Policeman(Vector * _position, Anthill * _home);
	~Policeman();
	void Update(float _deltaTime);
};