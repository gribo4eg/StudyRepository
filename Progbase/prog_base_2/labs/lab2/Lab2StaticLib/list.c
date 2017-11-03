#include "list.h"

struct list_s
{
    int  *arr;
    int size;
};

static int isEmpty(list_t * list);
static int isFull(list_t * list);

list_t * list_newList()
{
    list_t * list = malloc(sizeof(struct list_s));
    list->arr = malloc(MAX_LIST_SIZE * sizeof(int));
    list->size = 0;
    return list;
}

void list_freeList(list_t * list)
{
    free(list->arr);
    free(list);
}

void list_add(list_t * list, int value)
{
    if(isFull(list) || value < -128 || value > 127)
        return;
    list->arr[list->size++] = value;
}

int list_deleteElement(list_t * list)
{
    if(isEmpty(list))
        return;
    return list->arr[--list->size];
}

void list_printList(list_t * list)
{
    register int i;
    puts("\nYour list:\n");
    for(i = 0; i<list->size; i++)
        printf("%i\t", list->arr[i]);
    puts(" ");
}

int list_getData(list_t * list, int index)
{
    if(isEmpty(list) || index < 0 ||
       index >= list->size)
        return;
    return list->arr[index];
}

int list_getSize(list_t * list)
{
    return list->size;
}

static int isEmpty(list_t * list)
{
    return 0 == list->size;
}

static int isFull(list_t * list)
{
    return MAX_LIST_SIZE == list->size;
}
