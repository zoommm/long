#include <stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
int main(int argc, const char *argv[])
{
    int fd_src,fd_dst;
    char* buf[2048];
    int n = 0;
    if (argc != 3) 
    {
        printf("Usagel :%s[source file] [dest file]\n",argv[0]);
        exit(1);
    }
    fd_src = open(argv[1],O_RDONLY);
    if (fd_src < 0) 
    {
        perror("open file error:");
        exit(1);
    }
    fd_dst = open(argv[2],O_WRONLY|O_CREAT|O_TRUNC,0644);
    if (fd_dst<0) 
    {
        perror("open file error");
        exit(1);
    }
    while((n = read(fd_src,buf,1024)))
    {
        write(fd_dst,buf,n);
    }

    close(fd_dst);
    close(fd_src);

    return 0;
}
