#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#define PORT 8080

int main(int argc, char const *argv[])
{
///////////////////////////////////

int socket_fd;
socket_fd =socket(AF_INET,SOCK_STREAM,0);

//////////////////////////////////////////////


struct sockaddr_in serv_addr;
serv_addr.sin_family = AF_INET;
serv_addr.sin_port = htons(PORT);

/////////////////////////////////////////////////////////////////////

if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0)
    {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

///////////////////////////////////////////////////////////////////

connect(socket_fd,(struct sockaddr *)&serv_addr,sizeof(serv_addr));

//////////////////////////////////////////////////////////

char *hello = "Hello from client";
char buffer[1024] = {0};
int  valread;
send(socket_fd , hello , strlen(hello) , 0 );
printf("Hello message sent from client \n");
valread = read(socket_fd , buffer, 1024);
printf("%s\n", buffer);


return 0;
}
