#include <iostream>
#include <math.h>		// pow() and sqrt()
#include <ctime>		// for time loop function
#include <conio.h>		// _getch() <= to read input without enter "ENTER" key
#include <algorithm>	// for max and min function
#include <vector>
#include <random>
#include <stdexcept>
#include "Position.h"
#include "Trigger.h"

void isPositionValid(Position& pos);

void isInputValid(bool key[]);

// clip algroithm
float clip(float n, float minimun, float maximum);

// Check whether two position is close enough，利用 call-by-reference 將計算得到的方向回傳
bool canSee(Position cPos, Position hPos, Position& pos2);

void update(bool key[]);

void keyUpdate(bool key[]);

void generateMaze(int x, int y);
void setUsed();
void setMaze();
void setupBoard(int row, int col);
void printBoard();

