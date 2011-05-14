#include <stdio.h>
#include<sys/types.h>
#include<fcntl.h>
#include<stdlib.h>

int main(int argc, const char *argv[])
{
    int val;
    if (argc!=2) 
    {
        fputs("Usage:a.out<descriotor#>",stderr);
        exit(1);
    }
    if((val = fcntl(atoi(argv[1]),F_GETFL))<0) 
    {
        printf("fcntl error for fd %d\n",atoi(argv[1]));
        exit(1);
    }
    switch(val & O_ACCMODE)
    {
        case O_RDONLY:
            printf("resd only\n");
            break;
        case O_WRONLY:
            printf("write only\n");
            break;
        case O_RDWR:
            printf("read write\n");
            break;
        default:
            fputs("Invalid access mode\n",stderr);
            exit(1);
    }
    if (val & O_APPEND) 
    {
        printf(",append ");
    }
    if (val & O_NONBLOCK) 
    {
        printf(",nonblocking\n");
    }
    putchar('\n');
    return 0;
}
