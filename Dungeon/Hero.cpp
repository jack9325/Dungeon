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
}

Hero::Hero(int x, int y, int level, int maxExp, int currentExp, char icon, int hp)
{
	this->pos.x = x;
	this->pos.y = y;
	this->level = level;
	this->maxExp = maxExp;
	this->currentExp = currentExp;
	this->icon = icon;
	this->hp = hp;
}

Hero::Hero(Position& pos, int level, int maxExp, int currentExp, char icon, int hp)
{
	this->pos = pos;
	this->level = level;
	this->maxExp = maxExp;
	this->currentExp = currentExp;
	this->icon = icon;
	this->hp = hp;
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