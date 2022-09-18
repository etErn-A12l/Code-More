#include <stdio.h>
int main()
{
    int i, j, k, m, n;
    n = m = 8;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
           printf(" "); 
        }
        m--;
        for (k = 1; k <= i; k++)
        {
            printf("%d ", j);
        }
        printf(" \n");
    }
    return 0;
}