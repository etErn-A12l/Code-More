#include <stdio.h>

int main()
{
    int row = 4;
    int space = 3;
    int number = 1;

    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= space; j++)
        {
            printf("  ");
        }
        space--;
        for (int k = 1; k <= number; k++)
        {
            printf("%d ",i);
        }
        number++;
        printf("\n");
    }
    return 0;
}
