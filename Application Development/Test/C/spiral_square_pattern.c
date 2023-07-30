#include <stdio.h>

int main()
{
    short int row, colmn;
    printf("Enter the no. of rows: ");
    scanf("%hd", &row);
    printf("Enter the no. of columns: ");
    scanf("%hd", &colmn);
    printf("\n");

    int arr[row][colmn]; // Initializing the array of derired size

    // Taking input from user
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < colmn; j++)
        {
            printf("Element of %dth row %dth coloumn: ", i + 1, j + 1);
            scanf("%d", &arr[i][j]);
        }
    }
    printf("\n");

    // Normal Matrix Print
    printf("Printing the Matrix Normally: \n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < colmn; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // Spiral Print of the Matrix
    int count = row * colmn;                 // Total no. of elements in the Matrix
    int direction = 1;                       // It will help to print the elements
    int top = 0, left = 0;                   // Required to follow the index
    int right = colmn - 1, bottom = row - 1; // required to maintain row and coloumns

    printf("Printing the Matrix in Spiral way: \n");
    while (left <= right && top <= bottom)
    {

        if (direction == 1 && count > 0) // printing elements left to right
        {
            for (int i = left; i <= right; i++)
            {
                printf("%d ", arr[top][i]);
                count--;
            }
            direction = 2;
            top++;
            printf("\n");
        }

        if (direction == 2 && count > 0) // printing elements right to bottom
        {
            for (int i = top; i <= bottom; i++)
            {
                printf("%d ", arr[i][right]);
                count--;
            }
            direction = 3;
            right--;
            printf("\n");
        }

        if (direction == 3 && count > 0) // printing elements bottom to left
        {
            for (int i = right; i >= left; i--)
            {
                printf("%d ", arr[bottom][i]);
                count--;
            }
            direction = 4;
            bottom--;
            printf("\n");
        }

        if (direction == 4 && count > 0) // printing elements left to top
        {
            for (int i = bottom; i >= top; i--)
            {
                printf("%d ", arr[i][left]);
                count--;
            }
            direction = 1;
            left++;
            printf("\n");
        }
    }

    return 0;
}
