#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr;
    // ptr = (int*)malloc(3 * sizeof(int));
    ptr = (int *)calloc(3, sizeof(int));
    for(int i = 0;i<10;i++)
    {
        ptr[i] = i+1;
    }
    for (int i = 0; i < 3; i++)
    {
        printf("%d\n", ptr[i]);
    }

    ptr = realloc(ptr, 5 * sizeof(int));

    free(ptr);
    for (int i = 0; i < 3; i++)
    {
        printf("%d\n", ptr[i]);
    }
    return 0;
}
