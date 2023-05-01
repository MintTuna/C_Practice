#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include <stdlib.h>

#define LEFT 0
#define RIGHT 1
#define JUMP 2

int keyControl();
void init();
void mapDraw();
void gotoxy(int, int);
void venemyDraw();
void henemyDraw();
void playerMove();

char map[31][31] = {
	{"000000000000000000000000000000"},
	{"000000000000000000000000000000"},
	{"000000000000000000000000000000"},
	{"000000000000000011111000000000"},
	{"000000000000000000000000000000"},
	{"000000000000000000000000000000"},
	{"000011111000000000000000000000"},
	{"000000000000000000000000000000"},
	{"000000000000000000000000000000"},
	{"000000000000000011111000000000"},
	{"000000000000000000000000000000"},
	{"000000000000000000000000000000"},
	{"000000000000000000000000000000"},
	{"111111111111111111111111111111"},
};

char henemy[30] = "=============================";
char venemy[30][30] = {
	{"|"},
	{"|"},
	{"|"},
	{"|"},
	{"|"},
	{"|"},
	{"|"},
	{"|"},
	{"|"},
	{"|"},
	{"|"},
	{"|"},
	{"|"},
	{"|"},
	{"|"},
};

int main() {
	init();
	mapDraw();
	playerMove();
	henemyDraw();
	
	
	
	return 0;
}

void playerMove() {
	int x = 10;
	int y = 12;
	gotoxy(x, y);
	printf("@");
	while (1) {
		int n = keyControl();
		switch(n) {
			case LEFT: {
				gotoxy(x, y);
				printf(" ");
				gotoxy(--x, y);
				if (x < 1) {
					gotoxy(++x, y);
					printf("@");
					break;
				} else {
					printf("@");
					break;
				}
			}
			case RIGHT: {
				gotoxy(x, y);
				printf(" ");
				gotoxy(++x, y);
				if (x < 29) {
					printf("@");
					break;
				} else {
					gotoxy(--x, y);
					printf("@");
					break;
				}
			}
			case JUMP: {
				for (int i =0;i<4;i++) {
					gotoxy(x, y);
					printf(" ");
					gotoxy(x, --y);
					printf("@");
					Sleep(30);
				}
				for (int i =0;i<4;i++) {
					gotoxy(x, y);
					printf(" ");
					gotoxy(x, ++y);
					printf("@");
					Sleep(30);
				}
				break;
			}
		}
	}
}

void henemyDraw() {
	int _hy;
	_hy = rand()%9 + 2;
	gotoxy(0, 0);
	printf("%s", henemy);
}

void mapDraw() {
	system("cls");
	int h, w;
	
	for (h=0; h<31; h++) {
		for (w=0; w<31; w++) {
			char temp = map[h][w];
			if (temp == '0') {
				printf(" ");
			} else if (temp == '1') {
				printf("#");
			}
		}
		printf("\n");
	}
}

int keyControl() {
	char temp = getch();
	
	if (temp == 'a' || temp == 'A') {
		return LEFT;
	} else if (temp == 'd' || temp == 'D') {
		return RIGHT;
	} else if (temp == ' ') {
		return JUMP;
	} 
}


void init() {
	system("mode con cols = 56 lines = 20 | title 200STAIRS");
	
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = 0;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle , &ConsoleCursor);
}

void gotoxy(int x, int y) {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}
