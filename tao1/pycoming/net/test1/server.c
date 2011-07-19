/*server.c*/
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <stdlib.h>
#include "sock.h"
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc,char *argv[])
{
    int sockfd,ret,connfd,len,fd;
    char buf[1024],buf1[512],filename[20];
    struct sockaddr_in server, client;
    pid_t pid;    

/*socket creat*/
    sockfd = socket(AF_INET,SOCK_STREAM,0);
    if (sockfd < 0) 
    {
        perror("socket error");
        exit(1);
    }
/*bzero */
    bzero(&server,sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = htonl(INADDR_ANY);

    ret = bind(sockfd,(SA)&server,sizeof(server));

    if (ret < 0) 
    {
        perror("bind error ");
        exit(1);
    }

    
    ret = listen(sockfd,5);
    if (ret < 0) 
    {
        perror("listen error");
        exit(1);
    }

    printf("Accepting ...\n");
    while(1)
    {
        len = sizeof(client);
        connfd = accept(sockfd,(SA)&client,&len);
        if (connfd < 0) 
        {
            perror("accept error");
            exit(1);
        }
        pid = fork();
        if (pid == -1) 
        {
            perror("fork error");
            exit(1);
        }
        else if(pid == 0)
        {
            close(sockfd);
            read(connfd,filename,20);
            fd = open(filename,O_RDONLY);
            ret = read(fd,buf,1024);
            write(connfd,buf,ret);
            close(fd);
/*
            while(1)
            {
            #ifdef DEBUG
                printf("accept success!\n");
            #endif
                ret = read(connfd,buf,80);
            #ifdef DEBUG
                printf("%s\n",buf);
            #endif
                strcpy(buf1,"hello ");
                strcat(buf1,buf);
                write(connfd,buf1,512);
            }
*/
         }
         else
         {
            close(connfd);
         }
    }
    return 0;
}
