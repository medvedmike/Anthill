#include "WaitingStrategy.h"
#include "..\..\Log.h"
#include <sstream>


WaitingStrategy::WaitingStrategy(BaseAnt * _ant)
{
	Log::Message("New Waiting");
	ant = _ant;
	if (ant->targetPoint == NULL) ant->targetPoint = Vector::RandomAround(ant->home->Position()->X(), ant->home->Position()->Y(), ant->home->Size());
}


WaitingStrategy::~WaitingStrategy()
{
}

void WaitingStrategy::Update(float _deltaTime)
{
	//std::ostringstream buf;
	//buf << "size + speed " << ant->size * 2 << " dist " << ant->position->DistanceTo(ant->targetPoint) << " size " << ant->size;
	//Log::Message(buf.str());
	if (ant->position->DistanceTo(ant->targetPoint) <= ant->size * 2)
	{
		delete ant->targetPoint;
		ant->targetPoint = Vector::RandomAround(ant->home->Position()->X(), ant->home->Position()->Y(), ant->home->Size());
	}
}
