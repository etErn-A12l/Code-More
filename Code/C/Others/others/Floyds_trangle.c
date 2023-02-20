#include <stdio.h>

int main()
{
    int number = 1;

    for (int i = 0; i < 14; i++)
    {
        for (int j = 0; j < i; j++)
        {
            printf("%d ", number);
            number++;
        }
        printf("\n");
    }
    return 0;
}

// 1
// 2 3
// 4 5 6
