#ifndef SERVER_H_INCLUDED
#define SERVER_H_INCLUDED

#include "../http/http.h"
#include "../socket/socket.h"
#include "../worker/worker.h"

void server_info(socket_t* client, const char* worker);

#endif // SERVER_H_INCLUDED
