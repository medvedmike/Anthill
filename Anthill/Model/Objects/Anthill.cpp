#include "Anthill.h"
#include "Ants\Queen.h"
#include "..\..\Log.h"
#include "..\Objects\Ants\Larvae.h"

Anthill::Anthill(Vector * _position, float _size) : GameObject(_position, _size)
{
	Queen * queen = new Queen(Vector::RandomAround(position->X(), position->Y(), size), 7, this);
	ants.push_back(queen);
	ants.push_back(new Larvae(Vector::RandomAround(position->X(), position->Y(), size), 2, this));
	ants.push_back(new Larvae(Vector::RandomAround(position->X(), position->Y(), size), 2, this));
	ants.push_back(new Larvae(Vector::RandomAround(position->X(), position->Y(), size), 2, this));
	ants.push_back(new Larvae(Vector::RandomAround(position->X(), position->Y(), size), 2, this));
	ants.push_back(new Larvae(Vector::RandomAround(position->X(), position->Y(), size), 2, this));
	ants.push_back(new Larvae(Vector::RandomAround(position->X(), position->Y(), size), 2, this));
	ants.push_back(new Larvae(Vector::RandomAround(position->X(), position->Y(), size), 2, this));
	ants.push_back(new Larvae(Vector::RandomAround(position->X(), position->Y(), size), 2, this));
	Log::Message("Anthill created");
}


Anthill::~Anthill()
{
	vector<BaseAnt *>::iterator i = ants.begin();
	while (i != ants.end())
	{
			BaseAnt * ant = *i._Ptr;
			i = ants.erase(i);
			delete ant;
	}
}

const vector<BaseAnt *> Anthill::GetAnts()
{
	return ants;
}

void Anthill::Update(float _deltaTime)
{
	vector<BaseAnt *>::iterator i = ants.begin(); 
	while (i != ants.end())
	{
		(*i._Ptr)->Update(_deltaTime);
		if ((*i._Ptr)->GetHealth() <= 0)
		{
			BaseAnt * ant = *i._Ptr;
			i = ants.erase(i);
			delete ant;
		}
		else
			i++;
	}
}