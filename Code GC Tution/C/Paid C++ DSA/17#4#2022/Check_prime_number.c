#include <stdio.h>
#include <stdbool.h>

int main()
{
    int num;
    // bool check = true;
    printf("Enter the number: ");
    scanf("%d", &num);
    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
        {
            goto result;
            break;
        }
    }
    printf("The number is prime !");
result:
    printf("The number is not prime !");
    return 0;
}
