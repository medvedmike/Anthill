#include "BornStrategy.h"
#include "..\Objects\Ants\AntsProperties.h"

BornStrategy::BornStrategy(Queen * _queen) : BaseQueenStrategy(_queen)
{
}


BornStrategy::~BornStrategy()
{
}

void BornStrategy::Update(float _deltaTime)
{

	if (queen->position->DistanceTo(queen->nest->Position()) <= queen->nest->Size())
	{
		queen->BirhLarvaes();
		queen->timeToBorn = QUEEN_TIME_TO_BORN;
	}
}
