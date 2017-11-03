#include <stdlib.h>
#include <stdio.h>

#include <windows.h>

#include "thread.h"
#include "mutex.h"
#include "producer.h"
#include "consumer.h"

int main(void)
{
    register int i;
    srand(time(NULL));

    stack_t stack;
    for(i=0; i<5; i++)
        stack.arr[i] = 0;
    stack.hMutex = mutex_new();

    producer_t *producer1 = producer_new(&stack);
    producer_t *producer2 = producer_new(&stack);

    consumer_t *consumer = consumer_new(&stack);

    consumer_join(consumer);

    producer_free(producer1);
    producer_free(producer2);

    consumer_free(consumer);

    mutex_free(stack.hMutex);
    return 0;
}
