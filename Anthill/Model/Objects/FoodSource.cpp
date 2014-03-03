#include "FoodSource.h"
#include "ObjectsProperties.h"
#include "..\..\Log.h"

FoodSource::FoodSource(Vector * _position) : GameObject(_position, FOOD_SOURCE_SIZE)
{
	storage = FOOD_SOURCE_SIZE * FOOD_SOURCE_STORAGE_FACTOR;
	timeToGrown = FOOD_SOURCE_TIME_TO_GROWN;
	maxFood = storage;
}


FoodSource::~FoodSource()
{
	Log::Debug("Food source were dwindled");
}

float FoodSource::getStorage()
{
	return storage;
}

float FoodSource::getFood(float cash, GameObject * source)
{
	if (storage > 0 && position->DistanceTo(source->Position()) <= size + source->Size() + FOOD_SOURCE_AREA)
	{
		if (storage < cash)
			cash = storage;
		storage -= cash;
		return cash;
	}
	return 0;
}

void FoodSource::GrownUp() 
{
	if (size < FOOD_SOURCE_MAX_SIZE)
	{
		Log::Debug("Grown up!");
		size += FOOD_SOURCE_GROW_VALUE;
		size > FOOD_SOURCE_MAX_SIZE ? FOOD_SOURCE_MAX_SIZE : size;
		maxFood = size * FOOD_SOURCE_STORAGE_FACTOR;
		timeToGrown = FOOD_SOURCE_TIME_TO_GROWN;	
	}
}

void FoodSource::Update(float _delataTime)
{
	if (storage + FOOD_SOURCE_REPAIR * _delataTime < maxFood)
		storage += FOOD_SOURCE_REPAIR * _delataTime;
	else
		storage = maxFood;
	timeToGrown -= _delataTime; 
	if (timeToGrown <= 0)
		GrownUp();
}