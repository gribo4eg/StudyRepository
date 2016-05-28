#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>

#include "worker.h"
#include "../JSON/cJSON.h"


struct worker_s
{
    char name[50];
    char surname[50];
    int var;
};

struct autor_s
{
    char name[100];
    char quote[500];
    struct tm date;
};

worker_t* worker_new(void){
    worker_t * worker = malloc(sizeof(struct worker_s));
    strcpy(worker->name, "");
    strcpy(worker->surname, "");
    worker->var = 0;
    return worker;
}

autor_t* autor_new(void){
    autor_t * autor = malloc(sizeof(struct autor_s));
    strcpy(autor->name, "");
    strcpy(autor->quote, "");
    memset(&autor->date, 0, sizeof(autor->date));
    autor->date.tm_year = 0;
    autor->date.tm_mday = 0;
    autor->date.tm_mon = 0;
    return autor;
}

void autor_free(autor_t* autor)
{
    free(autor);
}

void worker_free(worker_t * worker){
    free(worker);
}

char* autor_getName(autor_t* autor)
{
    return autor->name;
}

char* autor_getQuote(autor_t* autor){
    return autor->quote;
}

char* autor_getDate(autor_t* autor){
    char buffer[300];
    sprintf(buffer, "%i-%i-%i", autor->date.tm_year,
                                autor->date.tm_mon,
                                autor->date.tm_mday);
    return buffer;
}


void autor_fill(autor_t* autor, char* name, char* quote, char* date){
    char* str = NULL;
    char buffer[300];

    strcpy(autor->name, name);
    strcpy(autor->quote, quote);

    strcpy(buffer, date);

    str = strtok(buffer, "-");
    autor->date.tm_year = atoi(str);
    str = strtok(NULL, "-");
    autor->date.tm_mon = atoi(str);
    str = strtok(NULL, "\0");
    autor->date.tm_mday = atoi(str);
}

char* worker_getName(worker_t* worker)
{
    return worker->name;
}

char* worker_getSurname(worker_t* worker){
    return worker->surname;
}

int worker_getVar(worker_t* worker){
    return worker->var;
}


void worker_fill(worker_t* worker, char* name, char* surname, int var){
    char* str = NULL;
    char buffer[300];

    strcpy(worker->name, name);
    strcpy(worker->surname, surname);
    worker->var = var;
}

char* worker_makeWorkerJSON(worker_t *worker){
    char* inJsn = NULL;
    char buffer[300];
    cJSON* workerJsn = cJSON_CreateObject();

    cJSON_AddItemToObject(workerJsn, "Name", cJSON_CreateString(worker->name));
    cJSON_AddItemToObject(workerJsn, "Surname", cJSON_CreateString(worker->surname));
    cJSON_AddItemToObject(workerJsn, "Variant", cJSON_CreateNumber(worker->var));


    inJsn = cJSON_Print(workerJsn);
    cJSON_Delete(workerJsn);
    return inJsn;
}

char* autor_makeAutorJSON(autor_t* autor){
    char* inJsn = NULL;
    char buffer[300];
    cJSON* workerJsn = cJSON_CreateObject();

    cJSON_AddItemToObject(workerJsn, "Name", cJSON_CreateString(autor->name));
    cJSON_AddItemToObject(workerJsn, "Quote", cJSON_CreateString(autor->quote));
    sprintf(buffer, "%i-%i-%i", autor->date.tm_year,
                                autor->date.tm_mon,
                                autor->date.tm_mday);

    inJsn = cJSON_Print(workerJsn);
    cJSON_Delete(workerJsn);
    return inJsn;
}

void autor_fromJSON(autor_t* autor, char* text)
{
    cJSON * jList = cJSON_Parse(text);
}
{

}





