#include<stdio.h>
#include<Windows.h>

int main() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	printf("   @@@@     @@@@\n");
	Sleep(200);
	printf(" @@    @   @    @@\n");
	Sleep(200);
	printf("@       @ @       @\n");
	Sleep(200);
	printf("@        @        @\n");
	Sleep(200);
	printf(" @               @\n");
	Sleep(200);
	printf("  @             @\n");
	Sleep(200);
	printf("   @           @\n");
	Sleep(200);
	printf("     @       @\n");
	Sleep(200);
	printf("       @   @\n");
	Sleep(200);
	printf("         @\n");
	Sleep(200);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	printf("\n\n\n");
	printf("��");
	Sleep(150);
	printf("��");
	Sleep(150);
	printf("��");
	Sleep(150);
	printf("��");
	Sleep(150);
	printf("��");
	Sleep(150);
	printf("��");
	Sleep(150);
	printf("��");
	Sleep(150);
	printf("��");
	Sleep(150);
	printf("��\n");
	Sleep(150);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
}
