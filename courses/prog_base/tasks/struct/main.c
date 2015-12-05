#include <stdio.h>
#include <stdlib.h>

struct Files
{
    int weight;
    char admin[10];
    char name[20];
};

int count(int size, struct Files files[size])
{
    int res=0, i;
    for(i=0; i<size; i++)
    {
        if(files[i].weight > 50)
        {
            res++;
        }
        else continue;
    }
    return res;
}

void change(struct Files * pVar, const char * newValue)
{
    strcpy(pVar->name, newValue);
}

void print(struct Files * pVar)
{
    printf("Name of file: %s\nCreator is: %s\nSize of file: %i Kb\n\n", pVar->name, pVar->admin, pVar->weight);
}

int main(void)
{
    srand(time(NULL));
    int size = 5, i;
    struct Files files[size];
    for(i=0; i<size; i++)
    {
        printf("Index of structure: %i\n\n", i);
        files[i].weight = rand()%99 + 1;
        strcpy(files[i].name, "Untitled");
        strcpy(files[i].admin, "devincube");
        printf("Name of file: %s\nCreator is: %s\nSize of file: %i Kb", files[i].name, files[i].admin, files[i].weight);
        printf("\n\n");
    }
    printf("Files more than 50Kb: %i \n\n", count(size, files));
    printf("Enter index of file, name of which you want to change:\n");
    scanf("%i", &i);
    change(&(files[i]), "I was changed!");
    print(&(files[i]));
    return EXIT_SUCCESS;
}
