#pragma once
#include "Position.h"

class Creature {//creature class 
protected:
	Position pos;			// Creature position
	char icon;			// Creature icon
	int power;
public:
	// Default constructor
	Creature();

	// Set position
	void setPos(Position pos);
	void setPos(int x, int y);

	// Set icon
	void setIcon(char& icon);

	// Get position
	Position getPos();

	// Get Icon
	char getIcon();

public:
	/*void update(Hero& hero) {
		Position hPos = hero.getPos();

		Position dir;
		if (canSee(this->sPos, hPos, dir)) {
			std::cout << "Creature has find the Hero in the ( " << dir.x << ", " << dir.y << " ) direction\n";
			this->sIcon = '!';
		}
		else {
			std::cout << "Creature didn't find the Hero\n";
			this->sIcon = 'C';
		}

		if (!(hPos != sPos)) {
			hero.damage(power);
		}
	}*/
};