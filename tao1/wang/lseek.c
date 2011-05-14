#include <stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<stdlib.h>
int main(int argc, const char *argv[])
{
    int fd;
    fd = open("1.txt",O_WRONLY);
    if (fd < 0)  
    {
        perror("open 1.txt");
        exit(1);
    }
    lseek(fd,10,SEEK_SET);
    write(fd,"L",1);
    close(fd);
    return 0;
}
