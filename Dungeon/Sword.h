#pragma once
#include "Item.h"
#include "Hero.h"

class Sword :public Item
{
private:
	int power;

public:
	Sword();
	int getPower();
	void setPower(int power);
	void update(Hero& hero) override;
};