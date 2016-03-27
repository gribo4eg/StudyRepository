#ifndef PRODUCER_H_INCLUDED
#define PRODUCER_H_INCLUDED

#include "thread.h"
#include "mutex.h"

typedef struct producer_s producer_t;

typedef struct stack_s
{
    int arr[5];
    mutex_t *hMutex;
}stack_t;

producer_t * producer_new(stack_t *self);
void producer_free(producer_t *prod);

#endif // PRODUCER_H_INCLUDED
