#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>

int main(void)
{
    int status;
    int a = 10;

    pid_t pid = fork();
    
    if (pid<0) 
    {
        perror("fork");
        exit(1);
    }
    if(pid>0)
    {
        kill(pid,SIGINT);

        wait(&status);
        if (WIFEXITED(status))
        {
            printf("the return status is %d\n",WEXITSTATUS(status));
        }
        else if(WIFSIGNALED(status))
        {
            printf("the return status not is %d\n",WTERMSIG(status));
            printf("%d\n",status);
        }
    }
   if(pid == 0)
   {
        sleep(5);
   }
    return 0;
}
