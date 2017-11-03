#include "godBlessRandom.h"
#include <cstdlib>

void getCoords(int playerCoordX, int playerCoordY, int* newX, int* newY)
{
    if(playerCoordX < 700 && playerCoordY < 240)
    {
        switch(1 + rand()%4)
        {
        case 1: *newX = 235;    *newY = 668;    break;
        case 2: *newX = 911;    *newY = 59;     break;
        case 3: *newX = 1359;   *newY = 285;    break;
        case 4: *newX = 1848;   *newY = 668;    break;
        }
    }
    else if( playerCoordX < 700 && playerCoordY < 500)
    {
        switch(1 + rand()%4)
        {
        case 1: *newX = 1166;   *newY = 573;    break;
        case 2: *newX = 911;    *newY = 59;     break;
        case 3: *newX = 1359;   *newY = 285;    break;
        case 4: *newX = 1848;   *newY = 668;    break;
        }
    }
    else if( playerCoordX < 700 && playerCoordY < 800)
    {
        switch(1 + rand()%4)
        {
        case 1: *newX = 34;     *newY = 32;     break;
        case 2: *newX = 911;    *newY = 59;     break;
        case 3: *newX = 1359;   *newY = 285;    break;
        case 4: *newX = 1848;   *newY = 668;    break;
        }
    }
    else if( playerCoordX < 1500 && playerCoordY < 240)
    {
        switch(1 + rand()%4)
        {
        case 1: *newX = 34;     *newY = 32;     break;
        case 2: *newX = 911;    *newY = 59;     break;
        case 3: *newX = 1359;   *newY = 285;    break;
        case 4: *newX = 1848;   *newY = 668;    break;
        }
    }
    else if( playerCoordX < 1500 && playerCoordY < 500)
    {
        switch(1 + rand()%4)
        {
        case 1: *newX = 34;     *newY = 32;     break;
        case 2: *newX = 397;    *newY = 284;    break;
        case 3: *newX = 235;    *newY = 668;    break;
        case 4: *newX = 1848;   *newY = 668;    break;
        }
    }
    else if( playerCoordX < 1500 && playerCoordY < 800)
    {
        switch(1 + rand()%4)
        {
        case 1: *newX = 34;     *newY = 32;     break;
        case 2: *newX = 1359;   *newY = 285;    break;
        case 3: *newX = 397;    *newY = 284;    break;
        case 4: *newX = 911;    *newY = 59;     break;
        }
    }
    else if( playerCoordX < 2028 && playerCoordY < 240)
    {
        switch(1 + rand()%4)
        {
        case 1: *newX = 34;     *newY = 32;     break;
        case 2: *newX = 1166;   *newY = 573;    break;
        case 3: *newX = 397;    *newY = 284;    break;
        case 4: *newX = 911;    *newY = 59;     break;
        }
    }
    else if( playerCoordX < 2028 && playerCoordY < 800)
    {
        switch(1 + rand()%4)
        {
        case 1: *newX = 34;     *newY = 32;     break;
        case 2: *newX = 1359;   *newY = 285;    break;
        case 3: *newX = 397;    *newY = 284;    break;
        case 4: *newX = 911;    *newY = 59;     break;
        }
    }

    }
