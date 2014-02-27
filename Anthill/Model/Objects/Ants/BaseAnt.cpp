#include "BaseAnt.h"
#include "..\..\GameObject.h"

#define MAX_HP 1
#define MAX_SATIETY 1

BaseAnt::BaseAnt(Vector * _position, float _size, float _speed, float _eating, float _defence) : GameObject(_position, _size)
{
	this->speed = _speed;
	this->eating = _eating;
	this->defence = _defence;
	this->health = MAX_HP;
	this->satiety = MAX_SATIETY;
}


BaseAnt::~BaseAnt()
{
}

void BaseAnt::Update()
{
	GameObject::Update();
	satiety -= eating;
	if (satiety < 0) health += satiety;
	if (health < 0) health = 0;
}

float BaseAnt::GetHealth()
{
	return health;
}