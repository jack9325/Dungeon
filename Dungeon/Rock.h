/***********************************************************************
 * File: Trigger.h
 * Author: B11115029白安睿 B11115046黃健嘉
 * Create Date: 2023/5/28
 * Editor: B11115029白安睿 B11115046黃健嘉
 * Update Date: 2023/6/11
 * Description: Declare a Trigger class,which has position,icon,and exp
 * ***********************************************************************/
#pragma once
#include "Creature.h"

class Rock:public Creature
{
public:
	Rock();
	void update(Hero& hero) override;
};
