#include <stdio.h>

#define max 10

int a[10] = {27, 31, 10, 35, 42, 44, 14, 19, 26, 33};
int b[10];

void merging(int low, int mid, int high)
{
    int l1, l2, i;

    for (l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++)
    {
        if (a[l1] <= a[l2])
            b[i] = a[l1++];
        else
            b[i] = a[l2++];
    }

    while (l1 <= mid)
        b[i++] = a[l1++];

    while (l2 <= high)
        b[i++] = a[l2++];

    for (i = low; i <= high; i++)
        a[i] = b[i];
}

void sort(int low, int high)
{
    int mid;

    if (low < high)
    {
        mid = (low + high) / 2;

        // printf("\n\n sort(low, mid);  =   sort(%d, %d);", low, mid);
        // printf("\n sort(%d, %d);", a[low], a[mid]);
        sort(low, mid);

        // printf("\n\n sort(mid + 1, high); =   sort(%d, %d);", mid + 1, high);
        // printf("\n sort(%d, %d);", a[mid + 1], a[high]);
        sort(mid + 1, high);

        // printf("\n\n merging(low, mid, high); =   merging(%d, %d, %d);", low, mid, high);
        // printf("\n merging(%d, %d, %d);", a[low], a[mid], a[high]);
        merging(low, mid, high);
    }

    else
    {
        return;
    }
}

int main()
{
    int i;

    printf("List before sorting\n");

    for (i = 0; i < max; i++)
        printf("%d ", a[i]);

    sort(0, max - 1);

    printf("\nList after sorting\n");

    for (i = 0; i < max; i++)
        printf("%d ", a[i]);

    return 0;
}