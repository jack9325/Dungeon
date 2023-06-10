#pragma once
#include "Creature.h"

class Ghost :public Creature
{
public:
	Ghost();
	void update(Hero& hero) override;
};
