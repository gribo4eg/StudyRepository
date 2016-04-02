#include "file.h"
#include "folder.h"

struct folder_s
{
    int size;
    file_t *files[10];
    folder_status_t status;
};

struct file_s
{
    char * data;
    file_status_t status;
};

void file_fillData(folder_t* folder, file_t* file, char* data)
{
    if(folder == NULL || file == NULL)
        return;
    if(data == NULL)
    {
        file->status = FILE_EMPTY;
        return;
    }

    file->data = (char*)malloc(FILE_SIZE * sizeof(char));//100 symbols in one string

    strcpy(file->data, data);

    file->status = FILE_OK;
}

void file_deleteData(folder_t * folder, file_t * file)
{
    if(folder == NULL || file == NULL || folder->status == FOLDER_EMPTY || file->status == FILE_EMPTY)
        return NULL;
    free(file->data);
    file->status = FILE_EMPTY;
}

char * file_getData(folder_t * folder, file_t * file)
{
    if(folder == NULL || file == NULL || folder->status == FOLDER_EMPTY || file->status == FILE_EMPTY)
        return;
    return file->data;
}

void file_freeFile(folder_t * folder, file_t* file)
{
    if(folder == NULL || file == NULL)
        return NULL;
    if(file->status == FILE_EMPTY)
        return NULL;
    if(file_getStatus(file) != FILE_EMPTY)
        free(file->data);
    free(file);
    (folder->size)--;
}

file_status_t file_getStatus(file_t * file)
{
    return file->status;
}
