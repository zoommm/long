#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>


int main(int argc, const char *argv[])
{
    int fd;
    if (argc!=2) 
    {
        fputs("usage :wrapper file\n ",stderr);
        exit(1);
    }
    fd = open (argv[1],O_RDONLY);
    if (fd <0) 
    {
        perror("open faile");
        exit(1);
    }
    dup2(fd,STDIN_FILENO);
    close(fd);
    execl("./a.out","upper",NULL);
    perror("exec ./a.out");
    exit(1);
}
