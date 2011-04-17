#include <stdio.h>
int sub() ;
int mul();
int add();
int div();
int main(int argc, const char *argv[])
{
    int a =5;
    int b =6;
    int c =0;
    c = sub(a,b);
    printf("%d\n",c);
    c= mul(a,b);
    printf("%d\n",c);
    c=div(a,b);
    printf("%d\n",c);
    c = add(a,b,c);

    printf("%d\n",c);
    return 0;
}
int add(int a ,int b,int c )
{
    c=a+b;
    return c;
}
int sub (int a ,int b) 
{
    return (a-b);
}
int  mul(int a,int b)
{
    return (a*b);    
}
int  div(int a,int b)

{
    return (a/b);
}
