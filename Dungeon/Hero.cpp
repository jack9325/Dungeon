/***********************************************************************
 * File: Hero.cpp
 * Author: B11115029 白安睿
 * Create Date: 2023/5/28
 * Editor: B11115029 白安睿
 * Update Date: 2023/6/11
 * Description: The implement of Hero.h
 * ***********************************************************************/
#include "Hero.h"

using namespace std;

// Intent: Initialize Hero.
// Pre: None.
// Post: Hero will be initialized to specified value
Hero::Hero()
{
	this->currentExp = 0;
	this->hp = 100;
	this->level = 1;
	this->maxExp = 15;
	this->icon = "Ｈ";
	this->pos.x = 1;
	this->pos.y = 1;
	this->power = 10;
	this->hpLimit = 100;
}

// Intent: Initialize Hero with the input value
// Pre: A integer named x,a integer named y,a integer named level,a integer named maxExp,a integer named currentExp,a string reference named icon,a integer named hp
// Post: The value of the class will be initialized with input value
Hero::Hero(int x, int y, int level, int maxExp, int currentExp, string& icon, int hp)
{
	this->pos.x = x;
	this->pos.y = y;
	this->level = level;
	this->maxExp = maxExp;
	this->currentExp = currentExp;
	this->icon = icon;
	this->hp = hp;
	this->power = 10;
	this->hpLimit = hp;
}

// Intent: Initialize Hero with the input value
// Pre: A position reference named pos,a integer named level,a integer named maxExp,a integer named currentExp,a string reference named icon,a integer named hp
// Post: The value of the class will be initialized with input value
Hero::Hero(Position& pos, int level, int maxExp, int currentExp, string& icon, int hp)
{
	this->pos = pos;
	this->level = level;
	this->maxExp = maxExp;
	this->currentExp = currentExp;
	this->icon = icon;
	this->hp = hp;
	this->power = 10;
	this->hpLimit = hp;
}

// Intent: Set hero's position
// Pre: A position named pos
// Post: The position of hero will be set to input position
void Hero::setPos(Position pos)
{
	this->pos.x = pos.x;
	this->pos.y = pos.y;
}

// Intent: Set hero's position
// Pre: A integer named x,a integer named y
// Post: The position of hero will be set to input value
void Hero::setPos(int x, int y)
{
	this->pos.x = x;
	this->pos.y = y;
}

// Intent: Set hero's icon
// Pre: A string reference named icon
// Post: The icon of hero will be set to input icon
void Hero::setIcon(string& icon)
{
	this->icon = icon;
}

// Intent: Set hero's level
// Pre: A integer named level
// Post: The level of hero will be set to input value
void Hero::setLevel(int level)
{
	this->level = level;
}

// Intent: Set hero's exp
// Pre: A integer named exp
// Post: The current exp of hero will be set to input value
void Hero::setExp(int exp)
{
	this->currentExp = exp;
}

// Intent: Set hero's max exp
// Pre: A integer named maxExp
// Post: The max exp of hero will be set to input value
void Hero::SetMaxExp(int maxExp)
{
	this->maxExp = maxExp;
}

// Intent: Get hero's position
// Pre: None.
// Post: Return Position of hero
Position Hero::getPos()
{
	return this->pos;
}

// Intent: Get hero's icon
// Pre: None.
// Post: Return the icon of hero
string Hero::getIcon()
{
	return this->icon;
}

// Intent: Get hero's level
// Pre: None.
// Post: Return the level of hero
int Hero::getLevel()
{
	return this->level;
}

// Intent: Get hero's current exp
// Pre: None.
// Post: Return the current of hero
int Hero::getExp()
{
	return this->currentExp;
}

// Intent: Get hero's max exp
// Pre: None.
// Post: Return the max exp of hero
int Hero::getMaxExp()
{
	return this->maxExp;
}

// Intent: Get hero's HP
// Pre: None.
// Post: Return the HP of hero
int Hero::getHP()
{
	return this->hp;
}

// Intent: Set hero's HP
// Pre: A integer named hp
// Post: Hero's HP will be set to input value
void Hero::setHP(int hp)
{
	this->hp = hp;
}

// Intent: Set hero's Limit HP
// Pre: A integer named hpLimit
// Post: Hero's Limit HP will be set to input value
void Hero::setHPLimit(int hpLimit)
{
	this->hpLimit = hpLimit;
}

// Intent: Get hero's Limit HP
// Pre: None
// Post: Return hero's limit HP
int Hero::getHPLimit()
{
	return this->hpLimit;
}

// Intent: Set hero's power
// Pre: A integer named power
// Post: The power of hero will be set to input value
void Hero::setPower(int power)
{
	this->power = power;
}

// Intent: Get hero's power
// Pre: None
// Post: Return the power of hero
int Hero::getPower()
{
	return this->power;
}

// Intent: Move the hero
// Pre: The difference of next position
// Post: Hero's position will be set to next position
void Hero::move(Position delta) 
{
	// Compute the next position
	Position next = this->pos + delta;
	this->pos = next;
}

// Intent: Hero gain exp
// Pre: A integer named points
// Post: Hero's exp will be updated
void Hero::gainEXP(int points)
{
	int number = points;
	//count the exp when it goes 0
	while (number > 0)
	{
		//if the amount exp can level up
		if (this->currentExp + number >= this->maxExp)
		{
			number -= (this->maxExp - this->currentExp);
			this->currentExp = 0;

			//max exp will be risen when level up
			this->maxExp = this->maxExp * 1.2;
			level++;

			//attack power will rise when level up
			this->power *= 1.5;
		}

		//if can't level up
		else
		{
			this->currentExp += number;
			number = 0;
		}
	}
	//output the message of gain exp
	cout << "Hero get " << points << " EXP Points!" << endl;
}

// Intent: Hero get damage
// Pre: A integer named power points
// Post: Hero's HP will down
void Hero::getDamage(int points)
{
	//subtarct the HP from Hero if the point is bigger than 0
	if (points > 0)
	{
		this->hp -= points;
		cout << "Hero get " << points << " damage!" << endl;
	}

	//hp can't smaller than 0
	if (hp < 0)
	{
		hp = 0;
	}
}

// Intent: Hero get heal
// Pre: A integer named healPoint
// Post: Hero's HP will add
void Hero::heal(int healPoint)
{
	//if the heal is smaller than limit hp
	if (this->hp + healPoint < this->hpLimit)
	{
		this->hp += healPoint;
	}

	//or set the hp to hp limit
	else
	{
		this->hp = this->hpLimit;
	}

	//output the message
	cout << "Hero get " << healPoint << " points heal!" << endl;
}

// Intent: Hero get equipment
// Pre: A integer named power
// Post: Hero's power will add
void Hero::getEquipment(int power)
{
	this->power += power;
	cout << "Hero get an equipment and get " << power << " attack points!" << endl;
}
