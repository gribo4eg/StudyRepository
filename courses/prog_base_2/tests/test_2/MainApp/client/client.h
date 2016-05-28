#ifndef CLIENT_H_INCLUDED
#define CLIENT_H_INCLUDED

#include <winsock2.h>
#include "../socket/socket.h"

void sendRequest(socket_t* socket, const char* host);
char* secondTask(const char* host);
char* getStringJSON(SOCKET Socket, char* reply);

#endif // CLIENT_H_INCLUDED
