#pragma once
#include "BaseStrategy.h"
#include "..\Objects\Ants\Warrior.h"
#include "..\Objects\Ants\Enemy.h"

class KillEnemiesStrategy : public BaseStrategy
{
private:
	Warrior * warrior;
	Enemy* GetNearEnemy();
public:
	KillEnemiesStrategy(Warrior * warrior);
	~KillEnemiesStrategy();
	void Update(float _deltaTime);
};

