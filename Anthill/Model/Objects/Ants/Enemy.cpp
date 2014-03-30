#include "Enemy.h"
#include "AntsProperties.h"
#include "..\..\BehaviorOfAnts\KillAllAntsStrategy.h"


Enemy::Enemy(Vector * _position, Anthill * _home) : BaseAnt(_position, ENEMY_SIZE, ENEMY_SPEED, ENEMY_EATING, ENEMY_DEFENCE, _home)
{
	attack = ENEMY_ATTACK;
}


Enemy::~Enemy()
{
}

void Enemy::Update(float  _deltaTime)
{
	BaseAnt::Update(_deltaTime);
	if (wait)
	{
		if (strategy != NULL) delete strategy;
		strategy = new KillAllAntsStrategy(this);
		wait = false;
	}
}
