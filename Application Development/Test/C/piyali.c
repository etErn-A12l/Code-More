#include <stdio.h>

int lcm(int a, int b, int max);
int hcf(int a, int b);

int main()
{
    int a, b, p, q, max;
    printf ("Enter the numbers: ");
    scanf("%d %d", &a, &b);
    max = (a > b) ? a : b;
    p = lcm(a, b, max);
    printf("LCM = %d\n", p);
    q = hcf(a, b);
    printf("HCF = %d", q);
    return 0;
}

int lcm(int a, int b, int max)
{
    while (1)
    {
        if (max % a == 0 && max % b == 0)
        {
            return max;
            break;
        }
        else
        {
            max++;
        }
    }
}

int hcf(int a, int b)

{
    int res;
    for (int i = 1; i <= a && i <= b; i++)
    {
        if (a % i == 0 && b % i == 0)
            res = i;
        else
            continue;
    }
    return res;
}

