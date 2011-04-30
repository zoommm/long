#include <stdio.h>
#include <string.h>

char str_comp(char *str1,char *str2)
{
    int num;
    char *pt;
    char ptt[100];
    char *p=str1,*q=str2;
    int i = 0;
  
    while(*p!='\0')
    {
        q = str2;
        if (*p==*q) 
        {
            *pt=*q;
            p++;
            q++;
            pt++;
        }
        else
        {
             p++;
             q++;
        }
    }
    strcpy(ptt,pt);

    return ptt;

}
int main(int argc, const char *argv[])
{
    char tmp[100];
    char tem[100];
    char *ptr;
    int num;
    printf("please input a string:\n");
    fgets(tmp,10,stdin);
    printf("please input another string:\n");
    fgets(tem,10,stdin);
    printf("tmp= %stem =%s\n",tmp,tem);

    tem[100]=str_comp(tmp,tem);
    printf("%s\n",tem);
    
    return 0;
}
