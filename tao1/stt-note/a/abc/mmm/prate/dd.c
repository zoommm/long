#include <stdio.h>

int main(int argc, const char *argv[])
{
    int d=0;
   unsigned int mask = (0x01<<(sizeof(int)*8-1));
    int i=0;
    printf("Please input a numbers:\n");
    scanf ("%d",&d);
    for (i = 0; i < (sizeof(int)*8); i++) 
    {
        printf("%d",((d&mask)!=0?1:0));
        mask>>=1;

    }
    printf("\n");
    return 0;
}
