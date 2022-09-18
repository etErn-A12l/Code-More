#include <stdio.h>
int main(void)
{
    int i, j, n;
    printf("Enter the length: ");
    scanf("%d", &n);
    // upper half of the pattern
    for(i = 0; i < n; i++) 
    {
        for(j = 0; j < (2 * n); j++)
        { 
            if(i + j <= n - 1)  // upper left triangle
                printf("*");
            else
                printf(" ");
            if((i + n) <= j)  // upper right triangle
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    // bottom half of the pattern
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < (2 * n); j++)
        {
            if(i >= j)  //bottom left triangle
                printf("*");
            else
                printf(" ");
            if(i >= (2 * n - 1) - j)  // bottom right triangle
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}
