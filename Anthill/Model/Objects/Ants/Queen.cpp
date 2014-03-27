#include "Queen.h"
#include "..\..\..\Log.h"
#include "..\..\Utils\Vector.h"
#include "AntsProperties.h"
#include "..\..\BehaviorOfAnts\BornStrategy.h"
#include "..\..\BehaviorOfAnts\WaitingStrategy.h"
#include "Larvae.h"


Queen::Queen(Vector * _position, Anthill * _home) : BaseAnt(_position, QUIEEN_SIZE, QUEEN_SPEED, QUEEN_EATING, QUEEN_DEFENCE, _home)
{
	targetPoint = Vector::RandomAround(home->Position()->X(), home->Position()->Y(), home->Size());
	timeToBorn = QUEEN_TIME_TO_BORN;
	nest = home->GetNest();
	born = false;
}


Queen::~Queen()
{
	Log::Debug("Queen is dead! Bitches! They killed our queen!");
}

void Queen::Update(float _deltaTime)
{
	BaseAnt::Update(_deltaTime);
	if (timeToBorn == QUEEN_TIME_TO_BORN)
	{
		Log::Message("Was born");
		if (strategy != NULL) delete strategy;
		targetObject = NULL;
		targetPoint = NULL;
		strategy = new WaitingStrategy(this);
		wait = true;
	}
	if (timeToBorn > 0)
	{
		timeToBorn -= _deltaTime;
	}
	else if (wait)
	{
		Log::Message("Want born");
		if (strategy != NULL) delete strategy;
		targetObject = NULL;
		*targetPoint = *nest->Position();
		strategy = new BornStrategy(this);
		wait = false;
	}
}

void Queen::BirhLarvaes()
{
	if (position->DistanceTo(home->GetNest()->Position()) <= nest->Size())
	{
		for (int i = 0; i < QUEEN_MAX_LARVAES*this->satiety; i++)
		{
			Vector * pos = new Vector();
			*pos = *this->position;
			home->AddAnt(new Larvae(pos, this->home));
		}
	}
}

int Queen::ChooseAnt()
{
	return rand() % 6;
}