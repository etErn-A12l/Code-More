#include <stdio.h>

int main()
{
    int num, arr[4];
    printf("Enter a number: ");
    scanf("%d", &num);
    int sum = 0, n = num;
    while (n != 0)
    {
        sum = sum + n % 10;
        n = n / 10;
    }
    printf("The sum of the digits of %d is :%d", num, sum);
    return 0;
}
