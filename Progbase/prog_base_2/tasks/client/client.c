#include "client.h"

int initializeWinsock(WSADATA wsa)
{
    puts("Initialising Winsock...");
    if(WSAStartup(MAKEWORD(2,2), &wsa) != 0)
    {
        printf("Failed. Error Code : %d", WSAGetLastError());
        return 1;
    }
    puts("Initialised.");
    return 0;
}

SOCKET createSocket()
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

void connectToServer(SOCKET Socket, SOCKADDR_IN receiveSocketAddr)
{
    puts("Connecting to server...");
    if(connect(Socket, (struct sockaddr *)&receiveSocketAddr, sizeof(receiveSocketAddr)) == SOCKET_ERROR)
    {
        puts("Socket connect error");
        closesocket(Socket);
        WSACleanup();
        return;
    }
    puts("Connected.");
}

void sendRequest(SOCKET Socket, const char* host)
{
    char data[200];

    sprintf(data, "GET /var/3 HTTP/1.1\r\nHost:%s\r\n\r\n", host);

    puts("Sending request...");
    send(Socket, data, strlen(data), 0);
    puts("Request send.");
}

char* receiveReply(SOCKET Socket)
{
    char reply[20000];
    if(recv(Socket, reply, 20000, 0) == SOCKET_ERROR)
    {
        puts("Receive failed");
        closesocket(Socket);
        WSACleanup();
        return 1;
    }
    puts("Reply received!\n");
    return reply;
}

void sendSecret(SOCKET Socket, const char* host, char* reply)
{
    char data[200];
    char secret[50];

    strcpy(secret, strstr(reply, "secret"));
    sprintf(data, "GET /var/3?%s HTTP/1.1\r\nHost:%s\r\n\r\n", secret, host);

    puts("Sending secret-request...");
    send(Socket, data, strlen(data), 0);
    puts("Secret-request send.");
}

char* getString(SOCKET Socket, char* reply)
{
    char numbers[40];
    char* str;
    reply = strstr(reply, "Content-Length:");
    str = strtok(reply, "\n");
    str = strtok(NULL, "\n");
    str = strtok(NULL, "\n");
    strcpy(numbers, str);
    numbers[strlen(numbers)] = '\0';
    return numbers;
}

int getArraySize(const char* numbers)
{
    int size = 0;
    char* str = numbers;
    while(*str != NULL)
    {
        if(*str == ' ')
            size++;
        *str++;
    }
    size++;
    return size;
}

char* sortArray(char* numbers, int size)
{
    char* str, temp[10];
    register int i, j;
    int position = 0;
    int intArr[size], minimal, tmp;

    str = strtok(numbers, " ");
    while(str != 0)
    {
        intArr[position] = atoi(str);
        position++;
        str = strtok(NULL, " ");
    }

    for(i = 0; i<size - 1; i++)
        for(j = 0; j < size -1; j++)
            if(intArr[j] > intArr[j+1])
            {
                tmp = intArr[j];
                intArr[j] = intArr[j+1];
                intArr[j+1] = tmp;
            }

    for(i = 0; i<position; i++)
    {
        if(i == 0)
        {
            itoa(intArr[i], numbers, 10);
            continue;
        }
        strcat(numbers, " ");
        itoa(intArr[i], temp, 10);
        strcat(numbers, temp);
    }
    numbers[strlen(numbers)] = '\0';
    return numbers;
}

void postToServer(SOCKET Socket, const char* host, char* message)
{
    char result[20];
    char data[200];
    sprintf(result, "result=%s", message);
    result[strlen(result)] = '\0';
    sprintf(data, "POST %s/var/3 HTTP/1.1\r\nContent-Length: %i\r\n\r\n%s\r\n", host, strlen(result), result);
    send(Socket, data, strlen(data), 0);
}
