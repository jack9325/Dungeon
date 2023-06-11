/***********************************************************************
 * File: Ghost.cpp
 * Author: B11115029 白安睿
 * Create Date: 2023/5/28
 * Editor: B11115029 白安睿
 * Update Date: 2023/6/11
 * Description: The implement of Ghost.h
 * ***********************************************************************/
#include "Ghost.h"

// Intent: Initialize the Ghost
// Pre: None.
// Post: The Ghost will be initialize to specified value
Ghost::Ghost()
{
	this->hp = 100;
	this->hpLimit = 100;
	this->icon = "　";
	this->orgIcon = "　";
	this->pos.x = 1;
	this->pos.y = 1;
	this->power = 3;
	this->name = "Ghost";
}

// Intent: Update the Ghost and Hero when Hero move
// Pre: A Hero reference
// Post: The hero and the ghost's HP will be updated when they are at the same position
void Ghost::update(Hero& hero)
{
	if (this->pos.x == hero.getPos().x && this->pos.y == hero.getPos().y)
	{
		hero.getDamage(this->power);
		if (this->hp - hero.getPower() >= 0)
		{
			this->hp -= hero.getPower();
			cout << "Ghost get " << hero.getPower() << " damage!" << endl;
		}
		else
		{
			this->hp = 0;
			this->power = 0;
			this->icon = "　";
		}
	}
}
