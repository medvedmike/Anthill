#include "BaseAnt.h"
#include "..\..\GameObject.h"
#include "..\..\..\Log.h"
#include "..\Anthill.h"
#include <sstream>

#define MAX_HP 1
#define MAX_SATIETY 1

BaseAnt::BaseAnt(Vector * _position, float _size, float _speed, float _eating, float _defence, Anthill * _home) : GameObject(_position, _size)
{
	this->home = _home;
	this->speed = _speed;
	this->eating = _eating;
	this->defence = _defence;
	this->health = MAX_HP;
	this->satiety = MAX_SATIETY;
	targetPoint = new Vector();
	direction = new Vector();
	*this->targetPoint = *_position;
	this->targetObject = NULL;
}


BaseAnt::~BaseAnt()
{
	delete position;
	delete direction;
	delete targetPoint;
}

void BaseAnt::Update(float _deltaTime)
{
	std::ostringstream buf;
	GameObject::Update(_deltaTime);
	satiety -= eating * _deltaTime;
	if (satiety < 0) health += satiety * _deltaTime;
	if (health < 0) health = 0;
	if (health > 0)
	{
		if (*targetPoint != *position) {
			*direction = *targetPoint - *position;
			direction->Normalize();
		}
		float distance = position->DistanceTo(targetPoint);
		if (distance > speed + size)
		{
			float multipler = speed * _deltaTime;
			Vector newPos = *direction * multipler;
			*position += newPos;
		}
		else
		{
			Log::Message("is arrived at destination");
			*direction = *position;
			Vector * oldTarget = targetPoint;
			targetPoint = Vector::RandomAround(home->Position()->X(), home->Position()->Y(), home->Size());
			delete oldTarget;
		}
	}
	//std::ostringstream buf;
	//buf << "delta time: " << _deltaTime << " health: " << health << " satiety: " << satiety;
	//Log::Message(buf.str());
}

float BaseAnt::GetHealth()
{
	return health;
}