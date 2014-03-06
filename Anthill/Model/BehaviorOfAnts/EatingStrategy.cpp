#include "EatingStrategy.h"
#include "..\Objects\Ants\Larvae.h"
#include "..\..\Log.h"

EatingStrategy::EatingStrategy(BaseAnt * _ant)
{
	ant = _ant;
	Log::Message("New eating strategy");
}


EatingStrategy::~EatingStrategy()
{
}

void EatingStrategy::Update(float _deltaTime)
{
	if (ant->targetObject == NULL)
		ant->targetObject = ant->home->GetStorage();
	if (ant->position->DistanceTo(ant->targetObject->Position()) <= ant->size + ant->targetObject->Size())
		ant->Eat((FoodStorage*)ant->targetObject);


}
