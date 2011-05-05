#include <stdio.h>
int string_to_number(char *s);

void char_change(char *p);
int main(int argc, const char *argv[])
{
    char str[20]="344 vs 346";
    char pt[100];
    int number=0;
    printf("input some number:\n");
    scanf("%s",pt);
   
    number=string_to_number(pt);
    if( number==-1) 
    {
        printf("No number\n");
    }
    else
    
    {
        printf("number=%d\n",number);
    }

    //char_change(str);

    printf("\n");
    return 0;
}
////////////////////////////////////////
/////////my_test////////////////////////

void char_change(char *p)
{   
     int i=0;
     while(p[i]!='\0')
    {
        if (p[i]>'0'&&p[i]<'a') 
       {
           p[i]=(p[i]-0x30);
           printf("%d",p[i]);

       }
       i++;
    }
}
////////////////////////////////////////////
////////////////////////////////////////////
///////////teacher//////////////////////////
int string_to_number(char *s)
{
    int number=0;
    if ((*s>='0')&&(*s<='9'))   
    {
       number =(*s-0x30);
       s++;
       while((*s>='0')&&(*s<='9')) 
       {
            number*=10;
            number+=(*s-0x30);
            s++;
       }
    
    }
    else
    {
        return -1;
    }
    return number;
}
