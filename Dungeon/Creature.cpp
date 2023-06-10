#include "Creature.h"

Creature::Creature()
{
	this->pos.x = 2;
	this->pos.y = 2;
	this->icon = "ขั";
	this->power = 5;
	this->hp = 100;
	this->hpLimit = 100;
	this->name = "Creature";
}

void Creature::setPos(Position pos)
{
	this->pos.x = pos.x;
	this->pos.y = pos.y;
}

void Creature::setPos(int x, int y)
{
	this->pos.x = x;
	this->pos.y = y;
}

void Creature::setIcon(string& icon)
{
	this->icon = icon;
}

Position Creature::getPos()
{
	return this->pos;
}

string Creature::getIcon()
{
	return this->icon;
}

void Creature::setPower(int power)
{
	this->power = power;
}

int Creature::getPower()
{
	return this->power;
}

void Creature::setHP(int hp)
{
	this->hp = hp;
}

int Creature::getHP()
{
	return this->hp;
}

void Creature::setHPLimit(int hpLimit)
{
	this->hpLimit = hpLimit;
}

int Creature::getHPLimit()
{
	return this->hpLimit;
}

void Creature::update(Hero& hero)
{
	if (this->pos.x == hero.getPos().x && this->pos.y == hero.getPos().y)
	{
		hero.getDamage(this->power);
		if (this->hp - hero.getPower() >= 0)
		{
			this->hp -= hero.getPower();
			cout << "Creature get " << hero.getPower() << " damage!" << endl;
		}
		else
		{
			this->hp = 0;
			this->power = 0;
			this->icon = "ก@";
		}
	}
}

string Creature::getOrgIcon()
{
	return this->orgIcon;
}

string Creature::getName()
{
	return this->name;
}
