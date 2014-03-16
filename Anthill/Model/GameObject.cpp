#include "GameObject.h"
#include "..\Log.h"

GameObject::GameObject(Vector * _position, float _size)
{
	this->position = _position;
	this->size = _size;
}


GameObject::~GameObject()
{
	for (std::vector<OnDestroyObjectListener *>::iterator i = destroyListeners.begin(); i != destroyListeners.end(); i++)
		(*i)->OnDestroyObject(this);
	delete position;
}

Vector * GameObject::Position()
{
	return this->position;
}

void GameObject::Position(Vector * value)
{
	this->position = value;
}

float GameObject::Size()
{
	return this->size;
}

void GameObject::Update(float _deltaTime)
{

}

void GameObject::AddDestroyListener(OnDestroyObjectListener * listener) 
{
	this->destroyListeners.push_back(listener);
}

void GameObject::RemoveDestroyListener(OnDestroyObjectListener * listener)
{
	//TODO need to refractor
	std::vector<OnDestroyObjectListener *>::iterator i = destroyListeners.begin();
	while (i != destroyListeners.end() && listener != *i)
	{
		if (listener == *i)
			i = destroyListeners.erase(i);
		else
			i++;
	}
}
