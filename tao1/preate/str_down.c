#include <stdio.h>
#include <string.h>
int find_word(char *s,char *w);

int main(int argc, const char *argv[])
{
    char str1[20]="This is a Game !";
    char str2[20]="a";
    int num =find_word(str1,str2);
    if (num<0) 
    {
        printf("No such word\n");       
    }
    else
    {
        printf("%d\n",num);
        printf("press enter to test ....\n");
        getchar();
        printf("%s\n",str1+num);
    }

    return 0;
}
int find_word(char *s,char *w)
{
    int i=0;
    while(s[i]!='\0')
    {
        if (strncmp(s+i,w,strlen(w))==0) 
        {   
            return i;
            
        }
        i++;
    }
    return -1;
}
