/***********************************************************************
 * File: Position.h
 * Author: B11115029 白安睿
 * Create Date: 2023/
 * Editor: B11115029 白安睿
 * Update Date: 2023/
 * Description: 
 * ***********************************************************************/
#pragma once
#include <iostream>

class Position {
public:
	int x, y; 

	Position();
	Position(int x, int y);
	Position(const Position& ref);

	// Operator overloading
	Position operator+(const Position& rhs) const;
	Position& operator=(const Position& rhs);
	Position& operator+=(const Position& rhs);
	Position operator-(const Position& rhs) const;
	Position& operator-=(const Position& rhs);
	Position operator*(int scale) const;
	bool operator==(const Position& rhs) const;
	bool operator!=(const Position& rhs) const;
	friend std::ostream& operator<<(std::ostream& oStream, const Position& pos);
	friend std::istream& operator>>(std::istream& iStream, Position& pos);
};