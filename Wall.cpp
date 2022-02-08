#include "Wall.h"

Wall::Wall()
{
	X = 0;
	Y = 0;
	Shape = '*';
	Color.r = 0x80;
	Color.g = 0x3A;
	Color.b = 0x0A;
	Color.a = 0xff;
}

Wall::Wall(int NewX, int NewY)
{
	SetActorLocation(NewX, NewY);
	Shape = '*';
	Color.r = 0x80;
	Color.g = 0x3A;
	Color.b = 0x0A;
	Color.a = 0xff;
}

Wall::~Wall()
{

}

void Wall::Render(SDL_Renderer* MyRenderer)
{
	Actor::Render(MyRenderer);
}
