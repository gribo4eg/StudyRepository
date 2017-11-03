#include <stdlib.h>
#include <string.h>

#include "worker.h"

#define SYMBOLS 30

struct worker_s
{
    int index;
    char* name;
    char* surname;
    int experience;
    int salary;
};

worker_t * worker_new(int index, char* name, char* surname, int exp, int salary)
{
    worker_t * worker = malloc(sizeof(struct worker_s));
    worker->index = index;
    worker->name = malloc(SYMBOLS * sizeof(char));
    strcpy(worker->name, name);
    worker->surname = malloc(SYMBOLS * sizeof(char));
    strcpy(worker->surname, surname);
    worker->experience = exp;
    worker->salary = salary;
    return worker;
}

void worker_free(worker_t* worker)
{
    free(worker->name);
    free(worker->surname);
    free(worker);
}

int worker_getIndex(worker_t* worker)
{
    return worker->index;
}

char* worker_getName(worker_t* worker)
{
    return worker->name;
}

char* worker_getSurname(worker_t* worker)
{
    return worker->surname;
}

int worker_getExp(worker_t* worker)
{
    return worker->experience;
}

int worker_getSalary(worker_t* worker)
{
    return worker->salary;
}
