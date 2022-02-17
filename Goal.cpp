#include "Goal.h"
#include "MyEngine.h"
#include "World.h"

Goal::Goal()
{
	X = 0;
	Y = 0;
	Shape = 'G';
	Color.r = 0xff;
	Color.g = 0xff;
	Color.b = 0x00;
	Color.a = 0xff;
	ZOrder = 1;
}

Goal::Goal(int NewX, int NewY)
{
	X = NewX;
	Y = NewY;
	Shape = 'G';
	Color.r = 0xff;
	Color.g = 0xff;
	Color.b = 0x00;
	Color.a = 0xff;
	ZOrder = 1;

	//RAM
	Surface = SDL_LoadBMP("Data/goal.bmp");
	//GPU VRAM
	Texture = SDL_CreateTextureFromSurface(MyEngine::GetRenderer(),
		Surface);
}

Goal::~Goal()
{
}

void Goal::Render()
{
	SDL_Rect SrcRect = { 0, 0, Surface->w, Surface->h };
	SDL_Rect DestRect = { GetX() * TileSize, GetY() * TileSize, TileSize, TileSize };

	SDL_RenderCopy(MyEngine::GetRenderer(), Texture, &SrcRect, &DestRect);
}