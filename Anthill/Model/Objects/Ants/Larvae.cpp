#include "Larvae.h"
#include "..\..\..\Log.h"
#include "AntsProperties.h"

Larvae::Larvae(Vector * _position, Anthill * _home) : BaseAnt(_position, LARVAE_SIZE, LARVAE_SPEED, LARVAE_EATING, LARVAE_DEFENCE, _home)
{
	targetPoint = Vector::RandomAround(home->Position()->X(), home->Position()->Y(), home->Size());
}


Larvae::~Larvae()
{
	Log::Debug("Larvae was died! Children are dying! Children are dying!");
}
