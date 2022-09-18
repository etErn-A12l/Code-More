#include <stdio.h>
#define MAX 10

int main(int argc, char const *argv[])
{
    int arr[MAX][MAX][MAX];

    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            for (int k = 0; k < MAX; k++)
            {
                arr[i][j][k] = k;
            }
        }
    }

    printf("\nHere is your 3D array : \n\n");

    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            for (int k = 0; k < MAX; k++)
            {
                printf("%d ", arr[i][j][k]);
            }
            printf("\n");
        }
        printf("\n\n");
    }
    return 0;
}
