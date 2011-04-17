#include <stdio.h>

int main(int argc, const char *argv[])
{
    int i=0;
    int j=0;
    int d=0;
    unsigned int mask=0x0f;
    char str_h[20]="0123456789abcdef";
    printf("Please input a nunber:\n");
    scanf("%d",&d);
    j=sizeof(int)*8-4;
    for (i = 0; i < sizeof(int)*2; i++,j-=4 ) 
    {
        printf("%c",str_h[(d>>j)&mask]);
    }
    printf("\n");

    return 0;
}
