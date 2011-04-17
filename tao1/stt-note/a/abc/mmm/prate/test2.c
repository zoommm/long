#include <stdio.h>

int main(int argc, const char *argv[])
{
    int i=0;
    int j=0;
    unsigned int mask =0x0f;
    int d=0;
    printf("Please input a number:\n");
    scanf("%d",&d);
    j=28;
    for (i = 0; i < 8;i++ ,j-=4)  
    {
        if (((d>>j)&mask)<=9) 
        {
            printf("%d\n",(d<<j));

        }
        else printf("%c\n",'a'+(((d<<j)&mask)-10));
    }
    printf("\n");
    return 0;
}
