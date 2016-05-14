#ifndef EVENT_H_INCLUDED
#define EVENT_H_INCLUDED

#include <stdbool.h>

#include "queue.h"
#include "user.h"

typedef struct event_s event_t;

typedef void (*alert_foo)(user_t* receiver, event_t* event);

typedef enum event_status_t{WRONG_DATA = -2, BAD_EVENT, FIRST, SECOND, THIRD} event_status_t;

event_t * event_new(const char* name);
void event_free(event_t* event);

char* event_name(event_t* event);
int event_receiversCount(event_t* event);
void event_addReceiver(event_t* event, user_t* user, alert_foo alert);
void event_happend(event_t* event);

//event_status_t event_firstEvent(queue_t* queue);
//event_status_t event_secondEvent(queue_t* queue);
//event_status_t event_thirdEvent(queue_t* queue);

#endif // EVENT_H_INCLUDED
