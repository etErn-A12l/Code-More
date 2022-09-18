#include <stdio.h>

int main()
{
    int i = 3;
    int *j;
    j = &i;
    printf("Address of i = %u\n", &i);
    printf("Address of i = %u\n", j);
}