#include <stdio.h>

int main(int argc, char const *argv[])
{
    int arr[10];

    for (int counter = 0; counter < 10; counter++)
    {
        printf("Enter the value of %dth element of the array: ", counter + 1);
        scanf("%d", &arr[counter]);
    }
    printf("\nThis is your array................\n");
        for (int counter = 0; counter < 10; counter++)
    {
        printf("The value of %dth element of the array: %d\n", counter + 1,arr[counter]);
    }
    return 0;
}
