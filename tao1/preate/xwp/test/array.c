#include <stdio.h>
#include<string.h>

void chang_array(char *p)
{
    char pt[4096];
    char ptr;
    int i = 0;
   
    while(*p!='\0')
    {
        pt[i] = *p;
        p++;
        i++;
    }
    
    printf("pt=%s\n",pt);
    if (strlen(pt)/2==0) 
    {
       
    
        for (i = 0; i < strlen(pt)/2; i++) 
        {
        ptr = pt[i+strlen(pt)/2];
        pt[i+strlen(pt)/2] = pt[i];
        p[i] = ptr;
        
        }
        printf("%s\n",pt);
    }
    else
    {
        for (i = 0; i < (strlen(pt)-1)/2; i++) 
        {
            ptr = pt[i+strlen(pt)+1];
            pt[i+strlen(pt)+1]=pt[i];
            p[i]=ptr;
        }
        printf("%s\n",pt);
    }
}
/*
void change(char *p)
{
    char pt;
    int x = strlen(p);
    char *q;
    int i = 0;
    if (x%2==0) 
    {
        for (i = 0; i < x/2; i++) 
        {
            pt = p[i];
            p[i] = p[i+x/2];
            p[i+x/2] = pt;
        }
        printf("%s\n",p);
    }
    else
    {
        for (i = 0; i < (x-1)/2; i++) 
        {
            pt = p[i];
            p[i] = p[i+x/2+1];
            p[i+x/2+1] = pt;
        }
        printf("%s\n",p);
    }

}
*/
int main(int argc, const char *argv[])
{
    int num = 0;
    char str[50]="abcdef";
    num = strlen(str);
    printf("%d\n",num);
    chang_array(str);
    printf("chang_array=%s\n",str);
    //change(str);
    //printf("chang = %s\n",str);
    return 0;
}
