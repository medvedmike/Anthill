#include "KillAllAntsStrategy.h"
#include "..\Objects\Ants\BaseAnt.h"
#include "..\GameObject.h"
#include <typeinfo>


KillAllAntsStrategy::KillAllAntsStrategy(Enemy* enemy)
{
	this->enemy = enemy;
}


KillAllAntsStrategy::~KillAllAntsStrategy()
{
}

void KillAllAntsStrategy::Update(float _deltaTime)
{
	if (enemy->GetTarget() == NULL)
	{
		enemy->SetTarget(GetNearAnt());
	}
	else
	{
		if (enemy->Position()->DistanceTo(enemy->GetTarget()->Position()) <= enemy->Size() + enemy->GetTarget()->Size())
		{
			//if (typeid(*enemy->GetTarget()) == typeid(BaseAnt))
			//{
				((BaseAnt*)enemy->GetTarget())->Attack(enemy->attack);
			//}
		}
	}
}

BaseAnt* KillAllAntsStrategy::GetNearAnt()
{
	float dist = INFINITY;
	BaseAnt* ant = NULL;
	for (int i = 0; i < enemy->home->GetAnts().size(); i++)
	{
		if (enemy->home->GetAnts()[i]->Position()->DistanceTo(enemy->Position()) < dist)
		{
			dist = enemy->home->GetAnts()[i]->Position()->DistanceTo(enemy->Position());
			ant = enemy->home->GetAnts()[i];
		}
	}
	return ant;
}