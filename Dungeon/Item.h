#pragma once
#include "Position.h"

class Item
{
protected:
	Position pos;
	string icon;
public:
	Positon getPos();
	void setIcon(string& icon);
	string getIcon();
};
