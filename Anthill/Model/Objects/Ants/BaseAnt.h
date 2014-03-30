#pragma once
#include "..\..\GameObject.h"
#include "..\Anthill.h"

class Anthill;
class BaseStrategy;
class EatingStrategy;
class WaitingStrategy;
class PatroolStrategy;
class FoodStorage;

class BaseAnt : public GameObject, OnDestroyObjectListener
{
private:
	GameObject * targetObject;
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
	Anthill * home;
	BaseStrategy * strategy;
	float minSatiety;
	void SetTarget(GameObject* target);
	GameObject * GetTarget();
public:
	BaseAnt(Vector * _position, float _size, float _speed, float _eating, float _defence, Anthill * _home);
	virtual ~BaseAnt();
	void Update(float _deltaTime);
	float GetHealth();
	void Eat(FoodStorage * storage);
	friend EatingStrategy;
	friend WaitingStrategy;
	friend PatroolStrategy;
	virtual void OnDestroyObject(GameObject * obj);
	void Attack(float power);
};

