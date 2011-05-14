#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, const char *argv[])
{
    char *ps;
    int fd1;
    int fd2;
    char *pd;
    struct stat statbuf;
    if (argc <2) 
    {
        printf("Usage :%s srcfile desfile\n",argv[0]);
        exit(1);
    }
    fd1 = open(argv[1],O_RDONLY);
    if (fd1 < 0) 
    {
        perror("open argv[1]");
        exit(1);
    }

    if (stat(argv[1],&statbuf)== -1) 
    {
        perror("fail to stat");
        exit(1);
    }
    printf("size :%d\n",(int)statbuf.st_size);
    ps = mmap(NULL,statbuf.st_size,PROT_READ,MAP_PRIVATE,fd1,0);
    if (ps == MAP_FAILED) 
    {
        perror("mmap ps");
        exit(1);
    }
    close(fd1);

    fd2 = open(argv[2],O_RDWR|O_CREAT|O_TRUNC,0644);
    if (fd2 < 0 ) 
    {
        perror("open desfile error");
        exit(1);
    }
    lseek(fd2,statbuf.st_size-1,SEEK_SET);
    write(fd2,"",1);
    
    pd = mmap(NULL,statbuf.st_size,PROT_WRITE,MAP_SHARED,fd2,0);
    if (pd == MAP_FAILED) 
    {
        perror("mmap pd");
        exit(1);
    }
    close(fd2);
    memcpy(pd,ps,statbuf.st_size);
    munmap(ps,statbuf.st_size);
    munmap(pd,statbuf.st_size);
    return 0;
}
