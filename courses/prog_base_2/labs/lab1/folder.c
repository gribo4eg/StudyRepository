#include "folder.h"
#include "file.h"


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

folder_t * folder_newFolder(void)
{
    folder_t * folder = malloc(sizeof(struct folder_s));
    folder->size = 0;
    folder->status = FOLDER_EMPTY;
    return folder;
}

file_t * folder_newFile(folder_t * folder)
{
    if(folder == NULL)
        return NULL;
    if(folder->size == 10)
    {
        folder->status = FOLDER_FULL;
        return NULL;
    }
    if(folder->size + 1 == 10)
    {
        folder->status = FOLDER_FULL;
    }

    file_t * file = malloc(sizeof(struct file_s));

    folder->files[(folder->size)++] = file;

    folder->status = FOLDER_OK;
    file->status = FILE_EMPTY;
    return file;
}

void folder_freeFolder(folder_t * folder)
{
    register int i;
    if(folder == NULL)
        return NULL;
    if(folder->status != FOLDER_EMPTY)
    {
        for(i=folder->size-1 ; i>=0; i--)
            file_freeFile(folder, folder->files[i]);
    }
    free(folder);
}

char * folder_getData(folder_t * folder)
{
    register int i;
    if(folder == NULL)
        return NULL;
    char folderData[100];
    for(i = 0; i<folder_getSize(folder); i++)
    {
        if(i == 0)
        {
            strcpy(folderData, file_getData(folder, folder->files[i]));
            continue;
        }
        strcat(folderData, " ");
        strcat(folderData, file_getData(folder, folder->files[i]));
    }
    return folderData;
}

int folder_getSize(folder_t * folder)
{
    return folder->size;
}

folder_status_t folder_getStatus(folder_t * folder)
{
    return folder->status;
}
