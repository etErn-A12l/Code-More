//This is a programm to see all types of patterns
#include <stdio.h>
#include <math.h>
#include <conio.h>

int main()
{
    int n, rows, i, j, remainder, coef, space;
    printf("\n\n     :You Have Entered a Pattern Zone:\n\n\n");
    printf("Press 0 To See Half Pyramid of Number\n");
    printf("Press 1 To See Half Pyramid of Serial Number\n");
    printf("Press 2 To See Half Pyramid of Stars\n");
    printf("Press 3 To See Reverse Half Pyramid of Number\n");
    printf("\nYour Choice: ");
    scanf("%d", &n);
    if (n > 3)
    {
        printf("You Have Pressed Wrong Key;\nPlease Try Again seeing The Above Menu:- ");
    }
    if (n >= 0 && n < 4)
    {
        switch (n)
        {
        case 0:
            printf("\nEnter The Number of Rows: ");
            scanf("%d,&rows");
            for (i = 1; i <= rows; i++)
            {
                printf("\n");
                for (j = 1; j <= i; j++)
                {
                    printf("%d", j);
                }
            }
            return 0;
        case 1:
            printf("\nEnter The Number of Rows: ");
            scanf("%d,&rows");
            for (i = 1; i <= rows; i++)
            {
                printf("\n");
                for (j = 1; j <= i; j++)
                {
                    printf("%d", i);
                }
            }
            return 0;
        case 2:
            printf("\nEnter The Number of Rows: ");
            scanf("%d,&rows");
            for (i = 1; i <= rows; i++)
            {
                printf("\n");
                for (j = 1; j <= i; j++)
                {
                    printf("*", i);
                }
            }
            return 0;
        }
    }

    return 0;
}
