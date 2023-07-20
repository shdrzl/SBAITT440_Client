#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

int main()
{
    printf("This is CLIENT.\n");
    int status, valread, client_fd, portNo;
    struct addrinfo hints, *res;
    char buffer[1024] = { 0 };
    char hostname[100] = "izani.synology.me";
    char portString[10] = "8443";

    portNo = 8443;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    // Resolve the hostname to IP address
    if ((status = getaddrinfo(hostname, portString, &hints, &res)) != 0)
    {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
        return -1;
    }

    // Create a socket
    if ((client_fd = socket(res->ai_family, res->ai_socktype, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        freeaddrinfo(res);
        return -1;
    }

    // Connect to the server
    if ((status = connect(client_fd, res->ai_addr, res->ai_addrlen)) < 0)
    {
        printf("\nConnection Failed \n");
        freeaddrinfo(res);
        return -1;
    }

    freeaddrinfo(res);

    printf("\nConnected to Server\n");

    char message[100];
    printf("\nPlease enter your Student ID: ");
    scanf("%99s", message); // enter student id
    send(client_fd, message, strlen(message), 0); // Send id to Server
    printf("Message sent to server\n");

    valread = recv(client_fd, buffer, 1024, 0); // Receive reply from Server
    printf("Server : %s\n", buffer);

    // Closing the connected socket
    close(client_fd);
    return 0;
}
