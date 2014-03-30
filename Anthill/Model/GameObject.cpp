#include "GameObject.h"
#include "..\Log.h"
#include <exception>

GameObject::GameObject(Vector * _position, float _size)
{
	this->position = _position;
	this->size = _size;
}


GameObject::~GameObject()
{
	for (std::vector<OnDestroyObjectListener *>::iterator i = destroyListeners.begin(); i != destroyListeners.end(); i++)
	{
		try
		{
			(*i._Ptr)->OnDestroyObject(this);
		}
		catch (int ex)
		{

		}
	}
	destroyListeners.clear();
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
	if (destroyListeners.size() > 0)
	{
		std::vector<OnDestroyObjectListener *>::iterator i = destroyListeners.begin();
		while (i != destroyListeners.end())
		{
			if (listener == *i._Ptr)
				i = destroyListeners.erase(i);
			else
				i++;
		}
	}
}
