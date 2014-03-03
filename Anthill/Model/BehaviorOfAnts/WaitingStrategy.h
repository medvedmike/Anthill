#pragma once
#include "BaseStrategy.h"
#include "..\Objects\Ants\BaseAnt.h"

class WaitingStrategy : public BaseStrategy
{
private:
	BaseAnt * ant;
public:
	WaitingStrategy(BaseAnt * _ant);
	~WaitingStrategy();
	void Update(float _deltaTime);
};

