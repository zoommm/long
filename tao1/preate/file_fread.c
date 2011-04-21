#include <stdio.h>
#include<stdlib.h>
int main(int argc, const char *argv[])
{
    FILE *fp1;
    FILE * fp2;
    char str[1024];
    int n=0;
    int i=0;
    fp1=fopen("s","r+");
    if (fp1==NULL) 
    {
        perror("fp1");
        exit(0);
    }
    fp2=fopen("d","r+");
    if (fp2==NULL) 
    {
        perror("fp2");
        exit(0);
    }
    i=0;
    while(!feof(fp1))
    {
         n += fread(&str[i],1,4,fp1);
         i +=4;
    }
    i-=4;
     fwrite(&str[0],1,n,fp2);
    
    printf("i= %d\tn= %d\n",i,n);
    fclose(fp1);
    fclose(fp2);
    return 0;
}
