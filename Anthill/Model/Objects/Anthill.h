#pragma once
#include "Ants\BaseAnt.h"
#include "../GameObject.h"
#include "../Utils/Vector.h"
#include <vector>
#include "FoodStorage.h"
#include "Nest.h"

using namespace std;

class BaseAnt;
class Queen;
class Larvae;

class Anthill : public GameObject
{
private:
	vector<BaseAnt *> ants; 
	vector<Larvae *> larvaes;
	vector<BaseAnt *> cache;
	FoodStorage * storage;
	Nest * nest;
	Queen * queen;
	void Hatch(Vector * pos);
public:
	Anthill(Vector * pos, float _size);
	~Anthill();
	const vector<BaseAnt *> GetAnts();
	const vector<Larvae *> GetLarvaes();
	void Update(float _deltaTime);
	FoodStorage * GetStorage();
	Nest * GetNest();
	void AddAnt(Larvae * ant);
};

