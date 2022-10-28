// Write a program to search an element in an array using interpolation search.

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int interpolation_search(int a[], int low, int high, int val)
{
    int mid;
    while (low <= high)
    {
        mid = low + (high - low) * ((val - a[low]) / (a[high] - a[low]));
        if (val == a[mid])
            return mid;
        if (val < a[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int main()
{
    int arr[MAX], val, pos;

    printf("\n Enter the elements : ");
    for (int i = 0; i < MAX; i++)
        scanf("%d", &arr[i]);

    printf("\n Enter the value to be searched : ");
    scanf("%d", &val);

    pos = interpolation_search(arr, 0, MAX-1, val);

    if (pos == -1)
        printf("\n %d is not found in the array", val);
    else
        printf("\n %d is found at position %d", val, pos);

    return 0;
}