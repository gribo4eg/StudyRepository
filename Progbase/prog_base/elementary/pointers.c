#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    srand(time(NULL));
    int a, x, * p, * p1, arr[20], i;
    double mas[15], * d, * d1, x1;
    char str[100], * s;
    puts("TASK 1");
    puts("Input number");
    scanf("%i", &a);
    printf("Your number: %i\n", a);
    puts("TASKS 2,3,4 and 5");
    p = &a;
    p1 = &a;
    puts("Input new value:");
    scanf("%i", p);
    printf("Changed value: %i\n", *p1);
    puts("TASKS 6 and 7");
    for(i=0; i<20; i++)
    {
        printf("%i ", arr[i] = rand() % 100);
    }
    p = arr;
    puts("");
    puts("Use pointer:");
    for(i=0; i<20; i++)
    {
        printf("%i ", *(p++));
    }
    p = &(arr[19]);
    puts("");
    for(i=19; i>=0; i--)
    {
        printf("%i ", *(p--));
    }
    puts("");
    puts("TASKS 8");
    for(i=0; i<20; i++)
    {
        printf("%i ", arr[i] = rand() % 200 - 100);
    }
    p = arr;
    puts("");
    puts("Use pointer:");
    for(i=0; i<20; i++, p++)
    {
        if( *p < 0)
        {
            printf("%i ", *p);
        }
    }
    puts("");
    puts("TASKS 9, 10, 11");
    for(i=0; i<15; i++)
    {
        a = rand() % 100;
        x = rand() % 100;
        x1 = (double)x/100;
        printf("%.2f ", mas[i] = a + x1);
    }
    d = mas;
    d1 = &(mas[14]);
    puts("");
    puts("Use pointer:");
    for(i=0; i<=7; i++, d++, d1--)
    {
        if(i == 7)
        {
            printf("%.2f ", *d++);
            break;
        }
        printf("%.3f ", (*d)/(*d1));
    }
    puts("");
    puts("TASK 12");
    printf("Print string\n>>");
    fflush(stdin);
    gets(str);
    s = str;
    while(*s != '\0')
    {
        printf("%c ", *s);
        s++;
    }
    puts("");
    puts("TASK 13");
    s = str;
    for(i=0; i<100; i++, s++)
    {
        if(*s == ' ')
        {
            *s = '\0';
            break;
        }
        //printf("%c", *s);
    }
    puts(str);
    return EXIT_SUCCESS;
}
