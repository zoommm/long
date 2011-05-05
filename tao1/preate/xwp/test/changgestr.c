#include <stdio.h>
int string_to_number(char *p)
{
    int number = 0;
    if ((*p>='0')&&(*p<='9')) 
    {
        *p=(*p-0x30);
        number = *p;
        p++;
        while((*p>='0')&&(*p<='9'))
        {
            number = number*10;
            number = number+(*p-0x30);
            p++;
        }
    }
    else
    {
        number = -1;
    }
    return number;
}
int main(int argc, const char *argv[])
{
    char pt[4096];
    int num = 0;
    printf("input a char number:\n");
    scanf("%s",pt);

    num=string_to_number(pt);
    if (num == -1) 
    {
        printf("NO Number\n");
    }
    else
    {
        printf("number = %d",num);
    }
    printf("\n");
    return 0;
}
