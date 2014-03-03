#include "CollectResourcesStrategy.h"
#include "..\..\Log.h"
#include "..\World.h"
#include "..\Objects\Ants\AntsProperties.h"
#include "..\Objects\ObjectsProperties.h"

CollectResourcesStrategy::CollectResourcesStrategy(Worker * _worker) : WorkerBaseStrategy(_worker)
{
}


CollectResourcesStrategy::~CollectResourcesStrategy()
{
}

void CollectResourcesStrategy::Update(float _deltaTime)
{
	if (worker->foodSource == NULL)
		worker->foodSource = World::Instance().getRandomFoodSource();
	if (worker->cache == 0)
	{
		if (worker->targetObject != worker->foodSource)
			worker->targetObject = worker->foodSource;
		if (worker->position->DistanceTo(worker->foodSource->Position()) < worker->size + worker->foodSource->Size() + FOOD_SOURCE_AREA)
		{
			worker->cache = worker->foodSource->getFood(WORKER_CASH_SIZE - worker->cache, worker);
			if (worker->cache < WORKER_CASH_SIZE)
				worker->targetObject = worker->foodSource = World::Instance().getRandomFoodSource();
			else
				worker->targetObject = worker->home->GetStorage();
		}
	}
	else
	{
		FoodStorage * storage = worker->home->GetStorage();
		if (worker->position->DistanceTo(storage->Position()) < worker->size + storage->Size() + FOOD_SOURCE_AREA)
		{
			storage->PushFood(&worker->cache);
		}
	}
}