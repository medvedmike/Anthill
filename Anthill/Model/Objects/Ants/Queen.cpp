#include "Queen.h"
#include "..\..\..\Log.h"

#define QUEEN_SPEED 5
#define QUEEN_EATING 0.05
#define QUEEN_DEFENCE 2


Queen::Queen(Vector * _position, float _size) : BaseAnt(_position, _size, QUEEN_SPEED, QUEEN_EATING, QUEEN_DEFENCE)
{
	Log::Message("Queen created");
}


Queen::~Queen()
{
}
