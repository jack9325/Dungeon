/***********************************************************************
 * File: Position.cpp
 * Author: B11115029 白安睿
 * Create Date: 2023/5/28
 * Editor: B11115029 白安睿
 * Update Date: 2023/6/11
 * Description: The implement of Position.h
 * ***********************************************************************/
#include "Position.h"

// Intent: Initialize the position
// Pre: None.
// Post: x and y will be initialized to 0
Position::Position()
{
	this->x = 0;
	this->y = 0;
}

// Intent: Initialize the position
// Pre: None.
// Post: x and y will be initialized to input value
Position::Position(int x, int y)
{
	this->x = x;
	this->y = y;
}

// Intent: Initialize the position
// Pre: A const Position reference named ref
// Post: x and y will be initialized to input ref
Position::Position(const Position& ref)
{
	this->x = ref.x;
	this->y = ref.y;
}

// Intent: Overloading + operator
// Pre: A const Position reference named rhs 
// Post: Return the result of 2 position add
Position Position::operator+(const Position& rhs) const
{
	return Position(x + rhs.x, y + rhs.y);
}

// Intent: Overloading = operator
// Pre: A const Position reference named rhs 
// Post: the position of left will be equal to right
Position& Position::operator=(const Position& rhs)
{
	this->x = rhs.x;
	this->y = rhs.y;
	return *this;
}

// Intent: Overloading += operator
// Pre: A const Position reference named rhs 
// Post: the position of right will be added to left
Position& Position::operator+=(const Position& rhs)
{
	x += rhs.x;
	y += rhs.y;
	return *this;
}

// Intent: Overloading - operator
// Pre: A const Position reference named rhs 
// Post: Return the result of left subtract right
Position Position::operator-(const Position& rhs) const
{
	return Position(x - rhs.x, y - rhs.y);
}

// Intent: Overloading -= operator
// Pre: A const Position reference named rhs 
// Post: right position will be subtracted by left position
Position& Position::operator-=(const Position& rhs)
{
	x -= rhs.x;
	y -= rhs.y;
	return *this;
}

// Intent: Overloading * operator
// Pre: A integer named scale
// Post: Return the result of the input value multiply position
Position Position::operator*(int scale) const
{
	return Position(x * scale, y * scale);
}

// Intent: Overloading == operator
// Pre: A const Position reference named rhs 
// Post: Return the result of compare 2 position x,y
bool Position::operator==(const Position& rhs) const
{
	return x == rhs.x && y == rhs.y;
}

// Intent: Overloading != operator
// Pre: A const Position reference named rhs 
// Post: Return the result after compare
bool Position::operator!=(const Position& rhs) const
{
	return !(*this == rhs);
}

// Intent: Overloading << operator
// Pre: an ostream and a const Position reference named rhs 
// Post: put the value of position into ostream and return it
std::ostream& operator<<(std::ostream& oStream, const Position& pos)
{
	return oStream << pos.x << " " << pos.y;
}

// Intent: Overloading >> operator
// Pre: an istream and a Position reference named pos 
// Post: read the value from the istream and put them into pos
std::istream& operator>>(std::istream& iStream, Position& pos)
{
	return iStream >> pos.x >> pos.y;
}
