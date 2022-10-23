#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int heap[MAX];

void insert(int heap[]);
void heapify(int heap[], int size, int i);
void heapSort(int heap[], int size);
void swap(int *a, int *b);
void display(int heap[]);

int main(int argc, char const *argv[])
{
    int option;
    system("cls");
    do
    {
        printf("\n\n**** MENU ****");
        printf("\n1. Insert");
        printf("\n2. Display");
        printf("\n3. Heap Sort");
        printf("\n\nEnter your choice: ");
        scanf("%d", &option);
        system("cls");

        if (option == 1)
            insert(heap);
        else if (option == 2)
            display(heap);
        else if (option == 3)
            heapSort(heap, MAX);
        else
            printf("\nWrong Choice !");
    } while (option < 4);

    return 0;
}

void insert(int heap[])
{
    printf("\nEnter elements for the heap: \n");
    for (int i = 0; i < MAX; i++)
    {
        printf("Element for %dth element: ", i);
        scanf("%d", &heap[i]);
    }
}

void heapify(int heap[], int size, int i)
{
    int index = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (heap[index] < heap[left] && left < size)
        index = left;
    if (heap[index] < heap[right] && right < size)
        index = right;

    if (i != index)
    {
        swap(&heap[i], &heap[index]);
        heapify(heap, size, index);
    }
}

void heapSort(int heap[], int size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapify(heap, MAX, i);
    }

    for (int i = size - 1; i >= 0; i--)
    {
        swap(&heap[0], &heap[i]);
        heapify(heap, i, 0);
    }
    printf("\nSorted the Heap !");
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void display(int heap[])
{
    printf("\nBelow is the heap: \n\n");
    for (int i = 0; i < MAX; i++)
    {
        printf("  %d", heap[i]);
    }
}