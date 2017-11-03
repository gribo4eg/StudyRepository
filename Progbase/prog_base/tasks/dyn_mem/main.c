#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    int * p;
    char * getStr;

    p = NULL;
    getStr = NULL;

    getStr = (char *)malloc(50 * sizeof(char));
    p = (int *)malloc(sizeof(int));

    if(getStr == NULL || p == NULL)
    {
        puts("Error!");
        return EXIT_FAILURE;
    }

    puts("Print smth:");
    gets(getStr);

    for((*p) = strlen(getStr); (*p)>=0; (*p)--)
    {
        if(isupper(*(getStr+*p)))
        {
            puts("Answer is:");
            printf("%c", *(getStr + *p));
            break;
        }
    }

    free(getStr);
    free(p);
    return EXIT_SUCCESS;
}
