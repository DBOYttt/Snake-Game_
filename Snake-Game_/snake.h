#ifndef snake
#define snake


#include "include.h"

class Snake {
private:
	Point* cell[MAXSNAKESIZE]; // array of points to represent snake
	int size; // current size of snake
	char dir; // current direction of snake
	Point fruit;
public:
	Snake() {
		size = 5; // default size
		cell[0] = new Point(60, 60); // 20,20 is default position
		for (int i = 1; i < MAXSNAKESIZE; i++) {
			cell[i] = NULL;
		}
		fruit.SetPoint(rand() % 50, rand() % 25);
	}
	void AddCell(int x, int y) {
		cell[size++] = new Point(x, y);
	}
	void TurnUp() {
		dir = 'w';
	}
	void TurnDown() {
		dir = 's';
	}
	void TurnLeft() {
		dir = 'a';
	}
	void TurnRight() {
		dir = 'd';
	}
	void Move() {

		system("cls");

		// making snake body follow its head
		for (int i = size - 1; i > 0; i--) {
			cell[i - 1]->CopyPos(cell[i]);
		}

		// turning snake's head
		switch (dir) {
		case 'w':
			cell[0]->MoveUp();
			break;
		case 's':
			cell[0]->MoveDown();
			break;
		case 'a':
			cell[0]->MoveLeft();
			break;
		case 'd':
			cell[0]->MoveRight();
			break;
		}

		// Collision with fruit
		if (fruit.GetX() == cell[0]->GetX() && fruit.GetY() == cell[0]->GetY()) {
			AddCell(0, 0);
			fruit.SetPoint(rand() % 50, rand() % 25);
		}

		//drawing snake
		for (int i = 0; i < size; i++)
			cell[i]->Draw();
		fruit.Draw();

		//Debug();

		Sleep(100);
	}
	void Debug() {
		for (int i = 0; i < size; i++) {
			cell[i]->Debug();
		}
	}
};


#endif // !snake
