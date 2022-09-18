// Take input from the user until he enters 75

#include <stdio.h>

int main()
{
    for (int i = 0; i >= 0; i++)
    {
        int num;
        printf("Tumi amake 75 dao: ");
        scanf("%d", &num);
        if (num == 75)
        {
            break;
        }
        // else
        // {
        //     continue;
        // }
    }
    return 0;
}
