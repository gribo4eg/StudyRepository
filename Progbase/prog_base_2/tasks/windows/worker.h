#ifndef WORKER_H_INCLUDED
#define WORKER_H_INCLUDED

typedef struct worker_s worker_t;

worker_t * worker_new(int index, char* name, char* surname, int exp, int salary);
void worker_free(worker_t* worker);

int worker_getIndex(worker_t* worker);
char* worker_getName(worker_t* worker);
char* worker_getSurname(worker_t* worker);
int worker_getExp(worker_t* worker);
int worker_getSalary(worker_t* worker);

#endif // WORKER_H_INCLUDED
