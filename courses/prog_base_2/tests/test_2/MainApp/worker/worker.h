#ifndef WORKER_H_INCLUDED
#define WORKER_H_INCLUDED

#define MAX_WORKERS 7

typedef struct worker_s worker_t;
typedef struct autor_s autor_t;

worker_t * worker_new(void);
void worker_free(worker_t * worker);

autor_t* autor_new(void);
void autor_free(autor_t* autor);

void autor_fill(autor_t* autor, char* name, char* quote, char* date);

char* autor_getName(autor_t* autor);
char* autor_getQuote(autor_t* autor);
char* autor_getDate(autor_t* autor);

void worker_fill(worker_t* worker, char* name, char* surname, int var);

char* worker_getName(worker_t*);
char* worker_getSurname(worker_t*);
char* worker_getBirthdate(worker_t*);
int worker_getExp(worker_t*);
double worker_getRate(worker_t*);

int worker_workersCount(worker_t** workers);

char* worker_makeWorkerJSON(worker_t *worker);
void worker_print(worker_t *worker);

#endif // WORKER_H_INCLUDED
