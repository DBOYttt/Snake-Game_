#include "include.h"


#define MAXSNAKESIZE 100

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

void gotoxy(int x, int y) {
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
}

int main() {
	//random no generation
	srand((unsigned)time(NULL));

	// Testing snake 
	Snake snake;
	char op = 'l';
	do {
		if (_kbhit()) {
			op = _getch();
		}
		switch (op) {
		case 'w':
		case 'W':
			snake.TurnUp();
			break;

		case 's':
		case 'S':
			snake.TurnDown();
			break;

		case 'a':
		case 'A':
			snake.TurnLeft();
			break;

		case 'd':
		case 'D':
			snake.TurnRight();
			break;
		}
		snake.Move();
	} while (op != 'e');

	return 0;
}

// THE END