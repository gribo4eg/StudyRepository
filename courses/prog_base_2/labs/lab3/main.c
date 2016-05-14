#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>
#include <stdbool.h>

/*#include "queue.h"
#include "event.h"
#include "user.h"*/
#include "for_user.h"
#include "unit_test.h"

void alert_callback(user_t * receiver, event_t * event);

int main(void)
{
    srand(time(NULL));

    cmocka_tests();
    getchar();
    system("cls");

    queue_t * queue = queue_new();

    user_t * user1 = user_new("User1");
    user_t * user2 = user_new("User2");
    user_t * user3 = user_new("User3");

    user_t * userArr[] =
    {
        user1,
        user2,
        user3
    };

    int userArrSize = sizeof(userArr)/sizeof(userArr[0]);

    event_t* firstEvent = event_new("First event");
    event_t* secondEvent = event_new("Second event");
    event_t* thirdEvent = event_new("Third event");

    event_addReceiver(firstEvent, user1, alert_callback);
    event_addReceiver(firstEvent, user2, alert_callback);
    event_addReceiver(secondEvent, user1, alert_callback);
    event_addReceiver(thirdEvent, user1, alert_callback);
    event_addReceiver(secondEvent, user2, alert_callback);
    event_addReceiver(thirdEvent, user3, alert_callback);
    event_addReceiver(secondEvent, user3, alert_callback);
    event_addReceiver(thirdEvent, user2, alert_callback);

    while(!kbhit() && queue_status(queue) != QUEUE_FULL)
    {
        queue_start(firstEvent, secondEvent, thirdEvent, queue);
    }

    event_free(firstEvent);
    event_free(secondEvent);
    event_free(thirdEvent);

    for(int i = 0; i<userArrSize; i++)
        user_free(userArr[i]);

    queue_free(queue);

    return 0;
}

void alert_callback(user_t * receiver, event_t * event)
{
    printf("User: %s\n\tReceived massage from: %s\n\n", user_username(receiver),
            event_name(event));
}
