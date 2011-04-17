#include <stdio.h>

int main(int argc, const char *argv[])
{
    int d=0;
    int i=0;
    int b=0;
    printf("Please input a numbers:\n");
    scanf ("%d",&d);
    b=31;
    for (i = 0; i < 32; i++,b--) 
    {
        printf("%d",((d>>b)&0x01));
    }
    printf("\n");
    return 0;
}
