#include <stdio.h>
#include <string.h>

void delete_char(char *str,char ch);
void init_char(char *p);
void delete_chartemp(char *str,char ch);
int main(int argc, const char *argv[])
{
    char ppt[]="thics is program";
    char cc='c';
    //ppt[20]=init_char(ppt);
    //delete_char(ppt,cc);
    delete_chartemp(ppt,cc);
    printf("%s\n",ppt);
    return 0;
}
void init_char(char *p)
{
    printf("input a string \n");
    scanf("%s",p);
    return p;
}
void delete_char(char *str,char ch)
{
    int i=0;
    int j=0;
    char p[20];
    p[20] = str;
    while(p[i]!='\0')
    {
        
       
        if (p[i]==ch) 
        {
            while(p[j]!='\0')
            {
                p[j]=p[j+1];
                j++;
            
            }
        }
        i++;
        j++;
    }
  return 0;
}
void delete_chartemp(char *str,char ch)
{
    char temp[1024];
    char *q = temp;
    char *p = str;
    char tem[20];
    tem[20] = str;
    int i = 0;
    while(*p != '\0')
    {
        if (*p==ch) 
        {
            p++;
        } 
        else
        {
            *q = *p;
             q++;
             p++;
        }
        
    }
   *q= '\0';
   strcpy(p,q);
}

