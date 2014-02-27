#pragma once
#include "Ants\BaseAnt.h"
#include "../GameObject.h"
#include "../Utils/Vector.h"
#include <vector>

using namespace std;

class BaseAnt;

class Anthill : public GameObject
{
private:
	vector<BaseAnt *> ants; 
public:
	Anthill(Vector * pos, float _size);
	~Anthill();
	const vector<BaseAnt *> GetAnts();
	void Update(float _deltaTime);
};

