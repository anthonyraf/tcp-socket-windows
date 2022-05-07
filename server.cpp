#include <WinSock2.h>
#include <ws2tcpip.h>
#include <iostream>

#pragma comment(lib, "ws2_32.lib")
#define PORT 5000

int main(int argc, char *argv[])
{
    WSADATA WSAData;
    WSAStartup(MAKEWORD(2,0), &WSAData);

    int socketServer = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addrServer;
    addrServer.sin_family = AF_INET;
    addrServer.sin_addr.s_addr = inet_addr("127.0.0.1");
    addrServer.sin_port = htons(PORT);

    bind(socketServer, (const struct sockaddr *)&addrServer, sizeof(addrServer));
    std::cout << "bind : " << socketServer << std::endl;


    listen(socketServer, 5);
    std::cout << "listen" << std::endl;

    struct sockaddr_in addrClient;
    socklen_t csize = sizeof(addrClient);
    int socketClient = accept(socketServer, (struct sockaddr *)&addrClient, &csize);
    std::cout << "accept" << std::endl;

    std::cout << "Client : " << socketClient << std::endl;

    char message[100] = "Hello World";

    send(socketClient, (char*)&message, sizeof(message), 0);


    closesocket(socketClient);
    closesocket(socketServer);
    std::cout << "close" << std::endl;

    WSACleanup();
    return 0;
}
