#include "Anthill.h"
#include "Ants\Queen.h"
#include "..\..\Log.h"
#include "Ants\Larvae.h"
#include "Ants\Policeman.h"
#include "Ants\Worker.h"
#include "Ants\Warrior.h"
#include <sstream>

Anthill::Anthill(Vector * _position, float _size) : GameObject(_position, _size)
{
	storage = new FoodStorage(Vector::RandomAround(position->X(), position->Y(), size));
	nest = new Nest(Vector::RandomAround(position->X(), position->Y(), size));

	queen = new Queen(Vector::RandomAround(position->X(), position->Y(), size), this);
	ants.push_back(queen);

	//ants.push_back(new Larvae(Vector::RandomAround(position->X(), position->Y(), size), this));
	//ants.push_back(new Larvae(Vector::RandomAround(position->X(), position->Y(), size), this));
	//ants.push_back(new Larvae(Vector::RandomAround(position->X(), position->Y(), size), this));
	//ants.push_back(new Larvae(Vector::RandomAround(position->X(), position->Y(), size), this));
	//ants.push_back(new Larvae(Vector::RandomAround(position->X(), position->Y(), size), this));
	//ants.push_back(new Larvae(Vector::RandomAround(position->X(), position->Y(), size), this));
	//ants.push_back(new Larvae(Vector::RandomAround(position->X(), position->Y(), size), this));
	//ants.push_back(new Larvae(Vector::RandomAround(position->X(), position->Y(), size), this));

	//ants.push_back(new Policeman(Vector::RandomAround(position->X(), position->Y(), size), this));
	//ants.push_back(new Policeman(Vector::RandomAround(position->X(), position->Y(), size), this));
	//ants.push_back(new Policeman(Vector::RandomAround(position->X(), position->Y(), size), this));
	//ants.push_back(new Policeman(Vector::RandomAround(position->X(), position->Y(), size), this));

	ants.push_back(new Worker(Vector::RandomAround(position->X(), position->Y(), size), this));
	ants.push_back(new Worker(Vector::RandomAround(position->X(), position->Y(), size), this));
	ants.push_back(new Worker(Vector::RandomAround(position->X(), position->Y(), size), this));
	ants.push_back(new Worker(Vector::RandomAround(position->X(), position->Y(), size), this));
	ants.push_back(new Worker(Vector::RandomAround(position->X(), position->Y(), size), this));

	//ants.push_back(new Warrior(Vector::RandomAround(position->X(), position->Y(), size), this));
	//ants.push_back(new Warrior(Vector::RandomAround(position->X(), position->Y(), size), this));
	//ants.push_back(new Warrior(Vector::RandomAround(position->X(), position->Y(), size), this));

	std::ostringstream buf;
	buf << "Anthilll created at (" << position->X() << ";" << position->Y() << ") with size=" << size;
	Log::Message(buf.str());
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

const vector<Larvae *> Anthill::GetLarvaes() 
{
	return larvaes;
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
	vector<Larvae *>::iterator li = larvaes.begin();
	while (li != larvaes.end())
	{
		(*li._Ptr)->Update(_deltaTime);
		if ((*li._Ptr)->GetHealth() <= 0)
		{
			BaseAnt * ant = *li._Ptr;
			li = larvaes.erase(li);
			delete ant;
		}
		else
		{
			if ((*li._Ptr)->IsGrowned())
			{				
				BaseAnt * ant = *li._Ptr;
				Hatch(ant->Position());
				li = larvaes.erase(li);
				delete ant;
			}
			else
				li++;
		}
	}
	/*for (vector<BaseAnt *>::iterator tmp = cache.begin(); tmp != cache.end(); tmp++)
		ants.push_back(*tmp._Ptr);
	cache.clear();*/
}

FoodStorage * Anthill::GetStorage()
{
	return storage;
}

Nest * Anthill::GetNest()
{
	return nest;
}

void Anthill::AddAnt(Larvae * ant)
{
	larvaes.push_back(ant);
}

void Anthill::Hatch(Vector * pos) 
{
	switch (queen->ChooseAnt())
	{
	case 0:
	case 1:
	case 2:
		ants.push_back(new Worker(new Vector(pos->X(), pos->Y()), this));
		break;
	case 3:
	case 4:
		ants.push_back(new Warrior(new Vector(pos->X(), pos->Y()), this));
		break;
	case 5:
		ants.push_back(new Policeman(new Vector(pos->X(), pos->Y()), this));
		break;
	default:
		break;
	}
}