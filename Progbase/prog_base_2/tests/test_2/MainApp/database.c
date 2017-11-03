#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>

#include <sqlite3.h>

#include "database.h"
#include "worker/worker.h"

struct db_s
{
    sqlite3 * db;
};

static void fillWorker(sqlite3_stmt * stmt, worker_t * worker);

db_t * db_new(const char * dbFileName)
{
    db_t * db_data = malloc(sizeof(struct db_s));

    if(SQLITE_ERROR == sqlite3_open(dbFileName, &db_data->db))
    {
        printf("Can't open DataBase!\n");
        exit(1);
    }
    return db_data;
}

void db_free(db_t * db_data)
{
    sqlite3_close(db_data->db);
    free(db_data);
}

void db_insertWorker(db_t* db_data, worker_t* work)
{
    sqlite3_stmt * stmt = NULL;

    const char * sqlRequest = "INSERT INTO Workers ('Name', 'Surname', 'Experience', 'Salary', 'Rating', 'BirthDate') VALUES ( ?, ?, ?, ?, ?, ?);";

    if(SQLITE_OK != sqlite3_prepare_v2(db_data->db, sqlRequest, strlen(sqlRequest)+1, &stmt, NULL))
    {
        printf("Can't prepare Insert request!\n");
        exit(1);
    }

    sqlite3_bind_text(stmt, 1, work->name, strlen(work->name), SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, work->surname, strlen(work->surname), SQLITE_STATIC);
    sqlite3_bind_int(stmt, 3, work->experience);
    sqlite3_bind_int(stmt, 4, work->salary);
    sqlite3_bind_double(stmt, 5, work->rating);

    char birth[20];
    sprintf(birth, "%i-%i-%i", work->birthDate.tm_year,
            work->birthDate.tm_mon, work->birthDate.tm_mday);

    sqlite3_bind_text(stmt, 6, birth, strlen(birth), SQLITE_STATIC);

    if(SQLITE_ERROR == sqlite3_step(stmt))
    {
        printf("Can't make step(insert)!\n");
        sqlite3_finalize(stmt);
    }
    else
    {
        work->id = sqlite3_last_insert_rowid(db_data->db);
        sqlite3_finalize(stmt);
    }
}

worker_t * db_getWorkerById(db_t* database, unsigned int id)
{
    worker_t * tmp = worker_newWorker();
    sqlite3_stmt * stmt = NULL;
    const char * sqlRequest = "SELECT * FROM Workers WHERE ID = ?;";

    if(SQLITE_OK != sqlite3_prepare_v2(database->db, sqlRequest, strlen(sqlRequest)+1, &stmt, NULL))
    {
        printf("Can't prepare Get request!\n");
        exit(1);
    }

    sqlite3_bind_int(stmt, 1, id);

    if(SQLITE_ERROR == sqlite3_step(stmt))
    {
        printf("Can't make step(get)!\n");
        sqlite3_finalize(stmt);
    }

    fillWorker(stmt, tmp);
    sqlite3_finalize(stmt);

    return tmp;
}

void db_updateWorker(db_t* database, worker_t* worker, unsigned int id)
{
    char data[20];
    sqlite3_stmt * stmt = NULL;
    const char * sqlRequest = "UPDATE Workers SET Name = ?, Surname = ?, Experience = ?, Salary = ?, Rating = ?, BirthDate = ? WHERE ID = ?;";

    if(SQLITE_OK != sqlite3_prepare_v2(database->db, sqlRequest, strlen(sqlRequest)+1, &stmt, NULL))
    {
        printf("Can't prepare Update request!\n");
        exit(1);
    }

    sqlite3_bind_text(stmt, 1, worker->name, strlen(worker->name), SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, worker->surname, strlen(worker->surname), SQLITE_STATIC);
    sqlite3_bind_int(stmt, 3, worker->experience);
    sqlite3_bind_int(stmt, 4, worker->salary);
    sqlite3_bind_double(stmt, 5, worker->rating);

    sprintf(data, "%i-%i-%i", worker->birthDate.tm_year,
            worker->birthDate.tm_mon, worker->birthDate.tm_mday);

    sqlite3_bind_text(stmt, 6, data, strlen(data), SQLITE_STATIC);

    sqlite3_bind_int(stmt, 7, id);

    if(SQLITE_ERROR == sqlite3_step(stmt))
    {
        printf("Can't make step(update)!\n");
        sqlite3_finalize(stmt);
    }
    else
    {
        sqlite3_finalize(stmt);
    }
}

