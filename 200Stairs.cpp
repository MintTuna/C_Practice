#include<stdio.h>
#include<windows.h>
#include<conio.h>

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4

void gameLoop();
void move(int*, int*, int, int);
int keyControl(); 
void init();
void titleDraw();
int menuDraw();
void infoDraw();
void drawMap(int*, int*);
void gotoxy(int, int);

char tempMap[15][60];
char map[15][60] = {
	{"11111111111111111111111111111111111111111111111111111111"},
	{"10000000000000000000000000000000000000000000000000000001"},
	{"10000000000000000000000000000000000000000000000000000001"},
	{"10000000000000000000000000000000000000000000000000000001"},
	{"10000000000100000000000000000000000000000000000000000001"},
	{"10000000000100000000000000000000000000000000000000000001"},
	{"10000000000100000000000000000000000000000000000000000001"},
	{"10000000000100000000000000000000000000000000000000000001"},
	{"10000000000100000000000000000000000000000000000000000001"},
	{"10000000000100000000000000000000000000000000000000000001"},
	{"10000000000100000000000000000000000000000000000000000001"},
	{"10000s0000010000000000000000000000000000000000000q000001"},
	{"10000000000100000000000000000000000000000000000000000001"},
	{"11111111111111111111111111111111111111111111111111111111"}
};

int main() {
	init();
	while (1) {
		titleDraw();
		int menuCode = menuDraw();
		if (menuCode == 0) {
			gameLoop();
		} else if (menuCode == 1) {
			infoDraw();
		} else if (menuCode == 2) {
			return 0;
		}
		system("cls");
	}
	return 0;
}	

void infoDraw() {
	system("cls");
	printf("\n\n");
	printf(" 조작법 : W A S D / SPACE BAR\n");
	printf("\n\n");
	printf(" 개발자 : MiNt_tUnA");
	
	while (1) {
		if (keyControl() == SUBMIT) {
			break;
		}
	}
}

void drawMap(int* x, int* y) {
	system("cls");
	int h, w;
	
	for (h=0; h<14; h++) {
		for (w=0; w<56; w++) {
			char temp = tempMap[h][w];
			if (temp == '0') {
				printf(" ");
			} else if (temp == '1') {
				printf("#");
			} else if (temp == 's') {
				*x = w;
				*y = h;
				printf("@");
			} else if (temp == 'q') {
				printf("O");
			}
		}
		printf("\n");
	}
	//Sleep(2000);
}

void move(int* x, int* y, int _x, int _y) {
	gotoxy(*x, *y);
	printf(" ");
	
	gotoxy(*x + _x, *y + _y);
	printf("@");
	
	*x += _x;
	*y += _y;
}

void gameLoop() {
	int x, y;
	int playing = 1;
	memcpy(tempMap, map, sizeof(tempMap	));
	
	drawMap(&x, &y);
	
	while (playing) {
		switch(keyControl()) {
			case UP:
				move(&x, &y, 0, -1);
				break;
			
			case DOWN:
				move(&x, &y, 0, 1);
				break;
				
			case RIGHT:
				move(&x, &y, 1, 0);
				break;
		
			case LEFT:
				move(&x, &y, -1, 0);
				break;
		}
	}
}

int keyControl() {
	char temp = getch();
	
	if (temp == 'w' || temp == 'W') {
		return UP;
	} else if (temp == 'a' || temp == 'A') {
		return LEFT;
	} else if (temp == 's' || temp == 'S') {
		return DOWN;
	} else if (temp == 'd' || temp == 'D') {
		return RIGHT;
	} else if (temp == ' ') {
		return SUBMIT;
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
void titleDraw() {
	printf("\n\n\n");
	printf("===============================\n");
	printf(">----------200STAIRS----------<\n");
	printf("===============================\n");
	printf("\n\n");
}

int menuDraw() {
	int x = 24;
	int y = 12;
	gotoxy(x-2, y);
	printf("> 게임시작");
	gotoxy(x, y+1);
	printf("게임정보");
	gotoxy(x, y+2);
	printf("   종료  ");
	while (1) {
		int n = keyControl();
		switch (n) {
			case UP: {
				if (y>12) {
					gotoxy(x-2, y);
					printf(" ");
					gotoxy(x-2, --y);
					printf(">");
				}
				break;
			}
			
			case DOWN: {
				if (y < 14) {
					gotoxy(x-2, y);
					printf(" ");
					gotoxy(x-2, ++y);
					printf(">");
				}
				break;
			}
			
			case SUBMIT: {
				return y-12;

			}
		}
	} 
}

void gotoxy(int x, int y) {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}
