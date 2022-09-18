#include <stdio.h>

int main()
{
    int i, j, n;
    long int c;
    double d, sum = 0;

    printf("Enter the last digit: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        printf("i=%d\n", i);
        c = 1;
        for (j = 1; j <= i; j++)
        {
            c *= j;
            printf("j=%d\n", j);
        }
        printf("c=%ld\n", c);
        d = i / c;
        printf("d=%f\n", d);
        sum += d;
    }
    
    printf("sum is: %f", sum);

    return 0;
}