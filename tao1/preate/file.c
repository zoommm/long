#include <stdio.h>
#include <stdlib.h>
int main(int argc, const char *argv[])
{
    FILE *fp;
    char str[100]="hello world!!!!";
    char str_1[100];
    int r_number=20;
    fp = fopen("text1","w+");
    if (fp==NULL) 
    {
        perror("open:");
        exit(0);
    }
    fprintf(fp, "%s         %d\n",str,r_number);
     rewind(fp);
    fscanf(fp,"%d",&r_number);
    printf("str_1 :%s   number= : %d\n",str_1,r_number);
    printf("\n");
    fclose(fp);

    return 0;
}
