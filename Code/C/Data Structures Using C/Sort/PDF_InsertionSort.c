#include <stdio.h>
#include <stdlib.h>

#define size 5

void insertion_sort(int arr[], int n);

int main()
{
    int arr[size], i;

    printf("\n Enter the elements of the array: ");

    for (i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    insertion_sort(arr, size);

    printf("\n The sorted array is: \n");
    for (i = 0; i < size; i++)
        printf(" %d\t", arr[i]);
    
    return 0;
}

void insertion_sort(int arr[], int n)
{
    int i, j, temp;
    for (i = 1; i < n; i++)
    {
        temp = arr[i];
        j = i - 1;
        while ((temp < arr[j]) && (j >= 0))
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}