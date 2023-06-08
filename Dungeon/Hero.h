#pragma once
#include <string>
#include "Position.h"

//************************************************************
// Hero Class, only has requirement part for example
//************************************************************

class Hero {

private:
	Position pos;			// Hero location
	std::string icon = "¢Ö";	// Hero icon
	int	hp;
	int level = 1;     // Level
	int	maxExp;		// Level update experience
	int	currentExp;	// current exp hero has

public:
	// Default constructor
	Hero();

	// Setting constructor
	Hero(int x, int y, int level, int maxExp, int currentExp, char icon, int hp);

	// Setting constructor
	Hero(Position& pos, int level, int maxExp, int currentExp, char icon, int hp);

	// Set position
	void setPos(Position pos);
	void setPos(int x, int y);

	// Set icon
	void setIcon(std::string& icon);

	// Set level
	void setLevel(int level);

	// Set exp
	void setExp(int exp);

	// Set MaxExp
	void SetMaxExp(int maxexp);

	// Get position
	Position getPos();

	// Get Icon
	std::string getIcon();

	// Get level
	int getLevel();

	// Get Exp
	int getExp();

	// Get Max
	int getMaxExp();

	int getHP() const;

	void setHP(int hp);

	// Incrementally move the elements 
	//void move(Position delta);

	//// Calculate Gain of EXP
	//void gainEXP(int points) {
	//	int number = points;
	//	while (number > 0) {
	//		if (sCurrentExp + number >= sMaxExp) {//level up
	//			number -= (sMaxExp - sCurrentExp);
	//			sCurrentExp = 0;
	//			sMaxExp = (int)((float)sMaxExp * 1.2f);
	//			sLevel++;
	//		}
	//		else {
	//			sCurrentExp += number;
	//			number = 0;
	//		}
	//	}
	//}
	//void damage(int points) {
	//	hp = hp - points;
	//	if (hp < 0)
	//		hp = 0;
	//}
};
