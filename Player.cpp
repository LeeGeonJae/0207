#include "Player.h"

Player::Player()
{
	X = 0;
	Y = 0;
	Shape = 'P';
}

Player::Player(int NewX, int NewY)
{
	SetActorLocation(NewX, NewY);
	Shape = 'P';
}

Player::~Player()
{
}
