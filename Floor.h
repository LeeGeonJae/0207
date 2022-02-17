#pragma once
#include "Actor.h"

class Floor : public Actor
{
public:
	Floor();
	Floor(int NewX, int NewY);
	virtual ~Floor();

	virtual void Render() override;

	SDL_Surface* Surface;
	SDL_Texture* Texture;

};

