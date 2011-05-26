#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    int fb[2];
    pid_t pid;
    pid = fork();
    if (pid < 0) 
    {
        perror("pid");
        exit(1);
    }
    if (pid == 0) 
    {
        int i;
        for (i = 3; i>0; i--) 
        {
            printf("thisis the child\n");
            sleep(1);
        }
        exit(3);
    }
    else
    {
        int stat_val;
        waitpid(pid,&stat_val,0);
        if (WIFEXITED(stat_val)) 
        {
            printf("Child exited with code %d\n",WEXITSTATUS(stat_val));
        }
        else if (WIFSIGNALED(stat_val)) 
        {
            printf("Child terminal abnomally ,signal %d\n",WTERMSIG(stat_val));
        }
    }
    

    return 0;
}
