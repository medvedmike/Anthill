#include "Policeman.h"
#include "AntsProperties.h"
#include "..\..\..\Log.h"


Policeman::Policeman(Vector * _position, Anthill * _home) : BaseAnt(_position, POLICEMAN_SIZE, POLICEMAN_SPEED, POLICEMAN_EATING, POLICEMAN_DEFENCE, _home)
{
	targetPoint = Vector::RandomAround(home->Position()->X(), home->Position()->Y(), home->Size());
}


Policeman::~Policeman()
{
	Log::Debug("Policeman is dead! Long live anarchy in anthill!");
}
