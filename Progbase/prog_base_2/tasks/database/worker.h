#ifndef WORKER_H_INCLUDED
#define WORKER_H_INCLUDED

#include <time.h>

typedef struct worker_s
{
    int id;
    char name[20];
    char surname[20];
    int experience;
    int salary;
    double rating;
    struct tm birthDate;
} worker_t;

worker_t * worker_newWorker(void);
void worker_freeWorker(worker_t* work);

void worker_fillWorker(worker_t* work, char* name, char* surname, int experience,
                       int salary, double rating, char* birthDate);

void worker_print(worker_t * work);

void worker_printWorkers(worker_t * work, int wcount);

#endif // WORKER_H_INCLUDED
