#include <stdio.h>

int main(int argc, const char *argv[])
{
    int fd;
    fd=open("/home/akae.txt",O_WRONLY|O_APPEND);
    fd=open("~",O_WRONLY|O_CREATE,0755);
    fd=open("~",O_WRONLY|O_TRUNC|O_CREATE,0777);
    fd=open("~",O_WRONLY|O_EXCL|O_CREATE,0777);
   
    return 0;
}
