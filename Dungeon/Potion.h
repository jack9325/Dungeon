#pragma once
#include "Item.h"
#include "Hero.h"

class Potion :public Item
{
private:
	int healPoint;
public:
	Potion();
	void setHealPoint(int healPoint);
	int getHealPoint();
	void update(Hero& hero);
};