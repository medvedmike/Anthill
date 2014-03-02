#include "Larvae.h"
#include "..\..\..\Log.h"

#define LARVAE_SPEED 5
#define LARVAE_EATING 0.08f
#define LARVAE_DEFENCE 0.5f

Larvae::Larvae(Vector * _position, float _size, Anthill * _home) : BaseAnt(_position, _size, LARVAE_SPEED, LARVAE_EATING, LARVAE_DEFENCE, _home)
{
	targetPoint = Vector::RandomAround(home->Position()->X(), home->Position()->Y(), home->Size());
}


Larvae::~Larvae()
{
	Log::Debug("Larvae was died");
}
