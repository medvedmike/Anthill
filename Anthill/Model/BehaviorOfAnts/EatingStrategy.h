#pragma once
#include "BaseStrategy.h"
#include "..\Objects\Ants\BaseAnt.h"

class EatingStrategy : public BaseStrategy
{
private:
	BaseAnt * ant;
public:
	EatingStrategy(BaseAnt * _ant);
	~EatingStrategy();
	void Update(float _deltaTime);
};

