#pragma once
#include "Hero.h"
#include "Creature.h"
#include "Trigger.h"
#include <iostream>
#include <random>
#include <vector>
#include <string>

using namespace std;

class Maze
{
public:
	Maze(int row, int col);
	void generateMaze(int x,int y);
	void setUsed();
	void setMaze();
	void printBoard();
	void randomGenerateHero(Hero& hero);
	void randomGenerateCreature(Creature& creature);
	void randomGenerateTrigger(Trigger& trigger);
	bool isPositionValid(Position& pos);
	string** board;

private:
	int** used;
	const string wall = "\u2588 ";
	const string road = "¡@";
	int row;
	int column;
	vector<pair<int, int>> dir;
};
