#include <stdio.h>
#include <string.h>

int main(int argc, const char *argv[])
{
    char s[]="ab-cd:ef;g+h;i-jkl;mnop;qrs-tu:vwx-y;z";
    char *delim="-:";
    char *p;
    char str[1024];
    char str1[1024];
    int i=0;
    p = strtok(query,'&');
    username = strtok(p,"=");
    printf("%s",strtok(s, delim));
    while((p=strtok(NULL,delim)))
    {  
        printf("%s",p);
            if (p != '\0') 
            {
                str[i]=p;
            }
            else
            {
               str1[i]=p;
            }
            i++;
    }
    printf("%s\n",str);
    printf("\n");
    return 0;
}
