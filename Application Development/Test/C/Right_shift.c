// #include <stdio.h>

// void main()
// {
//     int n = 10;
//     for (int i = 0; i < sizeof(n); i++)
//     {
//         printf("%d\n", n >> (sizeof(n) - i - 1));
//     }
//     // printf("%d",n>>(sizeof(n) - 0 - 1));
// }

#include <stdio.h>
#include <stdint.h>

void main()
{
    uint16_t n = 10;
    // for (int i = 0; i < sizeof(n) * 8; i++)
    // {
    //     printf("%d", (n >> ((sizeof(n) * 8) - i - 1)) & 1);
    // }
    // printf("\n");
    for (int i = 0; i < sizeof(n) * 2; i++)
    {
        printf("%d", (n >> (sizeof(n) * 2 - i - 1)) & 1);
    }
}