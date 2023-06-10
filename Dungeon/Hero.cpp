#include "Hero.h"

using namespace std;

Hero::Hero()
{
	this->currentExp = 0;
	this->hp = 100;
	this->level = 1;
	this->maxExp = 15;
	this->icon = "¢Ö";
	this->pos.x = 1;
	this->pos.y = 1;
	this->power = 10;
	this->hpLimit = 100;
}

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

void Hero::setPos(Position pos)
{
	this->pos.x = pos.x;
	this->pos.y = pos.y;
}

void Hero::setPos(int x, int y)
{
	this->pos.x = x;
	this->pos.y = y;
}

void Hero::setIcon(string& icon)
{
	this->icon = icon;
}

void Hero::setLevel(int level)
{
	this->level = level;
}

void Hero::setExp(int exp)
{
	this->currentExp = exp;
}

void Hero::SetMaxExp(int maxExp)
{
	this->maxExp = maxExp;
}

Position Hero::getPos()
{
	return this->pos;
}

string Hero::getIcon()
{
	return this->icon;
}

int Hero::getLevel()
{
	return this->level;
}

int Hero::getExp()
{
	return this->currentExp;
}

int Hero::getMaxExp()
{
	return this->maxExp;
}

int Hero::getHP() const
{
	return this->hp;
}

void Hero::setHP(int hp)
{
	this->hp = hp;
}

void Hero::setHPLimit(int hpLimit)
{
	this->hpLimit = hpLimit;
}

int Hero::getHPLimit()
{
	return this->hpLimit;
}

void Hero::setPower(int power)
{
	this->power = power;
}

int Hero::getPower()
{
	return this->power;
}

void Hero::move(Position delta) 
{
	// Compute the next position
	Position next = this->pos + delta;
	this->pos = next;
}

void Hero::gainEXP(int points)
{
	int number = points;
	while (number > 0)
	{
		//level up
		if (this->currentExp + number >= this->maxExp)
		{
			number -= (this->maxExp - this->currentExp);
			this->currentExp = 0;
			this->maxExp = this->maxExp * 1.2;
			level++;
			this->power *= 1.5;
		}
		else
		{
			this->currentExp += number;
			number = 0;
		}
	}
	cout << "Hero get " << points << " EXP Points!" << endl;
}

void Hero::getDamage(int points)
{
	this->hp -= points;
	if (hp < 0)
	{
		hp = 0;
	}
	if (points > 0)
	{
		cout << "Hero get " << points << " damage!" << endl;
	}
}

void Hero::heal(int healPoint)
{
	if (this->hp + healPoint < this->hpLimit)
	{
		this->hp += healPoint;
	}
	else
	{
		this->hp = this->hpLimit;
	}
	cout << "Hero get " << healPoint << " points heal!" << endl;
}

void Hero::getEquipment(int power)
{
	this->power += power;
	cout << "Hero get an equipment and get " << power << " attack points!" << endl;
}
