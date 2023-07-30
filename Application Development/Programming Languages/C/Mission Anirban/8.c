#include <stdio.h>
int main()
{

    int arr1[2][3], arr2[2][3];

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("Enter value for Array 1 [%d][%d]:", i, j);
            scanf("%d", &arr1[i][j]);
        }
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("Enter value for Array 2 [%d][%d]:", i, j);
            scanf("%d", &arr2[i][j]);
        }
    }

    printf("Two Dimensional array elements:\n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", arr1[i][j]);
            if (j == 2)
            {
                printf("\n");
            }
        }
    }

    printf("Two Dimensional array elements:\n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", arr2[i][j]);
            if (j == 2)
            {
                printf("\n");
            }
        }
    }
    return 0;
}