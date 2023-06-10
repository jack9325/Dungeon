#pragma once
#include "Creature.h"

class Rock:public Creature
{
public:
	Rock();
	void update(Hero& hero) override;
};