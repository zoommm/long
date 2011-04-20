#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    FILE *fp;
    char ch;
    int i=0;
    char str[100]="hello world!!!!\nthis is C world\n";
    char str_1[100]="hkjahkjhk";
    
    int r_number=20;
    str[4]=4;
    str[6]=0;
    str[7]=0;
    
    //gets(str_1);
    //printf("\r%s\n",str_1);
    fp=fopen("text2","r+");
    if (fp==NULL) 
    {
        perror("open:");
        exit(0);
    }
    while(str[i]!='\0')
    {
      putc(str[i++],fp);
        
    }
    rewind(fp);
    i=0;
    while((str_1[i]=getc(fp))!=EOF)
    {
 
        i++;
    }
    str_1[i]='\0';
    printf("%s\n%d\n",str_1,str_1[6]);
/*    
    putc(r_number,fp);
    putc(100,fp);
    rewind(fp);
    getc(fp);
    getc(fp);
    printf("%s\n",str_1);
    printf("%s\n",str);
 */
    fclose(fp);
    return 0;
}
