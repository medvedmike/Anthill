#pragma once
#include "../Model/World.h"

class View
{
private:
	static void Update(int arg);
	static void Draw();
	static void DrawCircle(float x, float y, float r, int segments);
	static void FillCircle(float x, float y, float r, int segments);
	static void DrawAthill(Anthill * anthill);
	static void DrawAnt(BaseAnt * ant);
	static World& world;
public:
	View();
	~View();
	void Initialize(int argc, char * argv[], int width, int height);
	void Start();

};

