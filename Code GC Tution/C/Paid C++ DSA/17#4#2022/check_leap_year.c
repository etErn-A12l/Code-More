#include <stdio.h>

int main()
{
    int year;
    printf("Enter the year that you wanna check: ");
    scanf("%d", &year);
    if (year % 4 == 0)
    {
        printf("ota leap year chilooooooooo !");
    }
    else
    {
        printf("ota leap year chilo naaaaaaaaaa !");
    }
    return 0;
}
