#include "BaseAnt.h"
#include "..\..\GameObject.h"
#include "..\..\..\Log.h"
#include "..\Anthill.h"
#include <sstream>
#include "AntsProperties.h"
#include "..\..\BehaviorOfAnts\BaseStrategy.h"
#include "..\..\BehaviorOfAnts\EatingStrategy.h"
#include "..\..\BehaviorOfAnts\WaitingStrategy.h"

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
	this->strategy = NULL;
	this->minSatiety = 0.5f;
}


BaseAnt::~BaseAnt()
{
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
		if (targetObject != NULL && position->DistanceTo(targetObject->Position()) > size + targetObject->Size())
			*direction = *targetObject->Position() - *position;
		else if (targetPoint != NULL && position->DistanceTo(targetPoint) > speed + size)
			*direction = *targetPoint - *position;
		else
			*direction = Vector::zero;
		direction->Normalize();
		*position += *direction * speed * _deltaTime;
		position->Noize();
	}
	if (satiety < minSatiety)
	{
		if (strategy != NULL) delete strategy;
		strategy = new EatingStrategy(this);
	}
	else if (strategy != NULL && typeid(strategy) == typeid(EatingStrategy) && satiety >= 0.95f)
	{
		delete strategy;
		strategy = new WaitingStrategy(this);
	}
	if (strategy != NULL)
		strategy->Update(_deltaTime);
	//std::ostringstream buf;
	//buf << "delta time: " << _deltaTime << " health: " << health << " satiety: " << satiety;
	//Log::Message(buf.str());
}

float BaseAnt::GetHealth()
{
	return health;
}