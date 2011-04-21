#include<stdio.h>
#define nmemb 3
struct test
{
char name[20];
int size;
}s[nmemb];
main()
{
FILE *stream;
int i;
stream = fopen("text2","r+");
fread(s,sizeof(struct test),nmemb,stream);
fclose(stream);
for(i=0;i<nmemb;i++)
printf("name[%d]=%-20s:size[%d]=%d\n",i,s[i].name,i,s[i].size);
}

