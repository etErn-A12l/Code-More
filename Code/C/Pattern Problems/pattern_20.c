#include <stdio.h>

int main()
{
    int a = 10, space = 9, star = 1;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < space; j++)
        {
            printf(" ");
        }
        space--;
        for (int k = 0; k < star; k++)
        {
            printf("* ");
            // printf(" ");
        }
        star++;
        printf("\n");
    }
    for (int i = 0; i < 5; i++)
    {
        space++;
        for (int j = 0; j < space; j++)
        {
            printf(" ");
        }
        star--;
        for (int k = 0; k < star; k++)
        {
            printf("* ");
            // printf(" ");
        }
        printf("\n");
    }
    return 0;
}

/*

        *
       * *
      * * *
     * * * *
    * * * * *
    * * * * *
     * * * *
      * * *
       * *
        *

*/

