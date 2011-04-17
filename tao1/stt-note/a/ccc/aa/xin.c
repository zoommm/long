#include <stdio.h>

int main()

{
    int i,j,k,n;
    for (scanf("%d",&n), k = 0; k < n; k++ , printf("===================\n"))
    for (i = 0; i < n;printf("\n"), i++) 
    for (j = 0; j < n;printf("%d",(j+k+i)%n+1), j++) ;
    printf("this is god\n");    
}
