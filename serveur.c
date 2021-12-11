#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>

#define PORT 8080

int main(int argc, char const *argv[])
{
//////////////////////////////////////////

int serveur_fd;

serveur_fd = socket(AF_INET,SOCK_STREAM,0);

//////////////////////// Creating socket file descriptor

if ((serveur_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)

    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

////////////////////////////////////

struct sockaddr_in  adress;

adress.sin_family = AF_INET;
adress.sin_addr.s_addr = INADDR_ANY;
adress.sin_port = htons( PORT );


//////////////////////////////////////////

bind(serveur_fd,(struct sockadrr *)&adress,sizeof(adress));

//////////////////////////////////////////////////////////

listen(serveur_fd,4);

///////////////////////////////////////////////////////////

int accept_fd;
int addrlen = sizeof(adress);

accept_fd= accept(serveur_fd,(struct sockaddr *)&adress,(socklen_t *)&addrlen);

//////////////////////////////////////////////////////

int valread ;
char buffer[1024] = {0};
char *hello = "Hello from server";

valread =read(accept_fd,buffer,1024);
printf("%s\n", buffer);
send(accept_fd, hello , strlen(hello) , 0 );
printf("Hello message sent from serveur \n");



return 0;
}
