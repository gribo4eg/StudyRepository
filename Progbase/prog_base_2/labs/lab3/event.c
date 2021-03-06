#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "queue.h"
#include "event.h"
#include "user.h"

#define MAX_RECEIVERS 10

typedef struct receiver_s
{
    user_t* receiver;
    alert_foo alert;
}receiver_t;

struct event_s
{
    char eventName[256];
    receiver_t* receiveArr;
    int rec_count;
};

event_t * event_new(const char* name)
{
    event_t * event = malloc(sizeof(struct event_s));
    event->receiveArr = malloc(MAX_RECEIVERS * sizeof(struct receiver_s));
    event->rec_count = 0;
    strcpy(event->eventName, name);
    return event;
}

void event_free(event_t* event)
{
    free(event->receiveArr);
    free(event);
}

char* event_name(event_t* event)
{
    return event->eventName;
}

int event_receiversCount(event_t* event)
{
    return event->rec_count;
}

void event_addReceiver(event_t* event, user_t* user, alert_foo alert)
{
    event->receiveArr[event->rec_count].receiver = user;
    event->receiveArr[event->rec_count].alert = alert;
    event->rec_count++;
}

void event_happend(event_t* event)
{
    for(int i = 0; i<event->rec_count; i++)
    {
        event->receiveArr[i].alert(event->receiveArr[i].receiver, event);
    }
}
