#include <stdio.h>
int remove_space(char s[]);

int main(int argc, const char *argv[])
{
    char str[20]="This is a C world!";
    char c_str[20];
    char *p=str;
    char *p_c=c_str;

    int i=0;
    

    for (i = 0; i < 20; i++) 
    {
        printf("%c",p[i]);

    }
    printf("\n");
//指针法。输出字符：
    for (p =str;*p !='\0'; p++) 
    {
       putchar(*p);
    }
    putchar('\n');
    while(*p !='\0')p++;
    for (p --; p !=(str-1); p--) 
    {
        putchar(*p);
    }
    putchar('\n');
//指针法：  去空格。
     for (p = str; *p !='\0'; p++) 
    {
        if (*p!=' ') 
        {
            *p_c=*p;
            p_c++;
        }
    }
    *p_c='\0';
    printf("%s\n",c_str);
    for (p =str; *p !='\0'; p++) 
    {
        if(*p!=' ')
        {
            *p_c=*p;
            p_c++;
        }
    }
    *p_c='\0';
    printf("%s\n",str);
//函数法：去空格。

    remove_space(str);
    printf("%s\n",c_str);
    return 0;
}
int remove_space(char s[])
{  
    int i ,j;
   for (i=j = 0; s[i]; i++) 
    
        if (s[i] !=' ') 
        {
            s[j++]=s[j];
        }
        s[j]=0;
       return 0;
}        
