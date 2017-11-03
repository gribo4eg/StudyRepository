#include <stdlib.h>

#include "../socket/socket.h"
#include "server.h"
#include "../http/http.h"

static void server_notFound(socket_t* client);

void server_info(socket_t* client, const char* worker)
{
    char homeBuf[10224];

    sprintf(homeBuf,
        "HTTP/1.1 200 OK\n"
        "Content-Type: application/json\n"
        "Content-Length: %i\r\n\r\n"
        "\n%s", strlen(worker)+1, worker);
    socket_write_string(client, homeBuf);
    socket_close(client);
}



static void server_notFound(socket_t* client)
{
    char homeBuf[800];
    const char * pageText = "<h1>404</h1><p>Page Not Found!</p>";
    sprintf(homeBuf,
        "HTTP/1.1 404 \n"
        "Content-Type: text/html\n"
        "Content-Length: %i\n"
        "\n%s", strlen(pageText), pageText);
    free(pageText);
    socket_write_string(client, homeBuf);
    socket_close(client);
}


