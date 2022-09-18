#include <stdio.h>

const int row = 3;
const int colmn = 4;

int main()
{
    int arr[3][4];
    
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < colmn; j++)
        {
            arr[i][j] = i+j+2;
        }
    }

    return 0;
}
