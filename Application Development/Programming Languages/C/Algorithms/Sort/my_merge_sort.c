#include <stdio.h>
#define MAX 5

int arr[MAX];
int brr[MAX];

void merge(int low, int mid, int high);
void mergeSort(int low, int high);

int main()
{
    printf("Enter the elements for the array: \n\n");
    for (int i = 0; i < MAX; i++)
    {
        printf("Enter element for index %d: ", i);
        scanf("%d", &arr[i]);
    }
    mergeSort(0, MAX - 1);
    printf("\nThe Sorted array is Below: \n");
    for (int i = 0; i < MAX; i++)
        printf("\t%d", arr[i]);
    return 0;
}

void mergeSort(int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;

        mergeSort(low, mid);
        mergeSort(mid + 1, high);

        merge(low, mid, high);
    }
}

void merge(int low, int mid, int high)
{
    int i, l1, l2;
    for (i = low, l1 = low, l2 = mid + 1; l1 <= mid && l2 <= high; i++)
    {
        if (arr[l1] <= arr[l2])
            brr[i] = arr[l1++];
        else
            brr[i] = arr[l2++];
    }

    while (l1 <= mid)
        brr[i++] = arr[l1++];

    while (l2 <= high)
        brr[i++] = arr[l2++];

    for (i = low; i <= high; i++)
        arr[i] = brr[i];
}