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
	printf("어");
	Sleep(150);
	printf("버");
	Sleep(150);
	printf("이");
	Sleep(150);
	printf("날");
	Sleep(150);
	printf("축");
	Sleep(150);
	printf("하");
	Sleep(150);
	printf("드");
	Sleep(150);
	printf("려");
	Sleep(150);
	printf("요\n");
	Sleep(150);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
}
