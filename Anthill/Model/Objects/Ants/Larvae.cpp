#include "Larvae.h"
#include "..\..\..\Log.h"
#include "AntsProperties.h"

Larvae::Larvae(Vector * _position, Anthill * _home) : BaseAnt(_position, LARVAE_SIZE, LARVAE_SPEED, LARVAE_EATING, LARVAE_DEFENCE, _home)
{
	targetPoint = Vector::RandomAround(home->GetNest()->Position()->X(), home->GetNest()->Position()->Y(), home->GetNest()->Size());
	timeToGrown = LARVAE_TIME_TOGROWN;
}


Larvae::~Larvae()
{
	Log::Debug("Larvae was died! Children are dying! Children are dying!");
}

bool Larvae::IsGrowned() 
{
	return timeToGrown <= 0;
}

void Larvae::Update(float _deltaTime)
{
	BaseAnt::Update(_deltaTime);
	timeToGrown -= _deltaTime;
	if (timeToGrown > 0)
	{
		if (wait && targetPoint != NULL && targetPoint->DistanceTo(this->position) <= 2 * size)
		{
			delete targetPoint;
			targetPoint = Vector::RandomAround(home->GetNest()->Position()->X(), home->GetNest()->Position()->Y(), home->GetNest()->Size());
		}
		SetTarget(NULL);
		if (eat)
		{

		}
	}
}
