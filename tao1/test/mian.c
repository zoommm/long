#include <stdio.h>
#include <time.h>
#include<stdlib.h>
#include<string.h>
int maopao(int p[]);
void print(int p[]);
int init(int p[]);
int check_string(char *s,char *w);
#define M 100
int main(int argc, const char *argv[])
{
    int a[M];
    char b[M]="This is C world!";
    char x[M]="s";
    //init(a);
    getchar();
    //maopao(a);
    //printf("THis is maopao\n");
    //print(a);
    //printf("\n");
    check_string(b,x);

    return 0;
}
int check_string(char *s,char *w)
{
   int i = 0 ;
   int num=0;
   int j=0;
   int z;
   while(s[i]!='\0')
   {
        if (strncmp(s+i,w,strlen(w))==0) 
        {
            z=i;
            break;
        }
        if (s[i]=='\0') 
        {
            z=-1;
            break ;
        }
        i++;
   }
   num=z;
    if (num<0) 
    {
        printf("NO word\n");    
    }
    else 
    {
        printf("%d\n",num);
        printf("ENTER a TEST\n");
        getchar();
        printf("%s\n",s+num);
    }
   
    
}
int init(int p[])
{
    
    int i = 0;
    int counter = 0;
    srand(time(NULL));
    for (i = 0; i < 100; i++) 
    {
        
        p[i] = (rand()%100);
    }
    for (i = 0; i < 100; i++) 
    {
        if (counter == 5) 
        {
            printf("\n");
            counter = 0;
        }
        counter++;
        printf("a[%d]=",i);
        printf("%d  ",p[i]);
    }
}
void print(int p[])
{
    int i= 0;
    int counter = 0;
    for (i = 0; i < 100; i++) 
    {
        if (counter == 5) 
        {
            printf("\n");
            counter = 0;
        }
        counter++;
        printf("a[%d]=",i);
        printf("%d  ",p[i]);
    }
}
int maopao(int p[])
{
    int i = 0;
    int j = 0;
    int temp[M];
    for (j = 0; j < 100; j++) 
    {
        
    
        for (i = j+1; i < 100; i++) 

        {   
            temp[0]=p[0];
            if(p[i]<p[j]) 
             {
                temp[0]=p[j];
                p[j]= p[i];
                p[i]=temp[0];
             }

        }   
    }
    return 0;
}
