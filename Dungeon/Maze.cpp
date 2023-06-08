#include "Maze.h"

using namespace std;

Maze::Maze(int row, int col)
{
	this->row = row;
	this->column = col;
	this->dir = {
	{0, 1},   // ¤U
	{0, -1},  // ¤W
	{-1, 0},  // ¥ª
	{1, 0}    // ¥k
	};
	setMaze();
	setUsed();
}

void Maze::generateMaze(int x, int y)
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
		if (newX > 0 && newX < this->row - 1 && newY > 0 && newY < this->column - 1 && used[newY][newX] == 0)
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

void Maze::setUsed()
{
	used = new int* [this->row];
	for (int i = 0; i < this->row; i++) {
		used[i] = new int[this->column];
		for (int j = 0; j < this->column; j++) {
			//set the edge to 1,represent can't use
			if (i == 0 || i == this->row - 1 || j == 0 || j == this->column - 1)
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

void Maze::setMaze()
{
	board = new string * [this->row];
	for (int i = 0; i < this->row; i++)
	{
		board[i] = new string[this->column];
		for (int j = 0; j < this->column; j++)
		{
			board[i][j] = wall;
		}
	}
}

void Maze::printBoard()
{
	for (int i = 0; i < this->row; i++)
	{
		for (int j = 0; j < this->column; j++)
		{
			cout << board[i][j];
		}
		cout << endl;
	}
}
