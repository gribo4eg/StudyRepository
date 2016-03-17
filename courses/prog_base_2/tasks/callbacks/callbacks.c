#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>

typedef void (*callback)(char * text);

void detect(callback cb1, callback cb2);

void processCB(char * text);
void printCB(char * text);

void randomString(char * str);

int main(void)
{
    srand(time(NULL));
    detect(processCB,printCB);
    return EXIT_SUCCESS;
}

void processCB(char * text)
{
    register int i;
    for(i = 0; i < strlen(text); i++)
    {
        if(isupper(*(text + i)))
            *(text + i) = tolower(*(text + i));
        else if(islower(*(text + i)))
            *(text + i) = toupper(*(text + i));
        else if(isspace(*(text + i)))
            *(text + i) = rand()%9 + '0';
        else if(isdigit(*(text + i)))
            *(text + i) = ' ';
        else
            continue;

    }
}

void printCB(char * text)
{
    puts(text);
}

void detect(callback cb1, callback cb2)
{
    char str[50];
    char c;
    randomString(str);
    puts("Your string is:");
    puts(str);
    puts("Endless cycle is running.\nPress 'q' to exit,\tpress 'a' to call \"processCB\"\n\tpress 'z' to call \"printCB\".");
    while(1)
    {
        if(kbhit())
        {
            c = getch();
            if(c == 'z')
                cb2(str);
            else if(c == 'a')
                cb1(str);
            else if(c == 'q')
                break;
            else
                continue;
        }
    }
}

void randomString(char * str)
{
    const char random[][50] =
    {
        "I say \"Hello, World\"",
        "You'rE GoDDamn riGhT"
        "mAy thE ForCe be wiTH YOU",
        "ChEck thIs StrInG",
        "PeaCE iS a LIe, theRe IS only PASsion",
        "the MoSt coolEst striNG",
        "say My NamE!",
        "HaiL tO thE KiNg!",
        "theRe is No Emotion. There IS pEAce",
        "WintEr is coMinG!",
    };
    strcpy(str, random[rand() % 9]);
}
