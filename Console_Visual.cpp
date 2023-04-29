#include<stdio.h>
#include<windows.h>
#include <conio.h>

//key define
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define ESC 4

int keyControl();
void gotoxy(int, int);

int main() {
	int xpos = 0;
	int ypos = 0;
	while (true) {
		int keyCode = keyControl();

		if (keyCode == 0) {
			ypos = ypos - 1;
			//system("cls");
			gotoxy(xpos, ypos);
			printf("бс");
		}
		else if (keyCode == 1) {
			ypos = ypos + 1;
			//system("cls");
			gotoxy(xpos, ypos);
			printf("бс");
		}
		else if (keyCode == 2) {
			xpos = xpos - 2;
			//system("cls");
			gotoxy(xpos, ypos);
			printf("бс");
		}
		else if (keyCode == 3) {
			xpos = xpos + 2;
			//system("cls");
			gotoxy(xpos, ypos);
			printf("бс");
		}
		else if (keyCode == 4) {
			system("cls");
			xpos = 0;
			ypos = 0;
		}

	}


	return 0;
}

int keyControl() {
	char temp = _getch();

	if (temp == 'w' || temp == 'W') {
		return UP;
	}
	else if (temp == 'a' || temp == 'A') {
		return LEFT;
	}
	else if (temp == 's' || temp == 'S') {
		return DOWN;
	}
	else if (temp == 'd' || temp == 'D') {
		return RIGHT;
	}
	else if (temp == 27 || temp == 'ESC') {
		return ESC;
	}
}

void gotoxy(int x, int y) {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}

