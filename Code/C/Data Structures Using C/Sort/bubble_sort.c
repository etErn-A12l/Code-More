#include <stdio.h>
#define SIZE 5

int arr[SIZE];

void bubbleSort(int arr[]);
void display(int arr[]);

int main(int argc, char const *argv[])
{
    printf("Enter the elements for the array: \n");
    for (int i = 0; i < SIZE; i++)
        scanf("%d", &arr[i]);
    display(arr);
    bubbleSort(arr);
    display(arr);
    return 0;
}

void bubbleSort(int arr[])
{
    for (int i = 0; i < SIZE - 1; i++)
    {
        for (int j = 0; j < SIZE - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void display(int arr[])
{
    printf("\nThe array is below: \n");
    for (int i = 0; i < SIZE; i++)
        printf("\t%d", arr[i]);
}