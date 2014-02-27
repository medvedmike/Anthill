#include "GameObject.h"
#include "..\Log.h"

GameObject::GameObject(Vector * _position, float _size)
{
	this->position = _position;
	this->size = _size;
}


GameObject::~GameObject()
{
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
