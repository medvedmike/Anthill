#pragma once
#include "BaseAnt.h"
#include "..\FoodSource.h"
#include "..\..\BehaviorOfAnts\WorkerBaseStrategy.h"

class CollectResourcesStrategy;

class Worker : public BaseAnt
{
private:
	FoodSource * foodSource;
	float cache;
public:
	Worker(Vector * _position, Anthill * _home);
	~Worker();
	void Update(float _deltaTime);
	friend CollectResourcesStrategy;
};

