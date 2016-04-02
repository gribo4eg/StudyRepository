#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
#include <conio.h>

void movement(int x, int y);
void map();

int main(void)
{
	char move, c = '#';
	int x = 40, y = 15;
	movement(x, y);
	printf("%c", c);
	bool d = true;
	map();
	while (d)
	{
	    map();
		if (kbhit())
		{
			switch (getch())
			{
			case 'a':
			{
				x--;
				if (x<0)
					x = 100;
				system("cls");
				movement(x, y);
				printf("%c", c);
				//puts(s);
			} break;
			case 'd':
			{
				x++;
				if (x == 100)
					x = 0;
				system("cls");
				movement(x, y);
				printf("%c", c);
				//puts(s);
			} break;
			case 'w':
                {
                    y--;
                    system("cls");
                    movement(x, y);
                    printf("%c", c);
                    map();
                    Sleep(100);
                    map();
                    y++;
                    system("cls");
                    movement(x, y);
                    printf("%c", c);
                } break;
			case 27:
				d = false; break;
			}
		}
	}
	return 0;
}

void movement(int x, int y)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hConsole, pos);
}

void map()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int x = 0;
	int y = 16;
	while (x != 100 && y == 16){
		COORD pos;
		pos.X = x;
		pos.Y = y;
		SetConsoleCursorPosition(hConsole, pos);
		printf("T");
		x++;
	}
}
