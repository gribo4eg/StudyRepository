#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <conio.h>

void movement(int x, int y);

int main(void)
{
    char move, c = '#';
    char s[] = {
        {'#'},
        {'#'}
    };
    int x = 40, y = 15;
    movement(x, y);
    printf("%c", c);
    _Bool d = TRUE;
    while(d)
    {
        if(kbhit())
        {
            switch(getch())
                {
                    case 'a':
                    {
                        x--;
                        if(x<0)
                            x = 89;
                        system("cls");
                        movement(x, y);
                        printf("%c", c);
                        //puts(s);
                    } break;
                    case 'd':
                        {
                            x++;
                            if(x == 90)
                                x = 0;
                            system("cls");
                            movement(x, y);
                            printf("%c", c);
                            //puts(s);
                        } break;
                    case 27:
                        d = FALSE; break;
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
