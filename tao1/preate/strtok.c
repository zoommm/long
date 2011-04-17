#include <stdio.h>
#include <string.h>
void str_test(void);

int main(int argc, const char *argv[])
{
    str_test();
    return 0;
}
void str_test(void)
{
    char str[100]="This is only a Game !";
    char *p= str;
          p= strtok(p," ");
          while(p!=NULL)
          {
           printf("%s\n",p);
           p=strtok(NULL ," ");
       
           }    
}
