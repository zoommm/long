#include <stdio.h>
#define M 100
int main(int argc, const char *argv[])
{
    int i = 0;
    char a[M];
    char b[M]="hello world !";
    int m = sizeof(a);
    printf("input a string:\n");
    scanf("%s",a);

    for (i = 0; i < m; i++) 
    {
       if (a[i]>'a'&&a[i]<'z') 
       {
           a[i]=a[i]-32;
       }
    }
    for (i = 0; i < m; i++) 
    {
       if (b[i]>'a'&&b[i]<'z') 
       {
           b[i]=b[i]-32;
       }
    }
    printf("%s\n",a);
    printf("%s\n",b);
    return 0;
}
