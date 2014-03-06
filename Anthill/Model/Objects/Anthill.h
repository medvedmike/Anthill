#pragma once
#include "Ants\BaseAnt.h"
#include "../GameObject.h"
#include "../Utils/Vector.h"
#include <vector>
#include "FoodStorage.h"
#include "Nest.h"

using namespace std;

class BaseAnt;

class Anthill : public GameObject
{
private:
	vector<BaseAnt *> ants; 
	vector<BaseAnt *> cache;
	FoodStorage * storage;
	Nest * nest;
public:
	Anthill(Vector * pos, float _size);
	~Anthill();
	const vector<BaseAnt *> GetAnts();
	void Update(float _deltaTime);
	FoodStorage * GetStorage();
	Nest * GetNest();
	void AddAnt(BaseAnt * ant);
};

