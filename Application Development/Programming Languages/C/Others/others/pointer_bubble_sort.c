#include <stdio.h>

void bubblesort(int a[], int n)
{
    int i = 0, j = 0, temp, *pa;
    pa = &a[0];
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (*(pa + j) > *(pa + j + 1))
            {
                temp = *(pa + j);
                *(pa + j) = *(pa + j + 1);
                *(pa + j + 1) = temp;
            }
        }
    }

    printf("\nThe array element after sorting:=\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", *(pa + i));
    }
    // return 0;
}

int main()
{
    int a[20], i, n, *pa = &a[0];

    // for (i = 0; i < 5; i++)
    //     scanf("%d", &a[i]);
    // // int *pa;

    // int *pa = &a[0];
    // for (i = 0; i < 5; i++)
    //     scanf("%d", *(pa + i));

    printf("\nenter the number of element in the array:");
    scanf("%d", &n);
    printf("\nenter the elements for the array :\n");

    for (i = 0; i < n; i++)
        scanf("%d", (pa + i));

    bubblesort(a, n);

    return 0;
}
