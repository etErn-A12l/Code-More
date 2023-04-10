#include <stdio.h>

#define MAX 5

void findMinMax(int arr[], int low, int high, int *min, int *max);

int main()
{
    int arr[MAX];
    printf("Enter the elements for the array: \n");
    for (int i = 0; i < MAX; i++)
    {
        printf("Enter element no. %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    int min, max;

    findMinMax(arr, 0, MAX - 1, &min, &max);

    printf("\n\nMIN: %d\t\tMAX: %d\n\n", min, max);

    return 0;
}

void findMinMax(int arr[], int low, int high, int *min, int *max)
{
    if (high == low)
        *min = *max = arr[low];

    else if ((high - low) == 1)
    {
        if (arr[low] < arr[high])
        {
            *min = arr[low];
            *max = arr[high];
        }
        else
        {
            *min = arr[high];
            *max = arr[low];
        }
    }
    else
    {
        int mid = (low + high) / 2;
        int min1, max1, min2, max2;

        findMinMax(arr, low, mid, &min1, &max1);
        findMinMax(arr, mid + 1, high, &min2, &max2);

        *min = (min1 < min2) ? min1 : min2;
        *max = (max1 > max2) ? max1 : max2;
    }
}
