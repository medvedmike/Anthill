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
	worker->SetTarget(NULL);
}


void CollectResourcesStrategy::CollectResources()
{
	if (worker->GetTarget() == NULL)
		worker->SetTarget(World::Instance().getRandomFoodSource());
	if (worker->GetTarget() != NULL)
	{
		if (worker->position->DistanceTo(worker->GetTarget()->Position()) <
			worker->size + worker->GetTarget()->Size() + FOOD_SOURCE_AREA)
		{
			if (typeid(*worker->GetTarget()) == typeid(FoodSource))
				worker->cache += ((FoodSource*)worker->GetTarget())->getFood(WORKER_CASH_SIZE - worker->cache, worker);
		}
	}
	if (worker->cache >= WORKER_CASH_SIZE)
		worker->SetTarget(NULL);
}

void CollectResourcesStrategy::StoreResources()
{
	if (worker->GetTarget() == NULL)
		worker->SetTarget(worker->home->GetStorage());
	if (worker->GetTarget() != NULL)
	{
		if (worker->position->DistanceTo(worker->GetTarget()->Position()) <
			worker->size + worker->GetTarget()->Size() + FOOD_SOURCE_AREA)
		{
			if (typeid(*worker->GetTarget()) == typeid(FoodStorage))
				((FoodStorage*)worker->GetTarget())->PushFood(&worker->cache);
		}
	}
	if (worker->cache < WORKER_CASH_SIZE)
		worker->SetTarget(NULL);
}

void CollectResourcesStrategy::Update(float _deltaTime)
{

	if (worker->cache < WORKER_CASH_SIZE)
		CollectResources();
	else
		StoreResources();
}