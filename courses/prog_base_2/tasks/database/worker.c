#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>

#include "worker.h"

worker_t * worker_newWorker(void)
{
    worker_t * work = malloc(sizeof(struct worker_s));
    work->id = 0;

    strcpy(work->name, " ");
    strcpy(work->surname, " ");

    work->experience = 0;
    work->salary = 0;
    work->rating = 0.0;

    memset(&work->birthDate, 0, sizeof(work->birthDate));
    work->birthDate.tm_year = 0;
    work->birthDate.tm_mon = 0;
    work->birthDate.tm_mday = 0;

    return work;
}

void worker_freeWorker(worker_t* work)
{
    free(work);
}

void worker_fillWorker(worker_t* work, char* name, char* surname, int experience,
                       int salary, double rating, char* birthdate)
{
    char* str = NULL;

    strcpy(work->name, name);
    strcpy(work->surname, surname);

    work->experience = experience;
    work->salary = salary;
    work->rating = rating;

    char copy[20];

    strcpy(copy, birthdate);

    str = strtok(copy, "-");
    work->birthDate.tm_year = atoi(str);

    str = strtok(NULL, "-");
    work->birthDate.tm_mon = atoi(str);

    str = strtok(NULL, "\0");
    work->birthDate.tm_mday = atoi(str);
}



void worker_print(worker_t* work)
{
    printf("Id: %i\nName: %s\nSurname: %s\nExperience(years): %i\nSalary: %i\nRating: %.1f\nBirthDate: %i-%i-%i\n\n",
           work->id, work->name, work->surname, work->experience,
           work->salary, work->rating, work->birthDate.tm_year, work->birthDate.tm_mon, work->birthDate.tm_mday);
}

void worker_printWorkers(worker_t* workArr, int wcount)
{
    for(int i = 0; i < wcount; i++)
        worker_print(&workArr[i]);
}
