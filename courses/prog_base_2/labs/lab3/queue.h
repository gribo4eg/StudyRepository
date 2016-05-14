#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include <stdlib.h>
#include <stdbool.h>

#define MAX_QUEUE_SIZE 10
#define MAX_VALUE (float)20.0

typedef enum queue_status_t
{
    QUEUE_EMPTY,
    QUEUE_FULL,
    QUEUE_OK
} queue_status_t;

typedef struct queue_s queue_t;

queue_t * queue_new(void);
void queue_free(queue_t * queue);

void queue_enqueue(queue_t * queue, double value);
double queue_dequeue(queue_t* queue);

double queue_getByInd(queue_t* queue, int index);
void queue_random(queue_t * queue);

double queue_head(queue_t * queue);
void queue_print(queue_t * queue);

bool queue_isEmpty(queue_t * queue);
bool queue_isFull(queue_t * queue);

int queue_size(queue_t* queue);
queue_status_t queue_status(queue_t * queue);

#endif // QUEUE_H_INCLUDED
