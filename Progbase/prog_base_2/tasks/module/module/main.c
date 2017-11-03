#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#include"list.h"

int main(void)
{
    list_t * myList = list_newList();
    assert(list_getStatus(myList) == LIST_OK);
    assert(list_size(myList) == 0);
    list_delete(myList, 1);
    assert(list_getStatus(myList) == LIST_EMPTY);
    list_add(myList, 30, 5);
    assert(list_getStatus(myList) == LIST_OK);
    assert(list_size(myList) == 1);
    list_add(myList, -5, 1);
    assert(list_getStatus(myList) == LIST_OK);
    assert(list_size(myList) == 2);
    list_add(myList, 0, 2);
    assert(list_getStatus(myList) == LIST_OK);
    assert(list_size(myList) == 3);
    assert(list_positive(myList) == 1);
    assert(list_zero(myList) == 1);
    assert(list_negative(myList) == 1);
    list_delete(myList, 1);
    list_delete(myList, 2);
    list_delete(myList, 3);
    assert(list_getStatus(myList) == LIST_EMPTY);
    list_removeList(myList);
    puts("GOOD BOY!!! Mission COMPLETE!");
    return EXIT_SUCCESS;
}
