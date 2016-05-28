#ifndef CLIENT_H_INCLUDED
#define CLIENT_H_INCLUDED

#include <winsock2.h>
#include "../socket/socket.h"

int initializeWinsock(WSADATA wsa);
SOCKET createSocket(void);
void connectToServer(SOCKET Socket, SOCKADDR_IN receiveSocketAddr);
void sendRequest(socket_t* socket, const char *host);
void sendSecret(SOCKET Socket, const char* host, char* reply);
char* receiveReply(SOCKET Socket);
char* getString(SOCKET Socket, char* reply);
int getArraySize(const char* numbers);
char* sortArray(char* numbers, int size);
void postToServer(SOCKET Socket, const char* host, char* message);

#endif // CLIENT_H_INCLUDED
