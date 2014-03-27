#pragma once
#include "BaseAnt.h"

class BornStrategy;

class Queen : public BaseAnt
{
private:
	float timeToBorn;
	bool born;
	Nest * nest;
public:
	Queen(Vector * _position, Anthill * _home);
	~Queen();
	void Update(float _deltaTime);
	void BirhLarvaes();
	friend BornStrategy;
	int ChooseAnt();
};

