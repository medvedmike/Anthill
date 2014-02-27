#include "World.h"
#include "Objects\Anthill.h"
#include "GameObject.h"

void World::InitWorld(int _worldWidth, int _worldHeight)
{
	anthill = new Anthill(new Vector(-170, 170), 150);
	Log::Message("World initialized");
}

Anthill * World::GetAnthill()
{
	return this->anthill;
}

void World::Update(float _deltaTime)
{
	anthill->Update(_deltaTime);
}

World::~World()
{
	delete anthill;
}
