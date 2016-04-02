#include <stdlib.h>  // !
#include <stdarg.h>  // !
#include <stddef.h>  // !
#include <setjmp.h>  // !

#include <cmocka.h>

#include "folder.h"
#include "file.h"
#include "glossary.h"
/*
static void new_void_folderEmpty(void **state)
{
    folder_t * folder = folder_newFolder();
    assert_int_equal(folder_getStatus(folder), FOLDER_EMPTY);
    assert_int_equal(folder_getSize(folder), 0);
    folder_freeFolder(folder);
}

static void new_folderPtr_newFileEmpty(void **state)
{
    folder_t * folder = folder_newFolder();
    file_t * file = folder_newFile(folder);
    assert_int_equal(file_getStatus(file), FILE_EMPTY);
    folder_freeFolder(folder);
}

static void newFile_folderPtr_newFile_sizeOne(void **state)
{
    folder_t * folder = folder_newFolder();
    file_t * file = folder_newFile(folder);
    assert_int_equal(folder_getStatus(folder), FOLDER_OK);
    assert_int_equal(folder_getSize(folder), 1);
    folder_freeFolder(folder);
}

static void newFile_folder_folderSizeTwo(void **state)
{
    folder_t * folder = folder_newFolder();
    file_t * file1 = folder_newFile(folder);
    file_t * file2 = folder_newFile(folder);
    assert_int_equal(folder_getSize(folder), 2);
    folder_freeFolder(folder);
}

static void fill_data_statusOk(void **state)
{
    folder_t * folder = folder_newFolder();
    file_t * file = folder_newFile(folder);
    file_fillData(folder, file, "Hello, World!");
    assert_int_equal(file_getStatus(file), FILE_OK);
    folder_freeFolder(folder);
}

static void getData_filePtr_string(void **state)
{
    char *str;
    str = (char*)malloc(20 * sizeof(char));
    folder_t * folder = folder_newFolder();
    file_t * file = folder_newFile(folder);
    file_fillData(folder, file, "Hello, World!");
    strcpy(str, "Hello, World!");
    assert_string_equal(file_getData(folder, file), str);
    folder_freeFolder(folder);
    free(str);
}

static void deleteData_filePtr_fileOk(void **state)
{
    folder_t * folder = folder_newFolder();
    file_t * file = folder_newFile(folder);
    file_fillData(folder, file, "Hello, World!");
    file_deleteData(folder, file);
    assert_int_equal(file_getStatus(file), FILE_EMPTY);
    folder_freeFolder(folder);
}

static void getFolderData_folderPtr_allData(void **state)
{
    char *str = (char*)malloc(50 * sizeof(char));
    folder_t * folder = folder_newFolder();
    file_t * file1 = folder_newFile(folder);
    file_t * file2 = folder_newFile(folder);
    file_t * file3 = folder_newFile(folder);
    //assert_int_equal(folder_getSize(folder), 3);
    file_fillData(folder, file1, "From First File");
    file_fillData(folder, file2, "From Second File");
    file_fillData(folder, file3, "From Third File");
    strcpy(str, "From First File From Second File From Third File");
    assert_string_equal(folder_getData(folder), str);
    free(str);
    folder_freeFolder(folder);
}

static void deleteData_filePtr_returnNULL(void **state)
{
    folder_t * folder = folder_newFolder();
    file_t * file = folder_newFile(folder);
    file_fillData(folder, file, "Hello, World!");
    file_deleteData(folder, file);
    assert_null(file_getData(folder, file));
    folder_freeFolder(folder);
}
*/
int main(void)
{
    /*
    const struct CMUnitTest tests[] =
    {
        cmocka_unit_test(new_void_folderEmpty),
        cmocka_unit_test(new_folderPtr_newFileEmpty),
        cmocka_unit_test(newFile_folderPtr_newFile_sizeOne),
        cmocka_unit_test(newFile_folder_folderSizeTwo),
        cmocka_unit_test(fill_data_statusOk),
        cmocka_unit_test(getData_filePtr_string),
        cmocka_unit_test(deleteData_filePtr_fileOk),
        cmocka_unit_test(deleteData_filePtr_returnNULL),
        cmocka_unit_test(getFolderData_folderPtr_allData)
    };
    */
///*
    gloss_t * dictionary = glossary_newGloss();
    folder_t * folder = folder_newFolder();
    file_t * file1 = folder_newFile(folder);
    file_t * file2 = folder_newFile(folder);
    file_t * file3 = folder_newFile(folder);

    file_fillData(folder, file1, "Hi, I am Winny");
    file_fillData(folder, file2, "Hi Hi, I am not Winny! I am Gangsta");
    file_fillData(folder, file3, "Winny is not a Gangsta");

    glossary_fillGloss(dictionary, folder);

    glossary_printGloss(dictionary);

    glossary_freeGloss(dictionary);
    folder_freeFolder(folder);
    return 0;
//*/
    //return cmocka_run_group_tests(tests, NULL, NULL);
}
