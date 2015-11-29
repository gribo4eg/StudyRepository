#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void fprocess(const char * pread, const char * pwrite)
{
    int i=1;
    char str[100];
    char * ptr;
    FILE * p;

    p = fopen(pread, "r");

    if(p == NULL)
    {
        puts("Error!");
        return EXIT_FAILURE;
    }
     while(i<=3)
     {
         fgets(str, 100, p);
         i++;
     }
     fclose(p);

    p = fopen(pwrite, "w");

    if(p == NULL)
    {
        puts("Error!");
        return EXIT_FAILURE;
    }

    ptr = strtok(str, " ");
    while(ptr != NULL)
    {
        fprintf(p, "%i, ", strlen(ptr));
        ptr = strtok(NULL, " ");
    }
    fclose(p);
    puts("It's OK!");
}

/*int main(void)
{
    fprocess("out.txt", "in.txt");
    return EXIT_SUCCESS;
}*/
