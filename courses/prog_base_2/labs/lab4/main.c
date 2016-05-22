#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>

#include "worker/worker.h"
#include "socket/socket.h"

#define MAX_WORKERS 7
#define PORT 1000


int main() {
    //lib_init();

    worker_t* workers[10];

    for(int i = 0; i<10; i++){
        workers[i] = worker_new();
    }

    worker_parseWorker(workers);

    for(int i = 0; i<worker_workersCount(workers); i++){
        worker_print(workers[i]);
    }

    worker_t* worker1 = worker_new();
    int id = worker_workersCount(workers);
    worker_fill(worker1, id, "HAHA", "LOLKEK", "1993-02-13", 4, 4.5);
    worker_print(worker1);
    puts(worker_makeWorkerJSON(worker1));
    workers[id++] = worker1;

    worker_free(worker1);

    for(int i = 0; i<worker_workersCount(workers); i++)
        puts(worker_makeWorkerJSON(workers[i]));

    for(int i = 0; i<worker_workersCount(workers); i++)
        worker_free(workers[i]);
  /*  socket_t* server = socket_new();
    socket_bind(server, PORT);
    socket_listen(server);

    char buffer[10000];
    while(true){
        puts("Waiting for client...!");
        socket_t* client = socket_accept(server);

        if(kbhit()){
            char e = getch();
            if(e == 'm'){
                socket_free(client);
                break;
            }
        }

        socket_read(client, buffer, sizeof(buffer));
        printf("Request:\n%s\n", buffer);

        http_request_t request = http_request_parse(buffer);


        //socket_write(client, massage, strlen(massage));

        socket_free(client);
    }

    //worker_free(worker1);
    socket_free(server);
    lib_free();*/
	return 0;
}
