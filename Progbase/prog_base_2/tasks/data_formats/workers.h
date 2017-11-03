#ifndef WORKERS_H_INCLUDED
#define WORKERS_H_INCLUDED

typedef struct workers_s workers_t;

workers_t * workers_newWorker();

void workers_freeWorker(workers_t * worker);

void workers_parseWorker(workers_t **worker, const char *xmlFile);
void workers_printWorker(workers_t *worker);

#endif // WORKERS_H_INCLUDED
