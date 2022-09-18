#include <stdio.h>

int main()
{
    int arr[10];

    // arr[0] = 23;
    // printf("%d",arr[0]);
    for (int i = 0; i <= 10 - 1; i++)
    {
        arr[i] = i + 10;
    }

    for (int i = 0;i< 10;i++)
    {
        printf("The %dth value of the array is: %d\n",i+1,arr[i]);
    }

    return 0;
}
