#include "Warrior.h"
#include "AntsProperties.h"
#include "..\..\..\Log.h"

Warrior::Warrior(Vector * _position, Anthill * _home) : BaseAnt(_position, WARRIOR_SIZE, WARRIOR_SPEED, WARRIOR_EATING, WARRIOR_DEFENCE, _home)
{
	targetPoint = Vector::RandomAround(home->Position()->X(), home->Position()->Y(), home->Size());
}


Warrior::~Warrior()
{
	Log::Debug("Soldier is dead! We must avenge this!");
}
