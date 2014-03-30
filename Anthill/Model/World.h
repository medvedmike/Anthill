#pragma once
#include "..\Log.h";
#include "Objects\Anthill.h"
#include <vector>
#include "Objects\FoodSource.h"
#include "Objects\Ants\Enemy.h"

class World
{
private:
	World(){ Log::Message("World created"); deltaTime = 0; };
	World(const World& root);
	World& operator=(const World&);
	~World();
	Anthill * anthill;
	vector<FoodSource*> foodSourecs;
	vector<Enemy*> enemies;
	float deltaTime;
	float worldSize;
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
	const vector<Enemy *> GetEnemies();
	FoodSource * getRandomFoodSource();
	float GetDeltaTime();
	float GetSize();
};

