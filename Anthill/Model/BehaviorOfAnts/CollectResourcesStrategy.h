#pragma once
#include "WorkerBaseStrategy.h"
#include "..\GameObject.h"

class CollectResourcesStrategy : public WorkerBaseStrategy, OnDestroyObjectListener
{
public:
	CollectResourcesStrategy(Worker * _worker);
	~CollectResourcesStrategy();
	virtual void Update(float _deltaTime);
	virtual void OnDestroyObject(GameObject * obj);
};

