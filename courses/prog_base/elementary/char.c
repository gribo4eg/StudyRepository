#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void findSym(char str[])
{
    int i;
    char c;
    printf("\nEnter the symbol, which you want to find:\n>>");
    scanf("%c", &c);
    for(i=0; i<strlen(str); i++)
    {
        if(str[i] == c)
        {
            puts("I found your symbol!");
            break;
        }
    }
}

/*void smth(char str[], int index, int size)
{
    char tmp[80], tmp1[80], tmp2[80];
    int a, i;
    puts("=====1-letters; 2-numbers; 3-symbols=====");
    for(i=0; i<size; i++)
    {
        if(isalpha(str[i]))
        {
            if(i == index)
            {
                strcpy(tmp, str[i]);
                continue;
            }
            strcat(tmp, str[i]);
        }
    }
    strcpy(str, tmp);
    a=0;
    for(i=0; i<size; i++)
    {
        if(isdigit(str[i]))
        {
            if(a==0)
            {
                strcpy(tmp1, str[i]);
                a++;
                continue;
            }
            if(a!=0)
            {
                strcat(tmp1, str[i]);
            }
        }

    }
    strcat(str, tmp1);
    a=0;
    for(i=0; i<size; i++)
    {
        if(isdigit(str[i]) || isalpha(str[i]))
            continue;
        if(a==0)
        {
            strcpy(tmp2, str[i]);
            a++;
            continue;
        }
        if(a!=0)
        {
            strcat(tmp2, str[i]);
        }
    }
    strcat(str, tmp2);
    puts(str);
}*/

int main(void)
{
    char str[50];
    char c;
    int a, i, ix;
    printf("Put symbol:\n");
    scanf("%c", &c);
    printf("How many times repeat symbol?\n>>");
    scanf("%i", &a);
    puts("");
    for(i=0; i<a; i++)
    {
        printf("%c ", c);
    }
    puts("");
    puts("=====Is digit?=====");
    if(isdigit(c))
    {
        puts("1");
    }
    else puts("0");
    puts("=====Is alpha?=====");
    if(isalpha(c))
    {
        printf("Is letter!", c);
    }
    else printf("Isn't letter!", c);
    puts("");
    puts("=====Is upper or is lower? Maybe not a letter?=====");
    if(isupper(c))
    {
        puts("2");
    }
    else if(islower(c))
    {
        puts("1");
    }
    else puts("0");
    puts("====='?'=====");
    if(c == ' ')
    {
        puts("Is NULL");
    }
    else puts("Not NULL");
    puts("=====String=====");
    puts("Print string of symbols:\n");
    scanf("%s", str);
    printf("\nResult:\n");
    puts("=====Changes=====");
    puts("");
    for(i=0; i<strlen(str); i++)
    {
        if(isupper(str[i]))
        {
            str[i]=tolower(str[i]);
        }
        else if(islower(str[i]))
        {
            str[i]=toupper(str[i]);
        }
        else if(isdigit(str[i]))
        {
            str[i]='9'-(str[i]-'0');
        }
    }
    puts(str);
    puts("=====First letter index=====");
    for(i=0; i<strlen(str); i++)
    {
        if(isalpha(str[i]))
        {
            ix = i;
            printf("\nIndex of first letter is %i", i);
            break;
        }
    }
    puts("");
    //smth(str, ix, strlen(str));
    puts("=====1st Letter <-> 1st Number=====");
    puts("");
    int tmpi, indexc, indexi;
    char tmpc;
    for(i=0; i<strlen(str); i++)
    {
        if(isalpha(str[i]))
        {
            tmpc=str[i];
            indexc=i;
            break;
        }
    }
    for(i=0; i<strlen(str); i++)
    {
        if(isdigit(str[i]))
        {
            tmpi=str[i];
            indexi=i;
            break;
        }
    }
    str[indexc]=tmpi;
    str[indexi]=tmpc;
    puts(str);
    /*puts("=====Find symbol=====");
    findSym(str);
    puts("");*/
    puts("=====All numbers = ' '=====");
    for(i=0; i<strlen(str); i++)
    {
        if(isdigit(str[i]))
        {
            str[i]=' ';
        }
        printf("%c,", str[i]);
    }
    puts("");
    return EXIT_SUCCESS;
}
