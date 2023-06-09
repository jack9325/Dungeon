#pragma once
#include "Hero.h"
#include "Position.h"
#include <string>

using namespace std;

class Trigger
{
private:
	Position pos;
	string icon;
	int exp;

public:
	Trigger();
	Trigger(int x, int y);
	Trigger(const Trigger& ref);

	void update(Hero& hero);
	void setPos(const Position& pos);
	void setPos(int x, int y);
	Position getPos() const;

	// Get Icon
	string getIcon() const;

	int getExpAmount() const;
};
