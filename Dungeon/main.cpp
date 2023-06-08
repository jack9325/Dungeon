#include "Hero.h"
#include "Position.h"
#include "Creature.h"
#include "main.h"

using namespace std;

Hero hero;
Creature creature;

vector<Trigger*> triggers;

string** board;
int** used;

const string wall = "\u2588 ";
const string road = "　";

int row = 0, col = 0;

const double timeLog = 0.033;

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
	row = 11;
	col = 11;

	bool gKeyState[validInput::INVALID];
	for (int i = 0; i < validInput::INVALID; i++) 
	{
		gKeyState[i] = false;
	}
	setUsed();
	setMaze();
	generateMaze(1, 1);
	printBoard();

	clock_t startT, endT;
	startT = clock();
	endT = clock();

	while (!gKeyState[validInput::EESC])
	{
		// Compute the time lap
		double timeFrame = (double)(endT - startT) / CLOCKS_PER_SEC;

		// Execute the game loop
		if (timeFrame >= timeLog) 
		{
			update(gKeyState);
			startT = clock();
		}

		// Update the key
		keyUpdate(gKeyState);
		endT = clock();


		//if (gKeyState[validInput::ESave]) {
		//	saveMap();
		//	gKeyState[validInput::ESave] = false;
		//}
		//else if (gKeyState[validInput::ELoad]) {
		//	loadMap();
		//	gKeyState[validInput::ELoad] = false;
		//}
	}

	system("pause");
	return 0;
}

void keyUpdate(bool key[])
//==================================================================
{
	for (int i = 0; i < validInput::INVALID; i++) 
	{
		key[i] = false;
	}
	char input = _getch();
	switch (input) 
	{
	case 'w':
		key[validInput::EW] = true;
		break;
	case 's':
		key[validInput::ES] = true;
		break;
	case 'a':
		key[validInput::EA] = true;
		break;
	case 'd':
		key[validInput::ED] = true;
		break;
	case ' ':
		key[validInput::ESPACE] = true;
		break;
	case 27:
		key[validInput::EESC] = true;
		break;
	case '1':
		key[validInput::ESave] = true;
		break;
	case '2':
		key[validInput::ELoad] = true;
		break;
	default:
		break;
	}
}

bool isPositionValid(Position& pos)
{
	if (board[pos.y][pos.x] != road)
	{
		return false;
	}
	return true;
}

void update(bool key[])
//==================================================================
{
	// 清除版面
	system("CLS");

	Position delta;

	// 是否有input
	bool hasInput = false;
	if (key[validInput::EW])
	{
		delta -= Position(0, 1);
		hasInput = true;
	}
	else if (key[validInput::ES])
	{
		delta += Position(0, 1);
		hasInput = true;
	}
	else if (key[validInput::EA]) 
	{
		delta = delta - Position(1, 0);
		hasInput = true;
	}
	else if (key[validInput::ED]) 
	{
		delta = delta + Position(1, 0);
		hasInput = true;
	}
	else 
	{
		bool allInvalid = true;
		for (int i = 0; i < validInput::INVALID; i++)
		{
			if (key[i]) 
			{
				allInvalid = false;
				break;
			}
		}
		if (allInvalid)
			std::cout << "invalid input\n";
	}
	if (hasInput) 
	{
		hero.move(delta);
	}

	// Manipulate update of two triggers using while loop

	//for (int i = 0; i < triggers.size(); i++) {
	//	triggers[i]->update(hero);
	//}

	//creature.update(hero);
	printBoard();
}

void generateMaze(int x, int y)
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
		if (newX > 0 && newX < row - 1 && newY > 0 && newY < col - 1 && used[newY][newX] == 0)
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

void setUsed()
{
	used = new int* [row];
	for (int i = 0; i < row; i++) {
		used[i] = new int[col];
		for (int j = 0; j < col; j++) {
			//set the edge to 1,represent can't use
			if (i == 0 || i == row - 1 || j == 0 || j == col - 1)
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
	board = new string* [row];
	for (int i = 0; i < row; i++)
	{
		board[i] = new string[col];
		for (int j = 0; j < col; j++)
		{
			board[i][j] = wall;
		}
	}
}

void printBoard()
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (i == hero.getPos().y && j == hero.getPos().x)
			{
				cout << hero.getIcon();
			}
			else
			{
				cout << board[i][j];
			}
		}
		cout << endl;
	}
}