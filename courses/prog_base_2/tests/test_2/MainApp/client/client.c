#include "client.h"

#include "../socket/socket.h"
#include <winsock2.h>
#define PORT 5000

#pragma comment(lib, "ws2_32.lib")

char* getStringJSON(SOCKET Socket, char* reply);

void sendRequest(socket_t* client, const char* host)
{
    char data[200];

    sprintf(data, "GET /test/var/6?format=json HTTP/1.1\r\nHost:%s\r\n\r\n", host);
    send(client, data, strlen(data), 0);
}

static SOCKET createSocket()
{
    SOCKET Socket;
    puts("Creating socket...");
    if((Socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == INVALID_SOCKET)
    {
        printf("Could not create socket : %d", WSAGetLastError());
        WSACleanup();
        return 1;
    }
    puts("Socket created.");
    return Socket;
}

char* secondTask(const char* host)
{
    SOCKET Socket;
    struct sockaddr_in recvSockAddr;
    struct hostent * rHost;
    char* ip;

    Socket = createSocket();
    rHost = gethostbyname(host);

    ip = inet_ntoa(*(struct in_addr *)*rHost->h_addr_list);
	printf("IP address is: %s\n", ip);

    memset(&recvSockAddr, 0, sizeof(recvSockAddr));

    recvSockAddr.sin_addr.s_addr = inet_addr(ip);
    recvSockAddr.sin_family = AF_INET;
    recvSockAddr.sin_port = htons(80);

    if(connect(Socket, (struct sockaddr *)&recvSockAddr, sizeof(recvSockAddr)) == SOCKET_ERROR)
    {
        puts("Socket connect error");
        closesocket(Socket);
        WSACleanup();
        return;
    }

    char data[200];

    sprintf(data, "GET /test/var/6?format=json HTTP/1.1\r\nHost:%s\r\n\r\n", host);
    send(Socket, data, strlen(data), 0);

    char reply[20000];
    if(recv(Socket, reply, 20000, 0) == SOCKET_ERROR)
    {
        puts("Receive failed");
        closesocket(Socket);
        WSACleanup();
        return 1;
    }
    char stringJSON[100];
    strcpy(stringJSON, getStringJSON(Socket, reply));

    return stringJSON;
}

char* getStringJSON(SOCKET Socket, char* reply)
{
    char JSON[400];
    char* str;
    reply = strstr(reply, "Content-Length:");
    str = strtok(reply, "\n");
    str = strtok(NULL, "\n");
    str = strtok(NULL, "\n");
    strcpy(JSON, str);
    JSON[strlen(JSON)] = '\0';
    return JSON;
}

/*char* makeJSON(char* data){
    char* inJsn = NULL;
    char buffer[300];
    cJSON* workerJsn = cJSON_CreateObject();

    sprintf(buffer, "%i-%i-%i", worker->birthdate.tm_year,
                                worker->birthdate.tm_mon,
                                worker->birthdate.tm_mday);
    cJSON_AddItemToObject(workerJsn, "Birth date", cJSON_CreateString(buffer));

    inJsn = cJSON_Print(workerJsn);
    cJSON_Delete(workerJsn);
    return inJsn;
}*/
