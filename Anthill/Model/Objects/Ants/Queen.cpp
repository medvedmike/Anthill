#include "Queen.h"
#include "..\..\..\Log.h"
#include "..\..\Utils\Vector.h"
#include "AntsProperties.h"


Queen::Queen(Vector * _position, Anthill * _home) : BaseAnt(_position, QUIEEN_SIZE, QUEEN_SPEED, QUEEN_EATING, QUEEN_DEFENCE, _home)
{
	targetPoint = Vector::RandomAround(home->Position()->X(), home->Position()->Y(), home->Size());
}


Queen::~Queen()
{
	Log::Debug("Queen is dead! Bitches! They killed our queen!");
}
