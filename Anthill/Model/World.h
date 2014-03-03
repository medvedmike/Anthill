#pragma once
#include "../Log.h";
#include "Objects\Anthill.h"
#include <vector>
#include "Objects\FoodSource.h"
class World
{
private:
	World(){ Log::Message("World created"); };
	World(const World& root);
	World& operator=(const World&);
	~World();
	Anthill * anthill;
	vector<FoodSource*> foodSourecs;
public:
	static World& Instance()
	{
		static World instance;
		return instance;
	}
	void InitWorld(int _worldSize);
	void Update(float _deltaTime);
	Anthill * GetAnthill();
	const vector<FoodSource *> GetFoodSources();
	FoodSource * getRandomFoodSource();
};

