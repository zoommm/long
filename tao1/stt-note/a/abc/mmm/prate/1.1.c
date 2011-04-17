#include <stdio.h>

int main(int argc, const char *argv[])
{
    int d=0;
    int i=0;
    puts("Please input a num:");
    scanf("%d",&d);
    puts("result:");
    for (i = 0; i < 32; i++) 
    {
    
    printf("%d",( d & 0x01));
    d >>=1;
    }
    printf("\n");

    return 0;
}
