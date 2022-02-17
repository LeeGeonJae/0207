#include "Floor.h"
#include "MyEngine.h"
#include "World.h"

Floor::Floor()
{
	X = 0;
	Y = 0;
	Shape = ' ';
	Color.r = 0xE6;
	Color.g = 0xE6;
	Color.b = 0xE6;
	Color.a = 0xff;
	ZOrder = 0;
}

Floor::Floor(int NewX, int NewY)
{
	X = NewX;
	Y = NewY;
	Shape = ' ';
	Color.r = 0xE6;
	Color.g = 0xE6;
	Color.b = 0xE6;
	Color.a = 0xff;
	ZOrder = 0;

	//RAM
	Surface = SDL_LoadBMP("Data/floor.bmp");
	//GPU VRAM
	Texture = SDL_CreateTextureFromSurface(MyEngine::GetRenderer(),
		Surface);
}

Floor::~Floor()
{
}

void Floor ::Render()
{
	SDL_Rect SrcRect = { 0, 0, Surface->w, Surface->h };
	SDL_Rect DestRect = { GetX() * TileSize, GetY() * TileSize, TileSize, TileSize };

	SDL_RenderCopy(MyEngine::GetRenderer(), Texture, &SrcRect, &DestRect);
}