#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <errno.h>

void perr_exit(const char *s)
{
    perror(s);
    exit(1);
}
int Accept(int fd, struct sockaddr *sa,socklen_t *salenptr)
{
    int n;
again:
    if ((n = accept(fd,sa,salenptr))< 0 ) 
    {
        if ((errno == ECONNABORTED)||(errno == EINTR)) 
        {
            goto again;
        }
        else
            perr_exit("accept error");
    }
    return n;
}
void Bind(int fd,const struct sockaddr *sa,socklen_t salen)
{
    if (bind(fd,sa,salen)< 0 ) 
    {
        perr_exit("bind error");
    }
}
void Connect(int fd,const struct sockaddr *sa,socklen_t salen)
{
    if (connect(fd,sa,salen)< 0 ) 
    {
        perr_exit("connect error");
    }
}
