#include <stdio.h>
#include<stdlib.h>
int main(int argc, const char *argv[])
{
    char str[100];
    int number=0;
    int base=0;
    char *p;
   // int atoi(const char *nptr);
    printf("input the number:\n");
    scanf("%s",str);
    printf("input the base:\n");
    scanf("%d",&base);
    number=strtol(str,&p,base);
    printf("decimal number :%d\n",number);

    return 0;
}
