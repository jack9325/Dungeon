#include "Rock.h"

Rock::Rock()
{
	this->hp = 0;
	this->hpLimit = 0;
	this->icon = "вр";
	this->name = "Rock";
	this->orgIcon = "вр";
	this->pos.x = 1;
	this->pos.y = 1;
	this->power = 25;
}

void Rock::update(Hero& hero)
{
	if (this->pos.x == hero.getPos().x && this->pos.y == hero.getPos().y)
	{
		hero.getDamage(this->power);
	}

}
