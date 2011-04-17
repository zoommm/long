#include <stdio.h>
void foo(int n);

int main(int argc, const char *argv[])
{
    int n;
    printf("%d\n",100);
    printf("%f\n",100.0);
    foo(100.0);
   
    return 0;
}
void foo(double n)
{
    printf("%f\n",n);
    return 0;
}
