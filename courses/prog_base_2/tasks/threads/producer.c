#include <stdlib.h>
#include <windows.h>

#include "mutex.h"
#include "thread.h"
#include "producer.h"

struct producer_s
{
    thread_t *thread;
};

static void *producer_fill(void *args);

producer_t * producer_new(stack_t *self)
{
    producer_t *prod = malloc(sizeof(struct producer_s));
    prod->thread = thread_create_args(producer_fill, self);
    return prod;
}

void producer_free(producer_t *prod)
{
    thread_free(prod->thread);
    free(prod);
}

static void *producer_fill(void *args)
{
    register int i;
    stack_t *st = (stack_t *)args;
    while(TRUE)
    {
        mutex_lock(st->hMutex);
        for(i=0; i<5; i++)
        {
            *(st->arr + i) = rand() % 10;
            Sleep(3);
        }
        mutex_unlock(st->hMutex);
    }
}
