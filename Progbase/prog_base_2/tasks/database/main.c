#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sqlite3.h>

#include "database.h"
#include "worker.h"

/** CHECK DATABASE BEFORE RUNNING! THERE ARE SOME FUNCTIONS
    WHICH CHANGE IT(DELETE, INSERT, ETC.)
**/

int main(void)
{
    db_t * db = db_new("workers.db");
    int dbsize = db_countWorkers(db);
    printf("Size of DB at the beginning: %i\n\n", dbsize);

    puts("========WORKER FROM DATABASE(ID = 2):");
    worker_t * TestWorker = worker_newWorker();
    TestWorker = db_getWorkerById(db, 2);
    worker_print(TestWorker);
    worker_freeWorker(TestWorker);
    puts("\n");

    puts("=========PERSONAL TASK:");
    worker_t workers[db_countWorkers(db)];

    int moreSalary = 1800;
    int lessExp = 6;

    dbsize = db_personalTask(db, moreSalary, lessExp, workers);
    printf("Workers with Salary > %i AND Experience < %i :\n\n", moreSalary, lessExp);
    worker_printWorkers(workers, dbsize);

    puts("==========WORKER UPDATE(ID = 3):");
    TestWorker = worker_newWorker();
    worker_fillWorker(TestWorker, "Vanyok", "Kunyok", 2, 1789, 2.9, "1995-07-23");
    db_updateWorker(db, TestWorker, 3);
    TestWorker = db_getWorkerById(db, 3);
    worker_print(TestWorker);
    worker_freeWorker(TestWorker);

    puts("========ADD NEW WORKER:");
    TestWorker = worker_newWorker();
    worker_fillWorker(TestWorker, "Babuin", "RedAss", 7, 5500, 8.1, "1989-10-15");
    puts("Worker from DB after adding:");
    db_insertWorker(db, TestWorker);
    TestWorker = db_getWorkerById(db, 4);
    worker_print(TestWorker);
    printf("Workers in database after adding: %i\n\n", db_countWorkers(db));
    worker_freeWorker(TestWorker);

    puts("==========DELETE WORKER(ID = 4(Babuin)):");
    printf("Look at the DATABASE, now there are 4 workers. But if you press any key, there will be 3 worker!\n");
    getchar();
    db_deleteWorker(db, 5);
    puts("Delete successful! Check your database!");


    db_free(db);
    return 0;
}
