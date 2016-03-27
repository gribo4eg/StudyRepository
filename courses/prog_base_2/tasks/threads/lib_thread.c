#include <windows.h>
#include "thread.h"
#include "mutex.h"

/* THREAD */

struct thread_s {
    HANDLE win_thread;
    DWORD win_tid;
    void * result;
};

/*
    Run wrapper input args
*/
typedef struct _thread_input_args_s {
    thread_func_t fun;  // function to run
    void * args;        // arguments for fun
    void ** result;     // return value of fun
} _thread_input_args_t;

/*
    Windows thread run wrapper for thread_func_t functions
*/
static DWORD _thread_with_result(LPVOID win_args) {
    _thread_input_args_t * args = (_thread_input_args_t *)win_args;
    *args->result = args->fun(args->args);
    free(win_args);
    return 0; //@todo SUCCESS
}

thread_t * thread_create_args(thread_func_t func, void * args) {
    thread_t * t = malloc(sizeof(struct thread_s));
    t->result = (void *)NULL;

    _thread_input_args_t * wrapped_args = malloc(sizeof(_thread_input_args_t));
    wrapped_args->fun = func;
    wrapped_args->args = args;
    wrapped_args->result = (void **)&t->result;

    t->win_thread = CreateThread(
        NULL,
        0,
        (LPTHREAD_START_ROUTINE) _thread_with_result,
        (LPVOID)wrapped_args,
        0,
        &t->win_tid);
    return t;
}

void thread_free(thread_t * self) {
    CloseHandle(self->win_thread);
    free(self);
}

int thread_join(const thread_t * self) {
    WaitForSingleObject(self->win_thread, INFINITE);
    return 0;
}

/* MUTEX */

struct mutex_s {
    HANDLE win_mutex;
};

mutex_t * mutex_new(void) {
    mutex_t * ins = malloc(sizeof(struct mutex_s));
    ins->win_mutex = CreateMutex(
        NULL,
        FALSE,  // not owned
        NULL);
    return ins;
}
void mutex_free(mutex_t * self) {
    CloseHandle(self->win_mutex);
    free(self);
}

void mutex_lock(mutex_t * self) {
    WaitForSingleObject(self->win_mutex, INFINITE);
}

void mutex_unlock(mutex_t * self) {
    ReleaseMutex(self->win_mutex);
}
