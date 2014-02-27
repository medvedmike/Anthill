#include "Queen.h"
#include "..\..\..\Log.h"
#include "..\..\Utils\Vector.h"

#define QUEEN_SPEED 25
#define QUEEN_EATING 0.05
#define QUEEN_DEFENCE 2


Queen::Queen(Vector * _position, float _size, Anthill * _home) : BaseAnt(_position, _size, QUEEN_SPEED, QUEEN_EATING, QUEEN_DEFENCE, _home)
{
	targetPoint = Vector::RandomAround(home->Position()->X(), home->Position()->Y(), home->Size());
}


Queen::~Queen()
{
	Log::Debug("Queen is dead!! ahahaha");
}
