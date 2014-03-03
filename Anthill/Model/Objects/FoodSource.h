#pragma once
#include "..\GameObject.h"
#include "..\Utils\Vector.h"
class FoodSource : public GameObject
{
private:
	float storage;
	float timeToGrown;
	float maxFood;
	void GrownUp();
public:
	FoodSource(Vector * _position);
	~FoodSource();
	float getStorage();
	float getFood(float cash, GameObject * source);
	void Update(float _delataTime);
};

