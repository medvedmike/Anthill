#include "PatroolStrategy.h"
#include "..\World.h"

PatroolStrategy::PatroolStrategy(BaseAnt * ant)
{
	this->ant = ant;
	ant->targetPoint = Vector::RandomAround(ant->home->Position()->X(), ant->home->Position()->Y(), World::Instance().GetSize());
}


PatroolStrategy::~PatroolStrategy()
{
}

void PatroolStrategy::Update(float _deltaTime)
{
	if (ant->position->DistanceTo(ant->targetPoint) <= ant->size * 2)
	{
		delete ant->targetPoint;
		ant->targetPoint = Vector::RandomAround(ant->home->Position()->X(), ant->home->Position()->Y(), World::Instance().GetSize());
	}
}