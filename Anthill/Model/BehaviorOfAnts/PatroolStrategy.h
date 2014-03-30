#pragma once
#include "BaseStrategy.h"
#include "..\Objects\Ants\BaseAnt.h"

class PatroolStrategy : public BaseStrategy
{
private: 
	BaseAnt * ant;
public:
	PatroolStrategy(BaseAnt * ant);
	~PatroolStrategy();
	void Update(float _deltaTime);
};

