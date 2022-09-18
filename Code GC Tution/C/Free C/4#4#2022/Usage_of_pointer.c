#include <stdio.h>

void swap(int *a1, int *b2)
{
    int temp;
    temp = *a1;
    *a1 = *b2;
    *b2 = temp;
}

int main()
{
    int a = 23, b = 78;
    swap(&a, &b);
    printf("a = %d and b = %d", a, b);
    return 0;
}
