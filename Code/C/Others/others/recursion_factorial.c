#include <stdio.h>

int fact(int num)
{
    // int ans = 1;
    if (num == 1)
    {
        return 1;
    }
    int fuck = fact(num - 1);
    int ans = fuck * num;

    return ans;
}
int main()
{
    int num = 5;
    printf("%d", fact(num));
    return 0;
}
