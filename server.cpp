#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <iostream>

#define PORT 5001

int main(int argc, char *argv[])
{
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


    close(socketClient);
    close(socketServer);
    std::cout << "close" << std::endl;
    return 0;
}
