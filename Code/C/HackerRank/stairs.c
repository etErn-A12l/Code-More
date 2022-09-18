#include <stdio.h>

int main(int argc, char const *argv[])
{
    int steps, proceeding = 0,count = 0;
    printf("Enter the number of steps you wanna proceed: ");
    scanf("%d", &steps);
    while (proceeding <= steps)
    {
        if ((steps - proceeding) >= 3)
        {
            proceeding += 3;
            printf("Moved 3 Steps !\n");
            printf("\nProceeded %d\n", proceeding);
            count++;
        }
        if ((steps - proceeding) >= 2)
        {
            proceeding += 2;
            printf("Moved 2 steps !\n");
            printf("\nProceeded %d\n", proceeding);
            count++;
        }
        else if ((steps - proceeding) >= 1)
        {
            proceeding += 1;
            printf("Moved 1 steps !\n");
            printf("\nProceeded %d\n", proceeding);
            count++;
        }
        else
        {
            break;
        }  
    }
    printf("\n\nThe required Steps are: %d", count);
    return 0;
}
