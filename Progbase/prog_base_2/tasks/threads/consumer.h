#ifndef CONSUMER_H_INCLUDED
#define CONSUMER_H_INCLUDED

#include "producer.h"
#include "mutex.h"
#include "thread.h"

typedef struct consumer_s consumer_t;

consumer_t * consumer_new(stack_t *self);
void consumer_free(consumer_t *cons);

void consumer_join(consumer_t *cons);

#endif // CONSUMER_H_INCLUDED
