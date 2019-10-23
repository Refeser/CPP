#include <iostream>
#include <conio.h>

using namespace std;

bool gameOver;
const int  width = 50;
const int height = 20;
int x, y, pointX, pointY, score;
int hvostX[1000], hvostY[1000];
int hvost;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;



void Setup()
{
	gameOver = false;
	dir = STOP;
	x = width / 2 - 1;
	y = height / 2 - 1;
	pointX = rand() % width;
	pointY = rand() % height;
	score = 0;
}

void Draw()
{
	system("cls");
	/************TOP************/
	for (int i = 0; i < width + 1; i++) 
		cout << "#";
	cout << endl;
	/*********LEFT-RIGHT*********/
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (j == 0 || j == width - 1) 
				cout << "#";
			if (i == y&&j == x)							
				cout << "O";
			else if (i == pointY && j == pointX)			
				cout << "P";
			else {
				bool print = false;
				for (int k = 0; k < hvost; k++)
					if (hvostX[k] == j && hvostY[k] == i) {
						print = true;
						cout << "o";
					}
				if(!print)
					cout << " ";
			}
		}
		cout << endl;
	}
	/***********BOTTOM***********/
	for (int i = 0; i < width + 1; i++)
		cout << "#";
	cout << endl;

	cout << "Score = " << score << endl;
}

void Input()
{
	if (_kbhit()){
		switch (_getch())
		{
			case 'a':
				dir = LEFT;
				break;
			case 'd':
				dir = RIGHT;
				break;
			case 'w':
				dir = UP;
				break;
			case 's':
				dir = DOWN;
				break;
		}
	}
}

void Logic()
{
	int prevX = hvostX[0];
	int prevY = hvostY[0];
	int prev2X, prev2Y;
	hvostX[0] = x;
	hvostY[0] = y;
	for (int i = 1; i < hvost; i++) {
		prev2X = hvostX[i];
		prev2Y = hvostY[i];
		hvostX[i] = prevX;
		hvostY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}

	switch (dir) {
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	}

	if (x >= width - 1)
		x = 0;
	else if (x < 0)
		x = width - 2;

	if (y >= height)
		y = 0;
	else if (y < 0)
		y = height - 1;

	for (int i = 0; i < hvost; i++)
		if (hvostX[i] == x && hvostY[i] == y)
			gameOver == true;

	if (x == pointX && y == pointY) {
		score++;
		pointX = rand() % width;
		pointY = rand() % height;
		hvost++;
	}
}

int main()
{
	Setup();
	while (!gameOver)
	{
		Draw();
		Input();
		Logic();
	}
	return 0;
}