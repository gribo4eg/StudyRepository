#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <stdbool.h>

#include <cmocka.h>

#include "queue.h"

static void new_void_zeroSize(void ** state)
{
    queue_t * queue = queue_new();
    assert_int_equal(0, queue_size(queue));
    queue_free(queue);
}

static void new_void_statusEmpty(void ** state)
{
    queue_t * queue = queue_new();
    assert_int_equal(QUEUE_EMPTY, queue_status(queue));
    queue_free(queue);
}

static void enqueue_value_sizeOne(void ** state)
{
    queue_t * queue = queue_new();
    double value = 15.46;
    queue_enqueue(queue, value);
    assert_int_equal(1, queue_size(queue));
    queue_free(queue);
}

static void random_randomValue_sizeOne(void ** state)
{
    queue_t * queue = queue_new();
    queue_random(queue);
    assert_int_equal(1, queue_size(queue));
    queue_free(queue);
}

static void enqueue_value_statusOk(void ** state)
{
    queue_t * queue = queue_new();
    double value = 15.46;
    queue_enqueue(queue, value);
    assert_int_equal(QUEUE_OK, queue_status(queue));
    queue_free(queue);
}

static void enqueue_tenValues_statusFull(void ** state)
{
    queue_t * queue = queue_new();
    for(int i = 0; i<MAX_QUEUE_SIZE; i++)
        queue_random(queue);

    assert_int_equal(QUEUE_FULL, queue_status(queue));
    queue_free(queue);
}

static void dequeue_value_statusEmpty(void ** state)
{
    queue_t * queue = queue_new();
    for(int i = 0; i<MAX_QUEUE_SIZE; i++)
        queue_random(queue);

    assert_int_equal(QUEUE_FULL, queue_status(queue));
    queue_free(queue);
}

static void isEmpty_void_true(void ** state)
{
    queue_t * queue = queue_new();
    assert_true(queue_isEmpty(queue));
    queue_free(queue);
}

static void isEmpty_value_false(void ** state)
{
    queue_t * queue = queue_new();
    queue_random(queue);
    assert_false(queue_isEmpty(queue));
    queue_free(queue);
}

static void isFull_void_false(void ** state)
{
    queue_t * queue = queue_new();
    assert_false(queue_isFull(queue));
    queue_free(queue);
}

static void isFull_tenValues_true(void ** state)
{
    queue_t * queue = queue_new();
    for(int i = 0; i<MAX_QUEUE_SIZE; i++)
        queue_random(queue);

    assert_true(queue_isFull(queue));
    queue_free(queue);
}

void cmocka_tests(void)
{
    const struct CMUnitTest tests[]=
    {
        cmocka_unit_test(new_void_zeroSize),
        cmocka_unit_test(new_void_statusEmpty),
        cmocka_unit_test(enqueue_value_sizeOne),
        cmocka_unit_test(random_randomValue_sizeOne),
        cmocka_unit_test(enqueue_value_statusOk),
        cmocka_unit_test(enqueue_tenValues_statusFull),
        cmocka_unit_test(dequeue_value_statusEmpty),
        cmocka_unit_test(isEmpty_void_true),
        cmocka_unit_test(isEmpty_value_false),
        cmocka_unit_test(isFull_void_false),
        cmocka_unit_test(isFull_tenValues_true)
    };

    cmocka_run_group_tests(tests, NULL, NULL);
}
