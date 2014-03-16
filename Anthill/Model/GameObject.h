#pragma once
#include "Utils\Vector.h"
#include <vector>

class GameObject;

class OnDestroyObjectListener
{
public:
	virtual void OnDestroyObject(GameObject * obj) = NULL;
};

class GameObject
{
protected:
	Vector * position;
	float size;
private:
	std::vector<OnDestroyObjectListener *> destroyListeners;
public:
	GameObject(Vector * _position, float _size);
	virtual ~GameObject();
	Vector * Position();
	void Position(Vector * value);
	float Size();
	virtual void Update(float _deltaTime);
	void AddDestroyListener(OnDestroyObjectListener * listener);
	void RemoveDestroyListener(OnDestroyObjectListener * listener);
};

