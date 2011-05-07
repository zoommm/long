#include <stdio.h>

int main(int argc, const char *argv[])
{
    char a[10]={0,1,2,3,4,5,6,7,8,9};
    short *p = (short *)(a+3);
    short i = *p;
    printf("%x",i);
    printf("\n");
    return 0;
}
