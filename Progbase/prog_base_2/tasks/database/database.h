#ifndef DATABASE_H_INCLUDED
#define DATABASE_H_INCLUDED

#include "worker.h"

typedef struct db_s db_t;

db_t * db_new(const char * dbFileName);
void db_free(db_t * db_data);

void db_insertWorker(db_t* db_data, worker_t* work);
worker_t * db_getWorkerById(db_t* database, unsigned int id);
void db_updateWorker(db_t* database, worker_t* worker, unsigned int id);
void db_deleteWorker(db_t* database, unsigned int id);
int db_countWorkers(db_t* database);
int db_personalTask(db_t* database, int salary_k, int experience_p, worker_t* workers);


#endif // DATABASE_H_INCLUDED
