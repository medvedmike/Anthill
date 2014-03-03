#pragma once
#include "..\GameObject.h"

class FoodStorage : public GameObject
{
private: 
	float store;
public:
	FoodStorage(Vector * _position);
	~FoodStorage();
	void PushFood(float *cache);
	float GetFood(float cache);
	float GetFill();
};

