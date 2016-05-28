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
    struct tm birthdate;
    int exp;
    double rating;
};

worker_t* worker_new(void){
    worker_t * worker = malloc(sizeof(struct worker_s));
    strcpy(worker->name, "");
    strcpy(worker->surname, "");
    memset(&worker->birthdate, 0, sizeof(worker->birthdate));
    worker->birthdate.tm_year = 0;
    worker->birthdate.tm_mday = 0;
    worker->birthdate.tm_mon = 0;
    worker->exp = 0;
    worker->rating = 0;
    return worker;
}

void worker_free(worker_t * worker){
    free(worker);
}

char* worker_getName(worker_t* worker)
{
    return worker->name;
}

char* worker_getSurname(worker_t* worker){
    return worker->surname;
}

char* worker_getBirthdate(worker_t* worker){
    char buffer[300];
    sprintf(buffer, "%i-%i-%i", worker->birthdate.tm_year,
                                worker->birthdate.tm_mon,
                                worker->birthdate.tm_mday);
    return buffer;
}

int worker_getExp(worker_t* worker){
    return worker->exp;
}

double worker_getRate(worker_t* worker){
    return worker->rating;
}

void worker_fill(worker_t* worker, char* name, char* surname, char* birthdate, int exp, double rating){
    char* str = NULL;
    char buffer[300];

    strcpy(worker->name, name);
    strcpy(worker->surname, surname);
    worker->exp = exp;
    worker->rating = rating;

    strcpy(buffer, birthdate);

    str = strtok(buffer, "-");
    worker->birthdate.tm_year = atoi(str);
    str = strtok(NULL, "-");
    worker->birthdate.tm_mon = atoi(str);
    str = strtok(NULL, "\0");
    worker->birthdate.tm_mday = atoi(str);
}

char* worker_makeWorkerJSON(worker_t *worker){
    char* inJsn = NULL;
    char buffer[300];
    cJSON* workerJsn = cJSON_CreateObject();

    cJSON_AddItemToObject(workerJsn, "Name", cJSON_CreateString(worker->name));
    cJSON_AddItemToObject(workerJsn, "Surname", cJSON_CreateString(worker->surname));
    sprintf(buffer, "%i-%i-%i", worker->birthdate.tm_year,
                                worker->birthdate.tm_mon,
                                worker->birthdate.tm_mday);
    cJSON_AddItemToObject(workerJsn, "Birth date", cJSON_CreateString(buffer));
    cJSON_AddItemToObject(workerJsn, "Experience", cJSON_CreateNumber(worker->exp));
    cJSON_AddItemToObject(workerJsn, "Rating", cJSON_CreateNumber(worker->rating));

    inJsn = cJSON_Print(workerJsn);
    cJSON_Delete(workerJsn);
    return inJsn;
}





