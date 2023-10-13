#include<stdio.h>
#include<windows.h>
#include <conio.h>

//key define
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define ESC 4
#define SPACE 5
#define SUBMIT 6
 
int keyControl();
void gotoxy(int, int);

int main() {
	system("mode con cols=60 lines=29");
	int xpos = 0;
	int ypos = 0;
	
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("         ###########################################\n");
	printf("         #                                         #\n");
	printf("         #                                         #\n");
	printf("         #                                         #\n");
	printf("         #                                         #\n");
	printf("         #                                         #\n");
	printf("         #                                         #\n");
	printf("         #                                         #\n");
	printf("         #                                         #\n");
	printf("         #                                         #\n");
	printf("         #                                         #\n");
	printf("         #                                         #\n");
	printf("         #                                         #\n");
	printf("         #                                         #\n");
	printf("         ###########################################\n");
	
	
	int x = 26;
	int y = 24;
	gotoxy(x-2, y);
	printf("> 행동하기");
	gotoxy(x, y+1);
	printf("스킵하기");
	gotoxy(x, y+2);
	printf("  종료  ");
	
	while (1) {
		int n = keyControl();
		switch (n) {
			case UP: {
				if (y>24) {
					gotoxy(x-2, y);
					printf(" ");
					gotoxy(x-2, --y);
					printf(">");
				}
				break;
			}
			
			case DOWN: {
				if (y < 26) {
					gotoxy(x-2, y);
					printf(" ");
					gotoxy(x-2, ++y);
					printf(">");
				}
				break;
			}
			
			case SUBMIT: {
				return y-24;

			}
		}
	} 
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
	else if (temp == ' ') {
		return SPACE;
	}
}

void gotoxy(int x, int y) {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}

