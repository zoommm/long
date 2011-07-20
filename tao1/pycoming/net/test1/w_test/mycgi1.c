#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int i,n;
    printf("Contenttype:text/plan\n\n");
    n = 0;

    printf("%s\n",getenv("QUERY_STRING"));
    fflush(stdout);
    return 0;
}
