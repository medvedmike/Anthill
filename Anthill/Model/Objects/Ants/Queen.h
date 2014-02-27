#pragma once
#include "BaseAnt.h"
class Queen : public BaseAnt
{
public:
	Queen(Vector * _position, float _size, Anthill * _home);
	~Queen();
};

