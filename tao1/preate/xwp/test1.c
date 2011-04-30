#include <stdio.h>
#include <string.h>
int my_strcmp(char *dest,char *src,int num)
{
    int i;
    if (num == 0) 
    {
        return 1;
    }
    for (i = 0; i < num; i++) 
    {
       if (strcmp(dest,src)==0)
       {
           return 0;
       }
      src=src+10;
    }
    return 1;
    
}
int main(int argc, const char *argv[])
{
    
    char name[5][10];
    char tmp[10];
    int i;

    for (i = 0; i < 5; i++) 
    {
        printf("please input a name \n");
        fgets(tmp,10,stdin);
        if (my_strcmp(tmp,name[0],i)==1) 
        {
            strcpy(name[i],tmp);
        }
        else
        {
            printf("chong xin input:\n");
            i--;
        }

    }
    for (i = 0; i < 5; i++) 
    {
        printf("%d      %s\n",i,name[i]);
    }

    return 0;
}
