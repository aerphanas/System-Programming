#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 5555

int
main()
{
    // create socket
    int net_socket = socket(AF_INET, SOCK_STREAM, 0);

    // server info
    struct sockaddr_in connect_to;
    connect_to.sin_family = AF_INET;
    connect_to.sin_port = htons(PORT);
    connect_to.sin_addr.s_addr = inet_addr("127.0.0.1");

    // connect to server
    int connection = connect(net_socket, (struct sockaddr*) &connect_to, sizeof(connect_to));

    // error handling
    if (connection == -1)
        printf("Unable connect to server \n");

    // get data from server
    char buffer[255];
    int data_rec = recv(net_socket, buffer, sizeof(buffer), 0);

    // print data from server
    if (data_rec == -1)
        printf("Unable read from server \n");
    else
        printf("%s \n", buffer);

    // close 
    close(net_socket);

    return 0;
}