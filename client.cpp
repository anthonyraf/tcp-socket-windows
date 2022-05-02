#include <WinSock2.h>
#include <ws2tcpip.h>
#include <iostream>

#pragma comment(lib, "ws2_32.lib")
#define PORT 5000


int main(int argc, char const *argv[])
{
    WSADATA WSAData;
    WSAStartup(MAKEWORD(2,0), &WSAData);

    int socketClient = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in addrClient;
    addrClient.sin_family = AF_INET;
    addrClient.sin_addr.s_addr = inet_addr("127.0.0.1");
    addrClient.sin_port = htons(PORT);

    connect(socketClient, (const struct sockaddr *)&addrClient , sizeof(addrClient));
    std::cout << "Connecte" << std::endl;

    char message[100];
    recv(socketClient, (char*)&message, sizeof(message), 0);
    std::cout << message << std::endl;


    closesocket(socketClient);
    WSACleanup();
    return 0;
}
