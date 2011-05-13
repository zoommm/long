#include <stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>


int main(int argc, const char *argv[])
{
    if (argc!=3) 
    {
        perror("USage!");
        exit(0);
    }

    int fd1;
    int fd2;
    char* buf[2048];
    int n = 0;
    fd1 = open("1.c",O_RDONLY);
    if (fd1<0) 
    {
        printf("1\n");
        exit(1);
    }
    read(fd1,buf,1024);
    fd2 = open("2.c",O_WRONLY|O_CREAT|O_TRUNC,0755);
    if (fd2<0) 
    {
        printf("2\n");
        exit(1);
    }
    write(fd2,buf,1024);
    while((n=read(fd1,buf,1024)))
    {
        write(fd2,buf,n);
    }
    close(fd1);
    close(fd2);
    return 0;
}
