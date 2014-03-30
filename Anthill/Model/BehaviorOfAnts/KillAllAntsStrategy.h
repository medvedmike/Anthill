#pragma once
#include "..\Objects\Ants\Enemy.h"
#include "..\Objects\Ants\BaseAnt.h"
#include "BaseStrategy.h"

class KillAllAntsStrategy : public BaseStrategy
{
private:
	Enemy* enemy;
	BaseAnt* GetNearAnt();
public:
	KillAllAntsStrategy(Enemy* enemy);
	~KillAllAntsStrategy();
	void Update(float _deltaTime);
};

