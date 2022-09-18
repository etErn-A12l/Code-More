#include <stdio.h>

int main()
{
    long int num, result = 1;
    long i;
    printf("Enter the number: ");
    scanf("%d", &num);
    for (i = num; i > 1; i--)
    {
        result = result * i;
    }
    printf("The factorial of the given number is: %d", result);
    return 0;
}
