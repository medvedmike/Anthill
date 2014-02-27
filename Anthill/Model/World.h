#pragma once
#include "../Log.h";
#include "Objects\Anthill.h"
class World
{
private:
	World(){ Log::Message("World created"); };
	World(const World& root);
	World& operator=(const World&);

	Anthill * anthill;
public:
	static World& Instance()
	{
		static World instance;
		return instance;
	}
	void InitWorld(int _worldWidth, int _worldHeight);
	void StartSimulate();
	Anthill * GetAnthill();
};

