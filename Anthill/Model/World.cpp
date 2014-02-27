#include "World.h"
#include "Objects\Anthill.h"
#include "GameObject.h"

void World::StartSimulate()
{
	Log::Message("Simulation started");
}

void World::InitWorld(int _worldWidth, int _worldHeight)
{
	anthill = new Anthill(new Vector(-170, 170), 150);
	Log::Message("World initialized");
}

Anthill * World::GetAnthill()
{
	return this->anthill;
}
