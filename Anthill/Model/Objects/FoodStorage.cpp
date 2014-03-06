#include "FoodStorage.h"
#include "ObjectsProperties.h"
#include "ObjectsProperties.h"

FoodStorage::FoodStorage(Vector * _position) :GameObject(_position, FOOD_STORAGE_SIZE)
{
	store = 0;
}


FoodStorage::~FoodStorage()
{
}

void FoodStorage::PushFood(float *cache)
{
	if (store + *cache > FOOD_STORAGE_MAX_FOOD)
	{
		*cache -= FOOD_STORAGE_MAX_FOOD - store;
		store = FOOD_STORAGE_MAX_FOOD;
	}
	else
	{
		store += *cache;
		*cache = 0;
	}
}

float FoodStorage::GetFood(float cache)
{
	if (store >= cache)
	{
		store -= cache;
		return cache;
	}
	else
	{
		float tmp = store;
		store = 0;
		return tmp;
	}
}

float FoodStorage::GetFill()
{
	return store;	
}
