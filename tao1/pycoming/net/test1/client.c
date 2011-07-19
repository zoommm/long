/* client.c */
#include <stdio.h>
#include <sys/types.h>          
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include "sock.h"
#include <sys/stat.h>
#include <fcntl.h>

#define SERVER_IP "127.0.0.1"

int main(int argc,char *argv[])
{
    int sockfd,ret,fd;
    char buf[1024];

    struct sockaddr_in server;
    
    sockfd = socket(AF_INET,SOCK_STREAM,0);

    if (sockfd < 0 ) 
    {
        perror("socket eorror");
        return 1;
    }
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    inet_pton(AF_INET, SERVER_IP,&server.sin_addr);

    ret = connect(sockfd,(SA)&server,sizeof(server));

   /* strcpy(buf,"pycoming");*/
    write(sockfd,argv[1],20);
    fd = open(argv[2],O_RDWR|O_CREAT|O_TRUNC,0644);
    ret = read(sockfd,buf,1024);
    write(fd,buf,ret);
    close(fd);
/*

    while(fgets(buf,80,stdin) != NULL)
    {
    
        write(sockfd,buf,80);
        read(sockfd,buf,80);
        printf("%s\n",buf);
    }
*/
    close(sockfd);
}
