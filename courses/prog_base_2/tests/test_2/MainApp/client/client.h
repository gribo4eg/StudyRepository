#ifndef CLIENT_H_INCLUDED
#define CLIENT_H_INCLUDED

#include <winsock2.h>
#include "../socket/socket.h"

void sendRequest(socket_t* socket, const char* host);

#endif // CLIENT_H_INCLUDED
