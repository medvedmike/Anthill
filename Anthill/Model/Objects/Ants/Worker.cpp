#include "Worker.h"
#include "AntsProperties.h"
#include "..\..\..\Log.h"

Worker::Worker(Vector * _position, Anthill * _home) : BaseAnt(_position, WORKER_SIZE, WORKER_SPEED, WORKER_EATING, WORKER_DEFENCE, _home)
{
	targetPoint = Vector::RandomAround(home->Position()->X(), home->Position()->Y(), home->Size());
}


Worker::~Worker()
{
	Log::Debug("Found dead worker! Slaves are dying!");
}
