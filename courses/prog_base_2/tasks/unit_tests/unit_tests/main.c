#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>

#include <cmocka.h>

#include "list.h"

static void new_void_zeroSize(void ** state)
{
    list_t * lt = list_newList();
    assert_int_equal(list_size(lt), 0);
    list_removeList(lt);
}

static void new_void_statusOk(void ** state)
{
    list_t * lt = list_newList();
    assert_int_equal(list_getStatus(lt), LIST_OK);
    list_removeList(lt);
}

static void add_oneValue_sizeOne(void ** state)
{
    list_t * lt = list_newList();
    list_add(lt, 2, 1);
    assert_int_equal(list_size(lt), 1);
    list_removeList(lt);
}

static void add_twoValue_sizeTwo(void ** state)
{
    list_t * lt = list_newList();
    list_add(lt, 111, 1);
    list_add(lt, -1234, 2);
    assert_int_equal(list_size(lt), 2);
    list_removeList(lt);
}

static void delete_oneAddValue_returnSizeZero(void **stzte)
{
    list_t * lt = list_newList();
    list_add(lt, 5, 1);
    list_delete(lt, 1);
    assert_int_equal(list_size(lt), 0);
    list_removeList(lt);
}

static void positive_onePositiveValue_countPositive(void ** state)
{
    list_t * lt = list_newList();
    list_add(lt, 5, 1);
    assert_int_equal(list_positive(lt), 1);
    list_removeList(lt);
}

static void negative_oneNegativeValue_countNegative(void ** state)
{
    list_t * lt = list_newList();
    list_add(lt, -5, 1);
    assert_int_equal(list_negative(lt), 1);
    list_removeList(lt);
}

static void zero_oneZeroValue_countZero(void ** state)
{
    list_t * lt = list_newList();
    list_add(lt, 0, 1);
    assert_int_equal(list_zero(lt), 1);
    list_removeList(lt);
}


int main(void)
{
    const struct CMUnitTest tests[]=
    {
        cmocka_unit_test(new_void_zeroSize),
        cmocka_unit_test(new_void_statusOk),
        cmocka_unit_test(add_oneValue_sizeOne),
        cmocka_unit_test(add_twoValue_sizeTwo),
        cmocka_unit_test(delete_oneAddValue_returnSizeZero),
        cmocka_unit_test(positive_onePositiveValue_countPositive),
        cmocka_unit_test(negative_oneNegativeValue_countNegative),
        cmocka_unit_test(zero_oneZeroValue_countZero),

    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
