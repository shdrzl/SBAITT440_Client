#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
  
int main()
{
    printf("This is CLIENT.\n");
    int status, valread, client_fd, portNo;
    struct sockaddr_in serv_addr;
    char buffer[1024] = { 0 };
    char ipBuffer[1024] = "192.168.1.121";
  
    printf("Server's IP Address : %s " ,ipBuffer);
    portNo = 8484;
    printf("\nServer's port number : %d " ,portNo);

    if ((client_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }
  
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portNo);
  
    // Convert IPv4 and IPv6 addresses from text to binary
    // form
    if (inet_pton(AF_INET, ipBuffer, &serv_addr.sin_addr)
        <= 0) {
        printf(
            "\nInvalid address/ Address not supported \n");
        return -1;
    }
    else
        printf("\nSocket successfully created");
  
    // connecting Client to Server
    if ((status
         = connect(client_fd, (struct sockaddr*)&serv_addr,
                   sizeof(serv_addr)))
        < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }
    else
        printf("\nGot connection from Server");

    valread = recv(client_fd, buffer, 1024, 0); //receive reply from Server
    printf("\nServer reply : %s\n", buffer);
  
    // closing the connected socket
    close(client_fd);
    return 0;
}

