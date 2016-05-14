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
static event_status_t queue_thirdEvent(queue_t* queue);
static event_status_t queue_secondEvent(queue_t* queue);
static event_status_t queue_firstEvent(queue_t* queue);

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

void queue_start(event_t* first, event_t* second, event_t* third, queue_t* queue)
{
    event_status_t event;

    printf("=*=*=*=*=*=*=*=*=*=*=*=WAITING FOR CHANGES=*=*=*=*=*=*=*=*=*=*=*=\n");
    queue_random(queue);

    //Sleep(900);
    puts("");
    queue_print(queue);
    puts("\n");

    puts("FIRST EVENT...\n");
    event = queue_firstEvent(queue);
    if(event == WRONG_DATA)
        puts("Less then 10 elements\n");
    else if(event == FIRST)
        event_happend(first);
    else if(event == BAD_EVENT)
        puts("Nothing new!\n");

    //Sleep(900);
    puts("SECOND EVENT...\n");
    event = queue_secondEvent(queue);
    if(event == WRONG_DATA)
        puts("Less then 5 elements\n");
    else if(event == SECOND)
        event_happend(second);
    else if(event == BAD_EVENT)
        puts("Nothing new!\n");

    //Sleep(900);
    puts("THIRD EVENT...\n");
    event = queue_thirdEvent(queue);
    if(event == WRONG_DATA)
        puts("Less then 5 elements\n");
    else if(event == THIRD)
        event_happend(third);
    else if(event == BAD_EVENT)
        puts("Nothing new!\n");
}

static void shiftLeft(queue_t* queue)
{
    for(int i = 0; i<queue->size-1; i++)
        queue->arr[i] = queue->arr[i+1];
}

static event_status_t queue_firstEvent(queue_t* queue)
{
    if(!queue_isFull(queue))
        return WRONG_DATA;
    double sum = 0;
    for(int i = 0; i<queue_size(queue); i++)
        sum += queue_getByInd(queue, i);

    sum /= queue_size(queue);
    sum = fabs(sum);

    if( sum <= 1)
        return FIRST;
    else
        return BAD_EVENT;
}

static event_status_t queue_secondEvent(queue_t* queue)
{
    if(queue_size(queue) < 5)
        return WRONG_DATA;

    double sum = 0;
    for(int i = queue_size(queue) - 5; i <= 5; i++)
        sum += queue_getByInd(queue, i);

    sum /= 5;

    if(sum > 5 || sum < -5)
        return SECOND;
    else
        return BAD_EVENT;
}

static event_status_t queue_thirdEvent(queue_t* queue)
{
    if(queue_size(queue) < 5)
        return WRONG_DATA;
    double sum = 0;
    for(int i = queue_size(queue) - 5; i<=5; i++)
        sum += queue_getByInd(queue, i);

    sum /= 5;
    sum = fabs(sum);

    if(sum > 10.0)
        return THIRD;
    else
        return BAD_EVENT;
}