void db_deleteWorker(db_t* database, unsigned int id)
{
    sqlite3_stmt * stmt = NULL;

    const char * sqlRequest = "DELETE FROM Workers WHERE ID = ?;";
    if(SQLITE_OK != sqlite3_prepare_v2(database->db, sqlRequest, strlen(sqlRequest)+1, &stmt, NULL))
    {
        printf("Can't prepare Delete request!\n");
        exit(1);
    }

    sqlite3_bind_int(stmt, 1, id);

    if(SQLITE_ERROR == sqlite3_step(stmt))
    {
        printf("Can't make step(delete)!\n");
        sqlite3_finalize(stmt);
    }
    else
    {
        sqlite3_finalize(stmt);
    }
}

int db_countWorkers(db_t* database)
{
    sqlite3_stmt * stmt = NULL;
    int count = 0;
    const char * sqlRequest = "SELECT COUNT(*) FROM Workers;";

    if(SQLITE_OK != sqlite3_prepare_v2(database->db, sqlRequest, strlen(sqlRequest)+1, &stmt, NULL))
    {
        printf("Can't prepare Count request!\n");
        exit(1);
    }

    if(SQLITE_ERROR == sqlite3_step(stmt))
    {
        printf("Can't take Count!\n");
        exit(1);
    }
    count = sqlite3_column_int(stmt, 0);
    sqlite3_finalize(stmt);
    return count;
}

int db_personalTask(db_t* database, int salary_k, int experience_p, worker_t* workers)
{
    sqlite3_stmt * stmt = NULL;
    int count = 0;
    const char * sqlRequest = "SELECT * FROM Workers WHERE Salary > ? AND Experience < ?;";

    if(SQLITE_OK != sqlite3_prepare_v2(database->db, sqlRequest, strlen(sqlRequest)+1, &stmt, NULL))
    {
        printf("Can't prepare Personal request!\n");
        exit(1);
    }

    sqlite3_bind_int(stmt, 1, salary_k);
    sqlite3_bind_int(stmt, 2, experience_p);

    while(1)
    {
        int rc = sqlite3_step(stmt);
        if(SQLITE_ERROR == rc)
        {
            printf("Can't select worker!\n");
            exit(1);
        }
        else if(SQLITE_DONE == rc)
        {
            break;
        }
        else
        {
            fillWorker(stmt, &workers[count]);
            count++;
        }
    }
    sqlite3_finalize(stmt);
    return count;
}

static void fillWorker(sqlite3_stmt * stmt, worker_t * worker)
{
    char data[20];
    char* str;

    worker->id = sqlite3_column_int(stmt, 0);
    strcpy(worker->name, sqlite3_column_text(stmt, 1));
    strcpy(worker->surname, sqlite3_column_text(stmt, 2));

    worker->experience = sqlite3_column_int(stmt, 3);
    worker->salary = sqlite3_column_int(stmt, 4);
    worker->rating = sqlite3_column_double(stmt, 5);

    strcpy(data, sqlite3_column_text(stmt, 6));

    str = strtok(data, "-");
    worker->birthDate.tm_year = atoi(str);

    str = strtok(NULL, "-");
    worker->birthDate.tm_mon = atoi(str);

    str = strtok(NULL, "\0");
    worker->birthDate.tm_mday = atoi(str);
}
