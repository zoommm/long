#include <stdio.h>

char  *my_strcmp(char *p, char *q);
int main(int argc, const char *argv[])
{
    char a[4096]="this is C world!";
    char b[4096]="yes you are right!";
   
    my_strcmp(a,b);
    printf("%s\n%s\n",b,a);
    return 0;
}
char *my_strcmp(char *p ,char *q)
{

  while(*q!='\0')
  {
      *p=*q;
       p++;
       q++;
       
  }
  q = '\0';
    
}
