#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>

#include <libxml/parser.h>
#include <libxml/tree.h>

#include "workers.h"

struct workers_s
{
    char name[50];
    char surname[50];
    char corp[50];
    char depart[50];
    struct tm birthdate;
    int year;
    double height;
};

workers_t * workers_newWorker()
{
    workers_t * worker = malloc(sizeof(struct workers_s));
    strcpy(worker->name, "");
    strcpy(worker->surname, "");
    strcpy(worker->corp, "");
    strcpy(worker->depart, "");
    memset(&worker->birthdate, 0, sizeof(worker->birthdate));
    worker->birthdate.tm_year = 0000;
    //worker->birthdate.tm_mday = ;
    //worker->birthdate.tm_mon = ;
    worker->year = 0000;
    worker->height = 0.0;
    return worker;
}

void workers_freeWorker(workers_t * worker)
{
    free(worker);
}

void workers_parseWorker(workers_t **worker, const char *xmlFile)
{
    int i = 0;
    xmlDoc *xDoc = xmlReadFile(xmlFile, "UTF-8", NULL);
    xmlNode *xRoot = xmlDocGetRootElement(xDoc);
    for(xmlNode *xCur = xRoot->children; xCur != NULL; xCur = xCur->next)
    {
        if(xmlStrEqual(xCur->name, "worker"))
        {
            for(xmlNode *xJ = xCur->children; xJ != NULL; xJ = xJ->next)
            {
                if(xmlStrEqual(xJ->name, "name"))
                    strcpy(worker[i]->name, xmlNodeGetContent(xJ));
                else if(xmlStrEqual(xJ->name, "surname"))
                    strcpy(worker[i]->surname, xmlNodeGetContent(xJ));
                else if(xmlStrEqual(xJ->name, "corporation"))
                {
                    strcpy(worker[i]->corp, xmlGetProp(xJ, "name"));
                    strcpy(worker[i]->depart, xmlNodeGetContent(xJ));
                }
                else if(xmlStrEqual(xJ->name, "birthdate"))
                    sscanf(xmlNodeGetContent(xJ), "%i-%i-%i", &worker[i]->birthdate.tm_year,
                           &worker[i]->birthdate.tm_mon, &worker[i]->birthdate.tm_mday);
                else if(xmlStrEqual(xJ->name, "year"))
                    worker[i]->year = atoi(xmlNodeGetContent(xJ));
                else if(xmlStrEqual(xJ->name, "height"))
                    worker[i]->height = atof(xmlNodeGetContent(xJ));
            }
            i++;
        }
    }
    xmlFreeDoc(xDoc);
}

void workers_printWorker(workers_t * worker)
{
    printf("Name: %s\nSurname: %s\nCorporation: \"%s\"\nDepartment:<%s>\nBirth date: %i-%i-%i\nBecome worker in: %i\nHeight: %.2f\n\n----------------------\n\n",
           worker->name, worker->surname, worker->corp, worker->depart,
           worker->birthdate.tm_year, worker->birthdate.tm_mon, worker->birthdate.tm_mday,
           worker->year, worker->height);
}
