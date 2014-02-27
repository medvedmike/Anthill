#include "Anthill.h"
#include "Ants\Queen.h"
#include "..\..\Log.h"

Anthill::Anthill(Vector * _position, float _size) : GameObject(_position, _size)
{
	Queen * queen = new Queen(new Vector(0, 0), 7);
	ants.push_back(queen);
	Log::Message("Anthill created");
}


Anthill::~Anthill()
{
}

const vector<BaseAnt *> Anthill::GetAnts()
{
	return ants;
}