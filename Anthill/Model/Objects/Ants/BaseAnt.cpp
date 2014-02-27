#include "BaseAnt.h"
#include "..\..\GameObject.h"
#include "..\..\..\Log.h"
#include <sstream>

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

void BaseAnt::Update(float _deltaTime)
{
	GameObject::Update(_deltaTime);
	satiety -= eating * _deltaTime;
	if (satiety < 0) health += satiety * _deltaTime;
	if (health < 0) health = 0;
	//std::ostringstream buf;
	//buf << "delta time: " << _deltaTime << " health: " << health << " satiety: " << satiety;
	//Log::Message(buf.str());
}

float BaseAnt::GetHealth()
{
	return health;
}