#include <stdio.h>

#define MAX 10

int arr[MAX] = {12, 76, 23, 54, 90, 13, 63, 83, 26, 93};

void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void swap(int *a, int *b);
void display(int arr[]);

int main(int argc, char const *argv[])
{
    display(arr);
    quickSort(arr, 0, MAX - 1);
    display(arr);
    return 0;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high);

        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

int partition(int arr[], int low, int high)
{
    int i = low - 1;
    int pivot = arr[high];

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void display(int arr[])
{
    printf("\nThe array: \n");
    for (int i = 0; i < MAX; i++)
        printf("  %d", arr[i]);
}