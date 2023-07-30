#include <stdio.h>
#define MAX 10

void insertionSort(int arr[]);
void display(int arr[]);

int main(int argc, char const *argv[])
{
    int arr[MAX] = {90, 45, 23, 78, 14, 58, 87, 36, 84, 63};

    printf("\n\nThe Array before insertion sort: \n");
    display(arr);

    insertionSort(arr);

    printf("\n\nThe Array after insertion sort: \n");
    display(arr);
    return 0;
}

void insertionSort(int arr[])
{
    int key, i, j;
    for (j = 1; j < MAX; j++)
    {
        key = arr[j];
        i = j - 1;
        while (i >= 0 && arr[i] > key)
        {
            arr[i + 1] = arr[i];
            i--;
        }
        arr[i + 1] = key;
    }
}

void display(int arr[])
{
    for (size_t i = 0; i < MAX; i++)
    {
        printf("\t%d", arr[i]);
    }
}