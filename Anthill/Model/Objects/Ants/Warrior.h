#pragma once
#include "BaseAnt.h"

class Warrior : public BaseAnt
{
public:
	Warrior(Vector * _position, Anthill * _home);
	~Warrior();
};

