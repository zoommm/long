#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
    int fd;
    char buf[4096];
    int n;
    if((fd = open("./hello",O_RDWR)) < 0)
    {
        perror("open error");
        exit(1);
    }   
    n = write(fd,"hello world\n",13);
    if (n < 0) 
    {
        perror("write error");
        exit(1);
    }
    printf("write data is :%s\n",buf);
    close(fd);
    
    
    return 0;
}
