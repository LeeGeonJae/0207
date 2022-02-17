#pragma once
#include "Actor.h"

class Goal : public Actor
{
public:
	Goal();
	Goal(int NewX, int NewY);
	virtual ~Goal();

	virtual void Render() override;

	SDL_Surface* Surface;
	SDL_Texture* Texture;
};

