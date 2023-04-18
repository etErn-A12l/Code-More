#include <stdio.h>

int main()
{
    int arr[5], i;
    for (i = 0; i < 5; i++)
        arr[i] = -1;

    for (i = 0; i < 5; i++)
        printf("\t%d", arr[i]);
    return 0;
}
