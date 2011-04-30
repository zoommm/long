#include <stdio.h>
void foo()
{
    int i = 0;
    int num = 10;
    for (i = 0; i < num; i++) 
    {
        printf("%d\n",i);
    }
}
int main(int argc, const char *argv[])
{
    char *str="hello world!";
    char str1[4096];

    foo();

    *str='a';
    printf("%s\n",str);
    return 0;
}
