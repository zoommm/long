#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define MAXLINE 80

int main(int argc, const char *argv[])
{
    int fd[2];
    int fd1[2];
    int n;
    pid_t pid;
    pid_t pid1;
    char line[MAXLINE];
    if (pipe(fd)<0) 
    {
        perror("piple");
        exit(1);
    }
    if ((pid = fork()) < 0)
    {
        perror("fork");
        exit(1);
    }
    if (pid == 0) 
    {
        close(fd[0]);
        write(fd[1],"hello world!\n",13);
        wait(NULL);
    }
    else if(pid > 0)
    {
        close(fd[1]);
        n = read(fd[0],line,MAXLINE);
        write(STDOUT_FILENO,line,n);
    }
    //////////////////////////////////
    if (pipe(fd1)<0) 
    {
        perror("pipe");
        exit(1);
    }
    if ((pid1 = fork()) < 0)
    {
        perror("fork");
        exit(1);
    }
    if (pid1 >0) 
    {
        close(fd1[0]);
        write(fd1[1],"world hello!\n",13);
        wait(NULL);
    }
    else 
    {
        close(fd1[1]);
        n = read(fd1[0],line,MAXLINE);
        write(STDOUT_FILENO,line,n);
    }
    
    
    return 0;
}
