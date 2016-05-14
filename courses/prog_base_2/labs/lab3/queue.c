#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
#include <math.h>

#include "queue.h"

struct queue_s
{
    double *arr;
    int size;
    int head;
    int tail;
    queue_status_t status;
};

static void shiftLeft(queue_t* queue);

queue_t * queue_new(void)
{
    queue_t * queue = malloc(sizeof(struct queue_s));
    queue->arr = malloc(MAX_QUEUE_SIZE * sizeof(double));
    queue->size = 0;
    queue->head = 0;
    queue->tail = 0;
    queue->status = QUEUE_EMPTY;
    return queue;
}

void queue_free(queue_t * queue)
{
    free(queue->arr);
    free(queue);
}

void queue_enqueue(queue_t * queue, double value)
{
    if(queue_isFull(queue))
    {
        queue->status = QUEUE_FULL;
        return;
    }
    queue->arr[queue->tail++] = value;
    queue->size++;
    if(queue_isFull(queue))
        queue->status = QUEUE_FULL;
    else
        queue->status = QUEUE_OK;
}

double queue_dequeue(queue_t* queue)
{
    if(queue_isEmpty(queue))
    {
        queue->status = QUEUE_EMPTY;
        return 0;
    }
    double value = queue->arr[queue->head];
    shiftLeft(queue);
    queue->tail--;
    queue->size--;
    if(queue_isEmpty(queue))
        queue->status = QUEUE_EMPTY;
    else
        queue->status = QUEUE_OK;
    return value;
}

double queue_head(queue_t * queue)
{
    if(queue_isEmpty(queue))
    {
        queue->status = QUEUE_EMPTY;
        return 0;
    }
    return queue->arr[queue->head];
}

queue_status_t queue_status(queue_t * queue)
{
    return queue->status;
}

bool queue_isEmpty(queue_t * queue)
{
    return queue->size == 0;
}

bool queue_isFull(queue_t * queue)
{
    return queue->size == MAX_QUEUE_SIZE;
}

void queue_print(queue_t * queue)
{
    if(queue_isEmpty(queue))
        puts("\nQueue is empty!\n");
    else
    {
        for(int i = 0; i<queue->size; i++)
            printf("%.2f\t", queue->arr[i]);
    }
}

double queue_getByInd(queue_t* queue, int index)
{
    if(queue_isEmpty(queue)){
        queue->status = QUEUE_EMPTY;
        return 0;
    }
    return queue->arr[index];
}

int queue_size(queue_t* queue)
{
    return queue->size;
}

void queue_random(queue_t * queue)
{
    if(queue_isFull(queue))
    {
        queue->status = QUEUE_FULL;
        return;
    }
    double value = pow(-1, rand()) * (double)(rand())/RAND_MAX * MAX_VALUE;
    queue_enqueue(queue, value);
}

static void shiftLeft(queue_t* queue)
{
    for(int i = 0; i<queue->size-1; i++)
        queue->arr[i] = queue->arr[i+1];
}
