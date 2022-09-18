#include <stdio.h>
#define MAX 5

int arr[MAX] = {12, 90, 43, 13, 76};

void BinarySearch(int arr[]);
void selectionSort(int arr[]);
void display(int arr[]);

int main(int argc, char const *argv[])
{
    printf("Enter the elements for the array: \n");
    // for (int i = 0; i < MAX; i++)
    //     scanf("%d", &arr[i]);
    display(arr);
    selectionSort(arr);
    display(arr);
    BinarySearch(arr);
    return 0;
}

void selectionSort(int arr[])
{
    for (int i = 0; i < MAX - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < MAX; j++)
        {
            if (arr[min] > arr[j])
                min = j;
        }
        if (min != i)
        {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}

void BinarySearch(int arr[])
{
    int value;
    printf("\nEnter the element to find: ");
    scanf("%d", &value);
    int left = 0, right = MAX - 1, mid, found = 0;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (arr[mid] == value)
        {
            found = 1;
            break;
        }
        else if (value > arr[mid])
            left = mid + 1;
        else
            right = mid - 1;
    }
    if (found == 1)
        printf("\n%d is found in %dth index !", value, mid);
    else
        printf("\nElement not found !");
}

void display(int arr[])
{
    printf("\nThe array is below: \n");
    for (int i = 0; i < MAX; i++)
        printf("\t%d", arr[i]);
}