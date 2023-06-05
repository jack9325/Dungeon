#include "Hero.h"
#include "Position.h"
#include "main.h"
#include <iostream>

using namespace std;

Hero hero;

const char wall = 'O';
const char road = '.';
char** board;
int** used;

vector<pair<int, int>> dir = {
	{0, 1},   // 下
	{0, -1},  // 上
	{-1, 0},  // 左
	{1, 0}    // 右
};

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
	setMaze();
	setUsed();
	generateMaze(1,1);
	board[hero.getPos().y][hero.getPos().x] = hero.getIcon();
	printBoard();
}

void setUsed()
{
	used = new int* [17];
	for (int i = 0; i < 17; i++) {
		used[i] = new int[17];
		for (int j = 0; j < 17; j++) {
			//set the edge to 1,represent can't use
			if (i == 0 || i == 16 || j == 0 || j == 16)
			{
				used[i][j] = 1;
			}
			else
			{
				used[i][j] = 0;
			}
		}
	}
}

void setMaze()
{
	board = new char* [17];
	for (int i = 0; i < 17; i++)
	{
		board[i] = new char[17];
		for (int j = 0; j < 17; j++)
		{
			board[i][j] = wall;
		}
	}
}

void generateMaze(int x,int y)
{
	// Set the current position as nothing (path) and mark it as used
	board[y][x] = road;
	used[y][x] = 1;

	// Shuffle the direction array randomly
	random_shuffle(dir.begin(), dir.end());

	// Iterate through the directions
	for (int i = 0; i < 4; i++)
	{
		int newX = 0, newY = 0;
		newX = x + dir[i].first * 2;
		newY = y + dir[i].second * 2;

		// Check if the new position is within the maze boundaries and not used
		if (newX > 0 && newX < 16 && newY > 0 && newY < 16 && used[newY][newX] == 0)
		{
			int passX = 0, passY = 0;
			passX = x + dir[i].first;
			passY = y + dir[i].second;

			// Set the passed position as nothing (path) and mark it as used
			board[passY][passX] = road;
			used[passY][passX] = 1;

			// Recursively generate the maze from the new position
			generateMaze(newX, newY);
		}
	}
}

void printBoard()
{
	for (int i = 0; i < 17; i++)
	{
		for (int j = 0; j < 17; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}
