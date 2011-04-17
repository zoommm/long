#include <stdio.h>
#include<string.h>

int main(int argc, const char *argv[])
{
    char str[20]="This is a C world!";
    char *p=str;
    char *p_c=str;
    

    char c_str[20]="THIS IS A C WORLD";
    char *s=c_str;
    char *pp=c_str;
    
//低效率：

    for (p = str; *p !='\0'; p++) 
    {
        if (*p!=' ') 
        {
            *p_c=*p;
            p_c++;
        }
    }
    *p_c='\0';
    printf("len=%d\t%s\n",strlen(str),str);
   
   
     
//效率高：     
     
     while(*s !='\0')
      {
        while(*s ==' ')s++;
        if (pp!=s) 
        {
            *pp=*s;
        }
        pp++;
        s++;
    }
    *pp='\0';
    printf("len=%d\t%s\n",strlen(c_str),c_str);
    return 0;
}
