/*client.c*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include "sock.h"
#define SERVER_IP "127.0.0.1"


int main(int argc,char *argv[])
{
	int sockfd,ret,i=0,fd;
	struct sockaddr_in server;
	char buf[1024],buf1[81];

	sockfd=socket(AF_INET,SOCK_STREAM,0);
	if(sockfd<0){
		perror("socket");
		return 1;
	}
	server.sin_family=AF_INET;
	server.sin_port=htons(PORT);
	inet_pton(AF_INET,SERVER_IP, &server.sin_addr);
	ret=connect(sockfd, (SA)&server,sizeof(server));
	/*strcpy(buf,"pycoming");*/
	write(sockfd,argv[1],20);
	fd=open(argv[2],O_RDWR|O_CREAT|O_TRUNC,0644);
	ret=read(sockfd,buf,1024);
	write(fd,buf,ret);
	close(fd);
	close(sockfd);
}
