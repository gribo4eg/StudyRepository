#ifndef FOR_USER_H_INCLUDED
#define FOR_USER_H_INCLUDED

#include "user.h"

typedef struct event_s event_t;
typedef struct queue_s queue_t;

typedef enum event_status_t{WRONG_DATA = -2, BAD_EVENT, FIRST, SECOND, THIRD} event_status_t;
typedef enum queue_status_t{QUEUE_EMPTY, QUEUE_FULL, QUEUE_OK} queue_status_t;
typedef void (*alert_foo)(user_t* receiver, event_t* event);

event_t * event_new(const char* name);
void event_free(event_t* event);

queue_t * queue_new(void);
void queue_free(queue_t * queue);

void event_addReceiver(event_t* event, user_t* user, alert_foo alert);

char* event_name(event_t* event);
char * user_username(user_t* user);

void queue_start(event_t* first, event_t* second, event_t* third, queue_t* queue);


#endif // FOR_USER_H_INCLUDED
