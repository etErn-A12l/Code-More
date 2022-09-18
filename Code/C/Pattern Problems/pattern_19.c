#include <stdio.h>

#define Height 20
#define Width 20

int main()
{
    int k = 1;
    for (int i = 0; i < Height / 2; i++)
    {
        for (int j = 0; j < k; j++)
        {
            printf("* ", j);
        }
        for (int g = 0; g < Width - (k * 2); g++)
        {
            printf("  ");
        }
        for (int j = 0; j < k; j++)
        {
            printf("* ", j);
        }
        k++;
        printf("\n");
    }
    for (int i = Height / 2; i > 0; i--)
    {
        k--;
        for (int j = 0; j < k; j++)
        {
            printf("* ", j);
        }
        for (int g = 0; g < Width - (k * 2); g++)
        {
            printf("  ");
        }
        for (int j = 0; j < k; j++)
        {
            printf("* ", j);
        }
        printf("\n");
    }
    return 0;
}

// *                          *
// * *                      * *
// * * *                  * * *
// * * * *              * * * *
// * * * * *          * * * * *
// * * * * * *      * * * * * *
// * * * * * * *  * * * * * * *
// * * * * * * *  * * * * * * *
// * * * * * *      * * * * * *
// * * * * *          * * * * *
// * * * *              * * * *
// * * *                  * * *
// * *                      * *
// *                          *