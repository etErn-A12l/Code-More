#include <stdio.h>
#define MAX 5

int arr[MAX];

void selectionSort(int arr[]);
void display();

int main(int argc, char const *argv[])
{
    printf("Enter the elements for the array: \n");
    for (int i = 0; i < MAX; i++)
        scanf("%d", &arr[i]);
    display(arr);
    selectionSort(arr);
    display(arr);
    return 0;
}

void selectionSort(int arr[])
{
    for(int i = 0;i< MAX -1 ;i++)
    {
        int min = i;
        for(int j = i+1; j< MAX ;j++)
        {
            if (arr[min] > arr[j])
                min = j;
        }
        if( min != i)
        {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}

void display(int arr[])
{
    printf("\nThe array is below: \n");
    for (int i = 0; i < MAX; i++)
        printf("\t%d", arr[i]);
}