#include <iostream>
#include <math.h>		// pow() and sqrt()
#include <ctime>		// for time loop function
#include <conio.h>		// _getch() <= to read input without enter "ENTER" key
#include <algorithm>	// for max and min function
#include <vector>
#include <random>
#include <stdexcept>
#include <fstream>
#include <windows.h>
#include "Position.h"
#include "Trigger.h"
#include "Hero.h"
#include "Position.h"
#include "Creature.h"
#include "Potion.h"
#include "Sword.h"
#include "Ghost.h"
#include "Rock.h"

void isPositionValid(Position& pos);

void isInputValid(bool key[]);

void drawInfo();

void update(bool key[]);

void keyUpdate(bool key[]);

void generateMaze(int x, int y);

void setUsed();

void setMaze();

void ghostMove(int row, int col);

void setupBoard(int row, int col);

void printBoard();

void saveMap();

void loadMap();