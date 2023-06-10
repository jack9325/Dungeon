#pragma once
#include "Position.h"
#include "Hero.h"
#include <string>

using namespace std;

class Creature {//creature class 
protected:
	Position pos;			// Creature position
	string icon="ขั";			// Creature icon
	int power;
	int hp;
	int hpLimit;
public:
	// Default constructor
	Creature();
	// Set position
	void setPos(Position pos);
	void setPos(int x, int y);
	// Set icon
	void setIcon(string& icon);
	// Get position
	Position getPos();
	// Get Icon
	string getIcon();
	void setPower(int power);
	int getPower();
	void setHP(int hp);
	int getHP();
	void setHPLimit(int hpLimit);
	int getHPLimit();
	void update(Hero& hero);
};