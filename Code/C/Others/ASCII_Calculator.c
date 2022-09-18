#include <stdio.h>

int main()
{
    char first = 'A';

    while (first != '&')
    {
        printf("The ASCII Value for %c is: %d\n", first, first);
        first++;
    }
    return 0;
}
