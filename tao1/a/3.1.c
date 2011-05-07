#include <stdio.h>

int main(int argc, const char *argv[])
{
    char c;
    c = 128;
    if (c==128) 
    {
        printf("hello\n");  
    }
    else
    {
        printf("world\n");
    }
    printf("%d\n",c);
    return 0;
}
