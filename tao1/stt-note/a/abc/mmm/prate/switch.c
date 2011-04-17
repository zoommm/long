#include <stdio.h>

int main(int argc, const char *argv[])
{
    int i;
    int j=sizeof(int)*8-4;
    int d;
    printf("Please input a numvber\n");
    scanf("%d",&d);
    for (i = 0; i < sizeof(int)*2; i++,j-=4) 
    {
        d=(d>>)&0x0f;
        if (d<<=9) 
        {
            printf("%d\n",d);

        }
        else
        {
            swich(d);
           { 
            case(10):c='a'
            break;
            case(11):c='b'
            break;
            case(12):c='c'
            break;
            case(13):c='d'
            break;
            case(14):c='e'
            break;
            case(15):c='f'
            break;
            default:break;
            }
        }
    }
    printf("%d\n");
}
