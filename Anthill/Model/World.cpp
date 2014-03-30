#include "World.h"
#include "Objects\Anthill.h"
#include "GameObject.h"
#include "Objects\ObjectsProperties.h"
#include <sstream>

void World::InitWorld(int _worldSize)
{
	worldSize = _worldSize;
	anthill = new Anthill(Vector::RandomAround(0, 0, _worldSize), ANTHILL_SIZE);
	for (int i = 0; i < 2 + rand() % 10; i++)
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
	std::ostringstream buf;
	deltaTime = _deltaTime;

	if (rand() % 560 == 100)
	{
		for (int i = 0; i < rand() % 3; i++)
			enemies.push_back(new Enemy(Vector::RandomAround(0, 0, worldSize), anthill));
	}

	vector<Enemy *>::iterator en = enemies.begin();
	while (en != enemies.end())
	{
		if ((*en._Ptr)->GetHealth() <= 0)
		{
			Enemy * dead = *en._Ptr;
			en = enemies.erase(en);
			delete dead;
		}
		else
		{
			(*en._Ptr)->Update(_deltaTime);
			en++;
		}
	}

	anthill->Update(_deltaTime);

	vector<FoodSource *>::iterator fs = foodSourecs.begin();
	while (fs != foodSourecs.end())
	{
		if ((*fs._Ptr)->getStorage() <= 0)
		{
			buf << "delete food source " << foodSourecs.size() << " ";
			FoodSource * dead = *fs._Ptr;
			fs = foodSourecs.erase(fs);
			delete dead;
			buf << foodSourecs.size() << std::endl;
			Log::Debug(buf.str());
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

const vector<Enemy *> World::GetEnemies()
{
	return enemies;
}

FoodSource * World::getRandomFoodSource()
{
	if (foodSourecs.size() > 0)
		return foodSourecs[rand() % foodSourecs.size()];
	else
		return NULL;
}

float World::GetDeltaTime()
{
	return deltaTime;
}

float World::GetSize()
{
	return worldSize;
}