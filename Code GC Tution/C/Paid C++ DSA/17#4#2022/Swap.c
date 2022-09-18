#include <stdio.h>

int main()
{
    int a = 2;
    int b = 3;

    printf("a = %d and b = %d\n", a, b);

    // int temp = a;
    // a = b;               // Using 3rd Variable
    // b = temp;
    a = a + b;
    b = a - b;
    a = a - b;
    printf("Value swapped successfully !\n");

    printf("a = %d and b = %d\n", a, b);

    return 0;
}
