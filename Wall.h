#pragma once
#include "Actor.h"

class Wall : public Actor
{
public:
	Wall();
	Wall(int NewX, int NewY);
	virtual ~Wall();

	virtual void Render() override;

	SDL_Surface* Surface;
	SDL_Texture* Texture;

};