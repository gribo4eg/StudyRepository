#include <stdlib.h>

#include "folder.h"
#include "file.h"
#include "list.h"


struct folder_s
{
    int size;
    char name[256];
    list_t *folders;
    list_t *files;
    folder_status_t status;
};

struct file_s
{
    char name[256];
    char * data;
    file_status_t status;
};

folder_t * folder_newFolder(const char *folderName)
{
    folder_t * folder = malloc(sizeof(struct folder_s));
    folder->folders = list_new();
    folder->files = list_new();
    strcpy(folder->name, folderName);
    folder->size = 0;
    folder->status = FOLDER_EMPTY;
    return folder;
}

folder_t* folder_folderAddFolder(folder_t *bigFolder, const char* smallFolderName)
{
    folder_t* smallFolder = folder_newFolder(smallFolderName);
    list_push_back(bigFolder->folders, (folder_t*)smallFolder);
    (bigFolder->size)++;
    return smallFolder;
}

file_t * folder_newFile(folder_t* smallFolder, const char *fileName)
{
    file_t * file = malloc(sizeof(struct file_s));
    strcpy(file->name, fileName);
    list_push_back(smallFolder->files, (file_t*)file);

    smallFolder->status = FOLDER_OK;
    file->status = FILE_EMPTY;
    return file;
}

void folder_freeFolder(folder_t * folder)
{
    int size = list_getSize(folder->folders);

    list_free(folder->folders);
    list_free(folder->files);
    free(folder);
}

char* folder_getName(folder_t* folder)
{
    return folder->name;
}

/*char * folder_getData(folder_t * folder)
{
    register int i;
    char folderData[300];
    for(i = 0; i<folder->size; i++)
    {
        if(file_getStatus(folder->files[i]) == FILE_EMPTY)
            continue;
        if(i == 0)
        {
            strcpy(folderData, file_getData(folder, folder->files[i]));
            continue;
        }
        strcat(folderData, " ");
        strcat(folderData, file_getData(folder, folder->files[i]));
    }
    return folderData;
}*/

/*int folder_getSize(folder_t * folder)
{
    int size;
    size = list_getSize(folder->folders);
    return
}*/

folder_status_t folder_getStatus(folder_t * folder)
{
    return folder->status;
}
