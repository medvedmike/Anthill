#pragma once
#include "BaseStrategy.h"
#include "..\Objects\Ants\Worker.h"

class Worker;

class WorkerBaseStrategy : public BaseStrategy
{
protected:
	Worker * worker;
public:
	WorkerBaseStrategy(Worker * _worker);
	virtual ~WorkerBaseStrategy();
};

