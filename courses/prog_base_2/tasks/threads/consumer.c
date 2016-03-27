#include <stdio.h>
#include <windows.h>

#include "consumer.h"
#include "thread.h"


struct consumer_s
{
    thread_t *thread;
};

static void *consumer_take(void *args);

consumer_t * consumer_new(stack_t *self)
{
    consumer_t * cons = malloc(sizeof(struct consumer_s));
    cons->thread = thread_create_args(consumer_take, self);
    return cons;
}

void consumer_free(consumer_t *cons)
{
    thread_free(cons->thread);
    free(cons);
}

void consumer_join(consumer_t *cons)
{
    thread_join(cons->thread);
}

static void *consumer_take(void *args)
{
    register int i;
    stack_t *st = (stack_t *)args;
    while(TRUE)
    {
        mutex_lock(st->hMutex);
        system("cls");
        for(i=4; i>=0; i--)
        {
            printf("\n%i\n",*(st->arr + i));
            *(st->arr + i) = 0;
            Sleep(3000);//break;
        }
        fflush(stdout);
        mutex_unlock(st->hMutex);
    }
}
