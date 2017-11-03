#ifndef THREAD_H_INCLUDED
#define THREAD_H_INCLUDED

// types
typedef struct thread_s thread_t;
typedef void * (*thread_func_t)(void *);

// constructors
thread_t * thread_create_args(thread_func_t func, void * args);

// destructor
void thread_free(thread_t * self);

// methods
int thread_join(const thread_t * self);

#endif // THREAD_H_INCLUDED
