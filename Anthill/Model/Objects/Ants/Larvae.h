#pragma once
#include "BaseAnt.h"

class Larvae : public BaseAnt
{
public:
	Larvae(Vector * _position, float _size, Anthill * _home);
	~Larvae();
};

