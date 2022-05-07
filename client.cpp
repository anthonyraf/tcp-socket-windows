#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <iostream>

#define PORT 5001


int main(int argc, char const *argv[])
{
    int socketClient = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in addrClient;
    addrClient.sin_family = AF_INET;
    addrClient.sin_addr.s_addr = inet_addr("127.0.0.1");
    addrClient.sin_port = htons(PORT);

    connect(socketClient, (const struct sockaddr *)&addrClient , sizeof(addrClient));
    std::cout << "Connecte" << std::endl;

    char message[100];
    recv(socketClient, &message, sizeof(message), 0);
    std::cout << message << std::endl;


    close(socketClient);
    return 0;
}
