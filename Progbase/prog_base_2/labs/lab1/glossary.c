#include "glossary.h"

struct gloss
{
    char word[30];
    int countOfThis;
};

struct gloss_s
{
    int countOfAll;
    glossary words[200];
};

gloss_t * glossary_newGloss(void)
{
    register int i;
    gloss_t * glos = malloc(sizeof(struct gloss_s));
    glos->countOfAll = 0;
    for(i = 0; i<200; i++)
        glos->words[i].countOfThis = 0;
    glos->countOfAll = 0;
    return glos;
}

void glossary_freeGloss(gloss_t * glos)
{
    if(glos == NULL)
        return NULL;
    free(glos);
}

void glossary_fillGloss(gloss_t * glos, folder_t * folder)
{
    register int i;
    _Bool check = FALSE;
    char *str;
    //char * folderText = malloc(100 * sizeof(char));
    char folderText[100];
    strcpy(folderText, folder_getData(folder));
    str = strtok(folderText, " .,?!;");
    while(str != NULL)
    {
        for(i = 0; i<glos->countOfAll; i++)
        {
            if(strcmp(str, glos->words[i].word) == 0)
            {
                check = TRUE;
                glos->words[i].countOfThis++;
                break;
            }
            else
                continue;
        }
        if(!check)
        {
            strcpy(glos->words[glos->countOfAll].word, str);
            glos->words[glos->countOfAll].countOfThis++;//!!!!!
            glos->countOfAll++;
        }
        check = FALSE;
        str = strtok(NULL, " .,?!;");
    }
    //free(folderText);
}

void glossary_printGloss(gloss_t * glos)
{
    register int i;
    if(glos == NULL)
        return NULL;
    for(i = 0; i<glos->countOfAll; i++)
    {
        printf("%s - %i\n", glos->words[i].word, glos->words[i].countOfThis);
    }
}
