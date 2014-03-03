#include "Worker.h"
#include "AntsProperties.h"
#include "..\..\..\Log.h"
#include "..\..\World.h"
#include "..\ObjectsProperties.h"
#include "..\..\BehaviorOfAnts\CollectResourcesStrategy.h"

Worker::Worker(Vector * _position, Anthill * _home) : BaseAnt(_position, WORKER_SIZE, WORKER_SPEED, WORKER_EATING, WORKER_DEFENCE, _home)
{
	targetPoint = Vector::RandomAround(home->Position()->X(), home->Position()->Y(), home->Size());
	foodSource = NULL;
	cache = 0;
	strategy = new CollectResourcesStrategy(this);
}

void Worker::Update(float _deltaTime)
{
	BaseAnt::Update(_deltaTime);	
}

Worker::~Worker()
{
	Log::Debug("Found dead worker! Slaves are dying!");
}
