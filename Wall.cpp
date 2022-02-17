#include "Wall.h"
#include "SDL.h"
#include "MyEngine.h"
#include "World.h"

Wall::Wall()
{
	X = 0;
	Y = 0;
	Shape = '*';
	Color.r = 0x80;
	Color.g = 0x3a;
	Color.b = 0x30;
	Color.a = 0xff;
	ZOrder = 1;
	bIsBlock = true;
}

Wall::Wall(int NewX, int NewY)
{
	SetActorLocation(NewX, NewY);
	Shape = '*';
	Color.r = 0x80;
	Color.g = 0x3a;
	Color.b = 0x30;
	Color.a = 0xff;
	ZOrder = 1;
	bIsBlock = true;

	//RAM
	Surface = SDL_LoadBMP("Data/wall.bmp");
	//GPU VRAM
	Texture = SDL_CreateTextureFromSurface(MyEngine::GetRenderer(),
		Surface);

}

Wall::~Wall()
{
}

void Wall::Render()
{
	SDL_Rect SrcRect = { 0, 0, Surface->w, Surface->h };
	SDL_Rect DestRect = { GetX() * TileSize, GetY() * TileSize, TileSize, TileSize };

	SDL_RenderCopy(MyEngine::GetRenderer(), Texture, &SrcRect, &DestRect);
}