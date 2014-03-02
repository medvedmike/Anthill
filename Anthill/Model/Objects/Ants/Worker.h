#pragma once
#include "BaseAnt.h"

class Worker : public BaseAnt
{
public:
	Worker(Vector * _position, Anthill * _home);
	~Worker();
};

