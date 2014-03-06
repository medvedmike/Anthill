#pragma once
#include "..\..\GameObject.h"
#include "..\Anthill.h"

class Anthill;
class BaseStrategy;
class EatingStrategy;
class WaitingStrategy;
class FoodStorage;

class BaseAnt : public GameObject
{
protected:
	float health;
	float speed;
	float defence;
	float eating;
	float satiety;
	bool eat;
	bool wait;
	Vector * targetPoint;
	Vector * direction;
	GameObject * targetObject;
	Anthill * home;
	BaseStrategy * strategy;
	float minSatiety;
public:
	BaseAnt(Vector * _position, float _size, float _speed, float _eating, float _defence, Anthill * _home);
	virtual ~BaseAnt();
	void Update(float _deltaTime);
	float GetHealth();
	void Eat(FoodStorage * storage);
	friend EatingStrategy;
	friend WaitingStrategy;
};

