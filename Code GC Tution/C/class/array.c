#include <stdio.h>

int main()
{
    int sweety[2][2], rituraj[2][3];
    int i, j;

    for (i = 0; i <= 1; i++)
    {
        for (j = 0; j <= 1; j++)
        {
            printf("\nEnter the value for sweety[%d][%d]: ", i, j);
            scanf("%d", &sweety[i][j]);
        }
    }

    for (i = 0; i <= 1; i++)
    {
        for (j = 0; j <= 1; j++)
        {
            printf("\nEnter the value for rituraj[%d][%d]: ", i, j);
            scanf("%d", &rituraj[i][j]);
        }
    }

    printf("\nThe Sweety matrix is below: \n");
    for (i = 0; i <= 1; i++)
    {
        for (j = 0; j <= 1; j++)
        {
            printf("%d ", sweety[i][j]);
        }
        printf("\n");
    }

    printf("\nThe Rituraj matrix is below: \n");
    for (i = 0; i <= 1; i++)
    {
        for (j = 0; j <= 1; j++)
        {
            printf("%d ", rituraj[i][j]);
        }
        printf("\n");
    }

    printf("\nThe Sum matrix is below: \n");
    for (i = 0; i <= 1; i++)
    {
        for (j = 0; j <= 1; j++)
        {
            printf("%d ", sweety[i][j] + rituraj[i][j]);
        }
        printf("\n");
    }

    return 0;
}

/*

i = 0
    j = 0, 1 , 2, 3

i = 1
    j = 0, 1 , 2, 3

i = 2
    j = 0, 1 , 2, 3

i = 3
    j = 0, 1 , 2, 3

4 * 4
*/