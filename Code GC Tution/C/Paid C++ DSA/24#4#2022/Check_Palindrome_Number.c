#include <stdio.h>

int main(int argc, char const *argv[])
{
    int num, check = 0;
    printf("Enter the Number: ");
    scanf("%d", &num); // 1233

    int temp = num;
    while (temp > 0)
    {
        int bachur = temp % 10;
        check = (check * 10) + bachur;
        temp = temp / 10;
    }
    // printf("%d",check);
    if (num == check)
    {
        printf("The number is Palindrome number !");
    }
    else
    {
        printf("The number is not a Palindrome number !");
    }
    return 0;
}
