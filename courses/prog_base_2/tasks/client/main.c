#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>

#include "client.h"

#pragma comment(lib, "ws2_32.lib")

int main(int argc, char *argv[])
{
    WSADATA wsa;
    struct sockaddr_in recvSocketAddr;
    SOCKET Socket;
    struct hostent * rHost;
    char* ip;
    char reply[20000], myArray[50];
    const char * hostName = "pb-homework.appspot.com";

    memset(reply, 0, 20000);

    if(initializeWinsock(wsa))
        return 1;

    Socket = createSocket();


    rHost = gethostbyname(hostName);

	ip = inet_ntoa(*(struct in_addr *)*rHost->h_addr_list);
	printf("IP address is: %s\n", ip);

    memset(&recvSocketAddr, 0, sizeof(recvSocketAddr));

    recvSocketAddr.sin_addr.s_addr = inet_addr(ip);
    recvSocketAddr.sin_family = AF_INET;
    recvSocketAddr.sin_port = htons(80);

    connectToServer(Socket, recvSocketAddr);

    sendRequest(Socket, hostName);

    strcpy(reply, receiveReply(Socket));

    sendSecret(Socket, hostName, reply);

    strcpy(reply, receiveReply(Socket));

    strcpy(myArray, getString(Socket, reply));

    strcpy(myArray, sortArray(myArray, getArraySize(myArray)));

    postToServer(Socket, hostName, myArray);

    puts(receiveReply(Socket));

    closesocket(Socket);
    WSACleanup();

    return 0;
}
