#include "Goal.h"

Goal::Goal()
{
	X = 0;
	Y = 0;
	Shape = 'G';
}

Goal::Goal(int NewX, int NewY)
{
	SetActorLocation(NewX, NewY);
	Shape = 'G';
}

Goal::~Goal()
{
}
