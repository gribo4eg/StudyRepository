#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "read.h"
#include "sqlite3.h"
#include "list.h"
#include "socket/socket.h"
#include "http/http.h"
#include "database.h"
#include "client/client.h"

#define WORKERS_MAX 7
#define PORT 5000

int main()
{
    lib_init();

    worker_t* myWorker = worker_new();
    autor_t* myAuthor = autor_new();

    worker_fill(myWorker, "Sasha", "Voloshchenko", 6);
    char* worker = worker_makeWorkerJSON(myWorker);

    socket_t* server = socket_new();
    socket_bind(server, PORT);
    socket_listen(server);

    char buffer[10000];

    const char* hostName = "pb-homework.appspot.com";

    char toReturn[100];
    strcpy(toReturn, secondTask(hostName));


    while(true){
        puts("Waiting for client...");
        socket_t* client = socket_accept(server);

        if(socket_read(client, buffer, sizeof(buffer)) <=0)
        {
            socket_close(client);
            socket_free(client);
            continue;
        }

        printf("Request:\n%s\n", buffer);

        http_request_t request = http_request_parse(buffer);
        if(!strcmp(request.uri, "/info"))
        {
            server_info(client, worker);
        }if(!strcmp(request.uri, "/external"))
        {
            autor_fromJSON(myAuthor, toReturn);
            char* sendd = autor_makeAutorJSON(myAuthor);
            server_info(client, sendd);
        }
        if(kbhit()){
                char e = getch();
                if(e == 'm'){
                    socket_free(client);
                    break;
                }
            }

        socket_free(client);
    }

    socket_free(server);

    worker_free(myWorker);
    autor_free(myAuthor);
    lib_free();

    return 0;
}
