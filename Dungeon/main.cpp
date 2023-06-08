#include "Hero.h"
#include "Position.h"
#include "main.h"
#include <iostream>

using namespace std;

Hero hero;

enum validInput
{
	EW = 0,
	ES = 1,
	EA = 2,
	ED = 3,
	ESPACE = 4,
	EESC = 5,
	ESave = 6,
	ELoad = 7,
	INVALID,
};

int main()
{
	srand(time(NULL));
	Maze maze1(11, 11); 
	Maze maze2(15, 15);
	Maze maze3(19, 19);
	maze3.generateMaze(1,1);
	maze3.board[hero.getPos().y][hero.getPos().x] = hero.getIcon();
	maze3.printBoard();
}


