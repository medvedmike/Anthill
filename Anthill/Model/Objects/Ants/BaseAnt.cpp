#include "BaseAnt.h"
#include "..\..\GameObject.h"
#include "..\..\..\Log.h"
#include "..\Anthill.h"
#include <sstream>
#include "AntsProperties.h"
#include "..\..\BehaviorOfAnts\BaseStrategy.h"
#include "..\..\BehaviorOfAnts\EatingStrategy.h"
#include "..\..\BehaviorOfAnts\WaitingStrategy.h"
#include "..\..\World.h"

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
	this->strategy = new WaitingStrategy(this);
	this->minSatiety = 0.5f;
	this->eat = false;
	this->wait = true;
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
		{
			const Vector * n = *targetObject->Position() - *position;
			*direction =*n;
			delete n;
		}
		else if (targetPoint != NULL && position->DistanceTo(targetPoint) > 2 * size)
		{
			const Vector * n = *targetPoint - *position;
			*direction = *n;
			delete n;
		}
		else
			*direction = Vector::zero;
		direction->Normalize();
		const Vector * n = (*direction * (speed * _deltaTime));
		*position += *n;
		delete n;
		position->Noize();
	}
	if (satiety < minSatiety && !eat)
	{
		if (strategy != NULL) delete strategy;
		targetObject = NULL;
		strategy = new EatingStrategy(this);
		eat = true;
		wait = false;
	}
	else if (eat && satiety >= 0.95f)
	{
		if (strategy != NULL) delete strategy;
		targetObject = NULL;
		strategy = new WaitingStrategy(this);
		eat = false;
		wait = true;
	}
	if (strategy != NULL)
		strategy->Update(_deltaTime);
	//std::ostringstream buf;
	//buf << "delta time: " << _deltaTime << " health: " << health << " satiety: " << satiety;
	//Log::Message(buf.str());
}

void BaseAnt::Eat(FoodStorage * storage)
{
	if (satiety < MAX_SATIETY - ANT_EAT)
		satiety += storage->GetFood(ANT_EAT) * EAT_HELPFULNESS;
	/*std::ostringstream str;
	str << satiety << "   " << ANT_EAT;
	Log::Debug(str.str());*/
}

float BaseAnt::GetHealth()
{
	return health;
}