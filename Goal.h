#pragma once
#include "Actor.h"

class Goal : public Actor
{
public:
	Goal();
	Goal(int NewX, int NewY, std::string ImageName);
	virtual ~Goal();
	virtual void Init(int NewX, int NewY) override;
	virtual void Tick() override { }

};
