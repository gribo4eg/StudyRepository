#include <stdio.h>
#include <stdlib.h>

#include <windows.h>

#include "folder.h"
#include "file.h"

int main()
{
    folder_t* bigFolder = folder_newFolder("Big Folder");
    folder_t* smallFolder = folder_folderAddFolder(bigFolder, "SmallFolder1");
    file_t* file1 = folder_newFile(smallFolder, "File1");
    char massage[1000];
    strcpy(massage, file_getData(file1));
    puts(massage);
    strcpy(massage, "GG WP NICE GEME MLG GO PRO ALALALALALA\n I LOVE RUSLAN <3!\n :3");
    file_fillData(file1, massage);


    strcpy(massage, file_getData(file1));
    puts(massage);

    puts(folder_getName(bigFolder));

    file_freeFile(smallFolder, file1);
    folder_freeFolder(smallFolder);
    folder_freeFolder(bigFolder);
    return 0;
}
