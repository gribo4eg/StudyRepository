#ifndef GLOSSARY_H_INCLUDED
#define GLOSSARY_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "folder.h"
#include "file.h"

typedef struct gloss glossary;
typedef struct gloss_s gloss_t;

gloss_t * glossary_newGloss(void);

void glossary_freeGloss(gloss_t * glos);

void glossary_fillGloss(gloss_t * glos, folder_t * folder);
void glossary_printGloss(gloss_t * glos);
#endif // GLOSSARY_H_INCLUDED
