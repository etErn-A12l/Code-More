
// Without using a temporary variable and with only one loop
#include <stdio.h>

void floyd(n)
{
    int line = 1;
    for (int i = 0; i < n; i++)
    {
        if(i == line)
        {
            printf("\n");
            line++;
        }
        printf("%d ", i+1);
    }
}

int main()
{
    floyd(6);
}