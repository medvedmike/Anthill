#include "Warrior.h"
#include "AntsProperties.h"
#include "..\..\..\Log.h"
#include "..\..\BehaviorOfAnts\KillEnemiesStrategy.h"
#include "..\..\World.h"
#include "..\..\BehaviorOfAnts\PatroolStrategy.h"

Warrior::Warrior(Vector * _position, Anthill * _home) : BaseAnt(_position, WARRIOR_SIZE, WARRIOR_SPEED, WARRIOR_EATING, WARRIOR_DEFENCE, _home)
{
	attack = WARRIOR_ATTACK;
	attacking = false;
	targetPoint = Vector::RandomAround(home->Position()->X(), home->Position()->Y(), home->Size());
}


Warrior::~Warrior()
{
	Log::Debug("Soldier is dead! We must avenge this!");
}

void Warrior::Update(float  _deltaTime)
{
	BaseAnt::Update(_deltaTime);
	if (wait)
	{
		if (World::Instance().GetEnemies().size() > 0)
		{
			if (strategy != NULL) delete strategy;
			strategy = new KillEnemiesStrategy(this);
			attacking = true;
		}
		else if (attacking)
		{
			if (strategy != NULL) delete strategy;
			strategy = new PatroolStrategy(this);
			attacking = false;
		}
	}
}