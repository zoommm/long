#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>

int main(int argc, const char *argv[])
{
    int *p;
    int fd = open("hello",O_RDWR);
    int i = 0;
    if (fd < 0) 
    {
        perror("open hello  ");
        exit(1);
    }
    p = mmap(NULL,6,PROT_WRITE,MAP_SHARED,fd,0);
    if (p == MAP_FAILED) 
    {
        perror("mmap");
        exit(1);
    }
    close(fd);
    for (i = 0; i < 6; i++) 
    {
        
        p[i]=0x30+i;
    }
    //p[0]=0x30313233;
    munmap(p,6);
    return 0;
}
