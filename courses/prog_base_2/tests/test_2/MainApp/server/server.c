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

static char* server_getAllWorkersJSON(worker_t** workers)
{
    int count = worker_workersCount(workers);
    char allOfTHem[2000] = "";
    for(int i = 0; i < count; i++)
    {
        strcat(allOfTHem, worker_makeWorkerJSON(workers[i]));
    }
    //puts(allOfTHem);
    return allOfTHem;
}

static void server_sendWorkersJSON(socket_t* client, worker_t** workers)
{
    char homeBuf[10224];
    char pageText[1000];
    strcpy(pageText, server_getAllWorkersJSON(workers));
    sprintf(homeBuf,
        "HTTP/1.1 200 OK\n"
        "Content-Type: application/json\n"
        "Content-Length: %i\r\n\r\n"
        "\n%s", strlen(pageText)+1, pageText);

    socket_write_string(client, homeBuf);
    socket_close(client);
}

static char* server_getAllWorkersHTML(worker_t** workers)
{
    int count = worker_workersCount(workers);
    char allOfTHem[10000] = "<p>";
    char one[1000];
    for(int i = 0; i < count; i++)
    {
        sprintf(one,
            "      Name: <a href=\"/workers/%i\">%s</a><br><br>",
            i, worker_getName(workers[i]));
        strcat(allOfTHem, one);
            //puts(allOfTHem);
    }
    strcat(allOfTHem, "</p>");
    return allOfTHem;
}

static void server_sendWorkersHTML(socket_t* client, worker_t** workers)
{
    char homeBuf[10224];
    char* pageText = server_getAllWorkersHTML(workers);
    char request[2000] = "<head><title>Workers</title></head><h1>Workers</h1>";
    strcat(request, pageText);
    sprintf(homeBuf,
        "HTTP/1.1 200 OK\n"
        "Content-Type: text/html\n"
        "Content-Length: %i\n"
        "Connection: keep-alive\n"
        "\n%s", strlen(request), request);

    free(pageText);
    socket_write_string(client, homeBuf);
    socket_close(client);
}

static void server_getByIdJSON(http_request_t request, socket_t* client, worker_t** workers)
{
    int id;
    char* getId = strpbrk(request.uri, "0123456");
    int count = worker_workersCount(workers);
    if(getId)
    {
        id = atoi(getId);
        if(id>6 || id<0 || id>=count)
        {
            socket_write_string(client, "Wrong ID");
            return;
        }
    }
    else
    {
        server_notFound(client);
        return;
    }
    char buffer[1000] = "";
    char* worker = worker_makeWorkerJSON(workers[id]);

    sprintf(buffer,
        "HTTP/1.1 200 OK\n"
        "Content-Type: application/json\n"
        "Content-Length: %i\r\n\r\n"
        "\n%s", strlen(worker)+1, worker);

    socket_write_string(client, buffer);
    socket_close(client);
}

static char* server_getWorkerHTML(worker_t* worker)
{
    char one[1000] = "";
    sprintf(one,
            "      Name: %s<br>"
            "   Surname: %s<br>"
            "Birth date: %s<br>"
            "Experience: %i<br>"
            "    Rating: %.2f<br><br>",
            worker_getName(worker),
            worker_getSurname(worker), worker_getBirthdate(worker),
            worker_getExp(worker), worker_getRate(worker));
    return one;
}

static void server_getByIdHTML(http_request_t request, socket_t* client, worker_t** workers)
{
    int id;
    char* getId = strpbrk(request.uri, "0123456");
    int count = worker_workersCount(workers);
    if(getId)
    {
        id = atoi(getId);
        if(id>6 || id<0 || id>=count)
        {
            socket_write_string(client, "<h1>Wrong ID</h1><p><a href=\"/workers/\">All workers</a></p>");
            return;
        }
    }
    else
    {
        server_notFound(client);
        return;
    }
    char toSend[2000];
    char buffer[2000] = "<head><title>Worker</title></head><h1>Worker</h1><p><a href=\"/workers/\">All workers</a></p><p>";
    char* worker = server_getWorkerHTML(workers[id]);
    strcat(buffer, worker);
    strcat(buffer, "</p>");

    sprintf(toSend,
        "HTTP/1.1 200 OK\n"
        "Content-Type: text/html\n"
        "Content-Length: %i\r\n\r\n"
        "\n%s", strlen(buffer), buffer);
    free(worker);
    socket_write_string(client, toSend);
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

/*void server_answerRequest(http_request_t request, socket_t* client, worker_t** workers)
{
    puts(request.method);
    puts(request.uri);
    if(!strcmp(request.uri, "/")){
        server_homepage(client);
    }else
    if(!strcmp(request.uri, "/api/workers") || !strcmp(request.uri, "/api/workers/"))
    {
        server_sendWorkersJSON(client, workers);
    }else
    if(!strcmp(request.uri, "/workers") || !strcmp(request.uri, "/workers/"))
    {
        server_sendWorkersHTML(client, workers);
    }else
    if(strncmp(request.uri, "/api/workers/", 13) == 0)
    {
        if(!strcmp(request.method, "GET"))
        {
            server_getByIdJSON(request, client, workers);
        }
    }else
    if(strncmp(request.uri, "/workers/", 9) == 0)
    {
        if(!strcmp(request.method, "GET"))
        {
            server_getByIdHTML(request, client, workers);
        }
    }
        else server_notFound(client);
}*/

