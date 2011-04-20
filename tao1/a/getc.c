#include <stdio.h>

int main(int argc, const char *argv[])
{
    char getc(FILE *p);
    char str[100]="123456ad";
    char ch;
    ch = getc(str);
    printf("this is :%s\n",ch);
    return 0;
}
