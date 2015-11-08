#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main(void)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int stnd=FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|BACKGROUND_RED | BACKGROUND_GREEN|BACKGROUND_BLUE| FOREGROUND_INTENSITY| BACKGROUND_INTENSITY;
    int fmt1=BACKGROUND_GREEN |FOREGROUND_GREEN|FOREGROUND_INTENSITY| BACKGROUND_INTENSITY;
    int fmt2=FOREGROUND_RED|FOREGROUND_GREEN| BACKGROUND_RED | BACKGROUND_GREEN | FOREGROUND_INTENSITY| BACKGROUND_INTENSITY;
    const int time=10;
    int i, j, k=0;
    for(j=24, k=0; j>=12; k++, j--)
    {
        for(i=0; i<80; i++)
        {
            COORD pos;
            pos.X=i;
            pos.Y=j-k;
            SetConsoleCursorPosition(hConsole, pos);
            Sleep(time);
            if(i==2*k || i==55+k*2)
            {
                 SetConsoleTextAttribute(hConsole, fmt1);
            }
            if(i>2*k && i<(55+k*2))
            {
                SetConsoleTextAttribute(hConsole, fmt2);
            }
            printf("*");
            SetConsoleTextAttribute(hConsole, stnd);
        }
        if((j-k)==0)
        {
            COORD pos;
            pos.X=0;
            pos.Y=25;
            SetConsoleCursorPosition(hConsole, pos);
            break;
        }
        for(i=79; i>=0; i--)
        {
            COORD pos;
            pos.X=i;
            pos.Y=j-k-1;
            SetConsoleCursorPosition(hConsole, pos);
            Sleep(time);
            if(i==(2*k)+1 || i==56+2*k)
            {
                 SetConsoleTextAttribute(hConsole, fmt1);
            }
            if(i>(2*k)+1 && i<56+2*k)
            {
                SetConsoleTextAttribute(hConsole, fmt2);
            }
            printf("*");
            SetConsoleTextAttribute(hConsole, stnd);
        }
    }
return EXIT_SUCCESS;
}
