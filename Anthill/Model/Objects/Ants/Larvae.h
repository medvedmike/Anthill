#pragma once
#include "BaseAnt.h"

class Larvae : public BaseAnt
{
public:
	Larvae(Vector * _position, Anthill * _home);
	~Larvae();
};

