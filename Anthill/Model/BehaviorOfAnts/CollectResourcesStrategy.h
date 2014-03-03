#pragma once
#include "WorkerBaseStrategy.h"

class CollectResourcesStrategy : public WorkerBaseStrategy
{
public:
	CollectResourcesStrategy(Worker * _worker);
	~CollectResourcesStrategy();
	virtual void Update(float _deltaTime);
};

