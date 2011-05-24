#include <stdio.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
    char *ps_argv[]={"ps","-o","pid,ppid,pgrp,session,tpgid,comm",NULL};
    char *ps_envp[]={"PATH=/bin:/usr/bin","TERM=console",NULL};
    execve("/bin/ps",ps_argv,ps_envp);
    perror("exec ps");
    exit(1);
    
}
