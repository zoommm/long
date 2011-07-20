#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int i,n;
    printf("Contenttype:text/plan\n\n");
    n = 0;
/*
    if (getenv("CONTENT_LENGTH")) 
    {
        n = atoi(getenv("CONTENT-LENGTH"));
    }
    for (i = 0; i < n-1; putchar(getchar())); 
    putchar('\n');
*/
    printf("%s\n",getenv("QUERY_STRING"));
    fflush(stdout);
    return 0;
}
