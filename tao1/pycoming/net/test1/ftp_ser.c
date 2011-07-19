/*server.c*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include "sock.h"

int main(int argc,char *argv[])
{
	int sockfd,connfd,ret,len,fd;
	struct sockaddr_in server, client;
	char buf[1024],buf1[512],filename[20];
	pid_t pid;
	/*socket creat*/
	sockfd=socket(AF_INET,SOCK_STREAM, 0);
	if(sockfd<0){
		perror("socket");
		return 1;
	}
	/*init server */
	bzero(&server,sizeof(server));
	server.sin_family=AF_INET;
	server.sin_port=htons(PORT);
	server.sin_addr.s_addr=htonl(INADDR_ANY);
	/*bind*/
	ret=bind(sockfd,(SA)&server,sizeof(server));
	if(ret<0){
		perror("bind");
		return 2;
	}

	ret=listen(sockfd,5);
	if(ret<0){
		perror("listen");
		return 3;
	}
	printf("Accepting ...\n");	
	while(1){
		len=sizeof(client);
		connfd=accept(sockfd, (SA)&client, &len);
		if(connfd<0){
			perror("accept");
			return 4;
		}
		pid=fork();
		if (pid==-1){
			perror("fork");
			return 5;
		}else if(pid==0){
			close(sockfd);
			read(connfd,filename,20);
			fd=open(filename,O_RDONLY);
			ret=read(fd,buf,1024);
			write(connfd,buf,ret);
			close(fd);
		}else{
			close(connfd);
		}

	}
	return 0;
}
