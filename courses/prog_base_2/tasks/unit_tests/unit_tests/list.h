#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include<stdlib.h>

typedef struct list_s list_t;

list_t * list_newList(void);

void list_removeList(list_t * self);

void list_add(list_t * self, int value, int index);
int list_delete(list_t * self, int index);
int list_size(list_t * self);
int list_positive(list_t * self);
int list_negative(list_t * self);
int list_zero(list_t * self);

typedef enum list_status_t
{
    LIST_OK,
    LIST_FULL,
    LIST_EMPTY
} list_status_t;

list_status_t list_getStatus(list_t * self);
#endif // LIST_H_INCLUDED
