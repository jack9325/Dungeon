/***********************************************************************
 * File: Creature.cpp
 * Author: B11115029 白安睿
 * Create Date: 2023/5/28
 * Editor: B11115029 白安睿
 * Update Date: 2023/6/11
 * Description: The implement of Creature.h
 * ***********************************************************************/
#include "Creature.h"

// Intent: Initialize the Creature.
// Pre: None.
// Post: The creature will be initialize to specified value
Creature::Creature()
{
	this->pos.x = 2;
	this->pos.y = 2;
	this->icon = "Ｃ";
	this->power = 5;
	this->hp = 100;
	this->hpLimit = 100;
	this->name = "Creature";
}

// Intent: Set creature's position.
// Pre: A Position.
// Post: The creature's position will be set to input position
void Creature::setPos(Position pos)
{
	this->pos.x = pos.x;
	this->pos.y = pos.y;
}

// Intent: Set creature's position.
// Pre: Two integer named x and y.
// Post: The position of x will be set to input x,the position of y will be set to input y
void Creature::setPos(int x, int y)
{
	this->pos.x = x;
	this->pos.y = y;
}

// Intent: Set creature's icon
// Pre: A string named icon
// Post: The creature's icon will be set to input icon
void Creature::setIcon(string& icon)
{
	this->icon = icon;
}

// Intent: Get creature's position
// Pre: None.
// Post: Return the position of creature
Position Creature::getPos()
{
	return this->pos;
}

// Intent: Get creature's icon
// Pre: None.
// Post: Return the position of icon
string Creature::getIcon()
{
	return this->icon;
}

// Intent: Set creature's power
// Pre: A integer named power
// Post: The creature's power will be set to input power
void Creature::setPower(int power)
{
	this->power = power;
}

// Intent: Get creature's power
// Pre: None.
// Post: Return creature's power
int Creature::getPower()
{
	return this->power;
}

// Intent: Set creature's HP
// Pre: A integer named HP
// Post: The creature's HP will be set to input HP
void Creature::setHP(int hp)
{
	this->hp = hp;
}

// Intent: Get creature's HP
// Pre: None.
// Post: Return creature's HP
int Creature::getHP()
{
	return this->hp;
}

// Intent: Set creature's Limit HP
// Pre: A integer named hpLimit
// Post: The Limit HP will be set to input hpLimit
void Creature::setHPLimit(int hpLimit)
{
	this->hpLimit = hpLimit;
}

// Intent: Get the HP Limit
// Pre: None.
// Post: Return the Limit HP
int Creature::getHPLimit()
{
	return this->hpLimit;
}

// Intent: Update the hero and the creature when the hero move
// Pre: A hero's reference
// Post: The hero and the creature's HP will be updated when they are at the same position
void Creature::update(Hero& hero)
{
	//if hero and creature at the same position
	if (this->pos.x == hero.getPos().x && this->pos.y == hero.getPos().y)
	{
		//hero get damage
		hero.getDamage(this->power);

		//if creature's HP didn't smaller than 0 after get damage
		if (this->hp - hero.getPower() >= 0)
		{
			//output the message
			this->hp -= hero.getPower();
			cout << "Creature get " << hero.getPower() << " damage!" << endl;
		}
		//or the creature die.
		else
		{
			this->hp = 0;
			this->power = 0;
			this->icon = "　";
		}
	}
}

// Intent: Get the original icon of creature.
// Pre: None.
// Post: Return the original icon of creature
string Creature::getOrgIcon()
{
	return this->orgIcon;
}

// Intent: Get creature's name
// Pre: None.
// Post: Return creature's name
string Creature::getName()
{
	return this->name;
}
