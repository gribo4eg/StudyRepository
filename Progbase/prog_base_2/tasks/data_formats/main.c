#include <stdio.h>
#include <stdlib.h>

#include "workers.h"

int main()
{
    workers_t * worker[3];
    int i;
    for(i = 0; i<3; i++)
        worker[i] = workers_newWorker();

    workers_parseWorker(worker, "workers.xml");

    for(i = 0; i<3; i++)
    {
        workers_printWorker(worker[i]);
    }

    for(i = 0; i<3; i++)
    {
        workers_freeWorker(worker[i]);
    }
    return 0;
}
