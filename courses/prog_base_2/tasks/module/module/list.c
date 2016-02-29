#include"list.h"

#define MAX_LIST_SIZE 100

struct list_s
{
    int * arr;
    int size;
    list_status_t status;
};

static void resetStatus(list_t * self);
static void shift_right(list_t * self, int index);
static void shift_left(list_t * self, int index);
static int isFull(list_t * self);
static int isEmpty(list_t * self);

list_t * list_newList(void)
{
    list_t * self = malloc(sizeof(struct list_s));
    self->arr = malloc(MAX_LIST_SIZE * sizeof(int));
    self->size = 0;
    self->status = LIST_OK;
}

void list_removeList(list_t * self)
{
    free(self->arr);
    free(self);
}

void list_add(list_t * self, int value, int index)
{
    resetStatus(self);
    if(isFull(self))
    {
        self->status = LIST_FULL;
        return;
    }
    if(index - 1 >= MAX_LIST_SIZE || index - 1 >= self->size - 1){
        self->arr[(self->size)++] = value;
        return;
    }
    if(index - 1 < self->size - 1)
        shift_right(self, index);
    self->arr[index - 1] = value;
    (self->size)++;
}

int list_delete(list_t * self, int index)
{
    resetStatus(self);
    if(!isEmpty(self) && index - 1 <= self->size - 1)
    {
        shift_left(self, index);
        (self->size)--;
    }
    else
        self->status = LIST_EMPTY;
}

int list_size(list_t * self)
{
    return self->size;
}

int list_positive(list_t * self)
{
    register int i;
    int count = 0;
    for(i = 0; i<self->size; i++)
    {
        if(self->arr[i] > 0)
            count++;
    }
    return count;
}

int list_negative(list_t * self)
{
    register int i;
    int count = 0;
    for(i = 0; i<self->size; i++)
    {
        if(self->arr[i] < 0)
            count++;
    }
    return count;
}

int list_zero(list_t * self)
{
    register int i;
    int count = 0;
    for(i = 0; i<self->size; i++)
    {
        if(0 == self->arr[i])
            count++;
    }
    return count;
}

static int isEmpty(list_t * self)
{
    if(0 == self->size)
        return 1;
    else
        return 0;
}

static int isFull(list_t * self)
{
    if(self->size == MAX_LIST_SIZE)
        return 1;
    else
        return 0;
}

static void shift_right(list_t * self, int index)
{
    register int i;
    for(i = self->size - 1; i >= index - 1; i--)
    {
        self->arr[i + 1] = self->arr[i];
    }
}

static void shift_left(list_t * self, int index)
{
    register int i;
    for(i = index - 1; i < self->size - 1; i++)
    {
        self->arr[i] = self->arr[i + 1];
    }
}

static void resetStatus(list_t * self)
{
    self->status = LIST_OK;
}

list_status_t list_getStatus(list_t * self)
{
    return self->status;
}
