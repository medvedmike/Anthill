#include "World.h"
#include "Objects\Anthill.h"
#include "GameObject.h"
#include "Objects\ObjectsProperties.h"

void World::InitWorld(int _worldSize)
{
	anthill = new Anthill(Vector::RandomAround(0, 0, _worldSize), ANTHILL_SIZE);
	for (int i = 0; i < 2 + rand() % rand() % 5; i++)
	{
		Vector * p = Vector::RandomAround(0, 0, _worldSize);
		while (p->DistanceTo(anthill->Position()) < anthill->Size() + FOOD_SOURCE_SIZE)
		{
			delete p;
			p = Vector::RandomAround(0, 0, _worldSize);
		}
		foodSourecs.push_back(new FoodSource(p));
	}
	Log::Message("World initialized");
}

Anthill * World::GetAnthill()
{
	return this->anthill;
}

void World::Update(float _deltaTime)
{
	deltaTime = _deltaTime;
	anthill->Update(_deltaTime);
	vector<FoodSource *>::iterator fs = foodSourecs.begin();
	while (fs != foodSourecs.end())
	{
		if ((*fs._Ptr)->getStorage() <= 0)
		{
			FoodSource * dead = *fs._Ptr;
			fs = foodSourecs.erase(fs);
			//delete dead;
		} 
		else
		{
			(*fs._Ptr)->Update(_deltaTime);
			fs++;
		}
	}
}

World::~World()
{
	delete anthill;
}

const vector<FoodSource *> World::GetFoodSources()
{
	return foodSourecs;
}

FoodSource * World::getRandomFoodSource()
{
	return foodSourecs[rand() % foodSourecs.size()];
}

float World::GetDeltaTime()
{
	return deltaTime;
}