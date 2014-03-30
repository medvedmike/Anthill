#include "KillEnemiesStrategy.h"
#include "..\Objects\Ants\Enemy.h"
#include "..\World.h"

KillEnemiesStrategy::KillEnemiesStrategy(Warrior * warrior)
{
	this->warrior = warrior;
}


KillEnemiesStrategy::~KillEnemiesStrategy()
{
}

void KillEnemiesStrategy::Update(float _deltaTime)
{
	if (warrior->GetTarget() == NULL)
	{
		warrior->SetTarget(GetNearEnemy());
	}
	else
	{
		if (warrior->Position()->DistanceTo(warrior->GetTarget()->Position()) <= warrior->Size() + warrior->GetTarget()->Size())
		{
			//if (typeid(*enemy->GetTarget()) == typeid(BaseAnt))
			//{
			((BaseAnt*)warrior->GetTarget())->Attack(warrior->attack);
			//}
		}
	}
}

Enemy* KillEnemiesStrategy::GetNearEnemy()
{
	float dist = INFINITY;
	Enemy* ant = NULL;
	for (int i = 0; i < World::Instance().GetEnemies().size(); i++)
	{
		if (World::Instance().GetEnemies()[i]->Position()->DistanceTo(warrior->Position()) < dist)
		{
			dist = World::Instance().GetEnemies()[i]->Position()->DistanceTo(warrior->Position());
			ant = World::Instance().GetEnemies()[i];
		}
	}
	return ant;
}