/***********************************************************************
 * File: Hero.h
 * Author: B11115029 白安睿
 * Create Date: 2023/5/28
 * Editor: B11115029 白安睿
 * Update Date: 2023/6/11
 * Description: Hero can move,attack,and get exp to level up.
 * ***********************************************************************/
#pragma once
#include <string>
#include "Position.h"

using namespace std;


class Hero {

private:
	// Hero location
	Position pos;

	// Hero icon
	string icon = "Ｈ";	

	// Hero HP
	int	hp;

	// Hero Level
	int level = 1;

	// Requirment exp of level up
	int	maxExp;	

	// current exp hero has
	int	currentExp;

	// Hero Power
	int power;

	// Hero Limit HP
	int hpLimit;

public:
	// Default constructor
	Hero();
	// Setting constructor
	Hero(int x, int y, int level, int maxExp, int currentExp, string& icon, int hp);
	// Setting constructor
	Hero(Position& pos, int level, int maxExp, int currentExp, string& icon, int hp);

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
	string getIcon();

	// Get level
	int getLevel();

	// Get Exp
	int getExp();

	// Get MaxExp
	int getMaxExp();

	// Get HP
	int getHP();

	// Set HP
	void setHP(int hp);

	// Set Limit HP
	void setHPLimit(int hpLimit);

	// Get Limit HP
	int getHPLimit();

	// Set Power
	void setPower(int power);

	// Get power
	int getPower();

	// Hero move
	void move(Position delta);

	// Calculate Gain of EXP
	void gainEXP(int points);

	// Calculate the damage
	void getDamage(int points);

	// Calculate heal
	void heal(int healPoint);

	// Calculate the power after get equipment
	void getEquipment(int power);
};
