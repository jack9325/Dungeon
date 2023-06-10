#include "Item.h"

Item::Item()
{
	this->icon = "";
	this->pos.x = 1;
	this->pos.y = 1;
}

void Item::setPos(int x, int y)
{
	this->pos.x = x;
	this->pos.y = y;
}

void Item::setPos(Position pos)
{
	this->pos.x = pos.x;
	this->pos.y = pos.y;
}

Position Item::getPos()
{
	return this->pos;
}

void Item::setIcon(string& icon)
{
	this->icon = icon;
}

string Item::getIcon()
{
	return this->icon;
}

void Item::update(Hero& hero)
{

}
