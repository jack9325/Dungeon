/***********************************************************************
 * File: Ghost.h
 * Author: B11115029 白安睿
 * Create Date: 2023/5/28
 * Editor: B11115029 白安睿
 * Update Date: 2023/6/11
 * Description: Declare a class named Ghost which inherit from Creature.
 * ***********************************************************************/
#pragma once
#include "Creature.h"

// A Ghost class which inherit from Creature
class Ghost :public Creature
{
public:
	// Default Constructor
	Ghost();

	//overwrite the update function
	void update(Hero& hero) override;
};
