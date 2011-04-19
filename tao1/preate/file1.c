#include <stdio.h>

int main(int argc, const char *argv[])
{
    FILE *fp;
    char ch;
    if ((fp=fopen("e10-1.c","rt"))==NULL) 
    {
        printf( "Can't open the file :\n");
        getch();   
        exit(1);

    }
    ch=fgetc(fp);
    while(ch!=EOF)
    {
        putchar(ch);
        ch=fgetc(fp);
    }
    fclose(fp);
    return 0;
}
