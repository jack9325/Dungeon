#include "Ghost.h"

Ghost::Ghost()
{
	this->hp = 100;
	this->hpLimit = 100;
	this->icon = "¡@";
	this->orgIcon = "¡@";
	this->pos.x = 1;
	this->pos.y = 1;
	this->power = 3;
	this->name = "Ghost";
}

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
			this->icon = "¡@";
		}
	}
}
