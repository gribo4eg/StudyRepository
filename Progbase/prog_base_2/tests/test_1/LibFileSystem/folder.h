#ifndef FOLDER_H_INCLUDED
#define FOLDER_H_INCLUDED

#include <stdlib.h>

#include "file.h"

typedef struct folder_s folder_t;
typedef struct file_s file_t;

folder_t * folder_newFolder(const char *folderName);

file_t * folder_newFile(folder_t* smallFolder, const char *fileName);

void folder_freeFolder(folder_t * folder);

char* folder_getName(folder_t* folder);
folder_t* folder_folderAddFolder(folder_t *bigFolder, const char* smallFolderName);
char * folder_getData(folder_t * folder);

int folder_getSize(folder_t * folder);

typedef enum folder_status_t
{
    FOLDER_OK,
    FOLDER_EMPTY,
    FOLDER_FULL
} folder_status_t;

folder_status_t folder_getStatus(folder_t * folder);

#endif // FOLDER_H_INCLUDED
