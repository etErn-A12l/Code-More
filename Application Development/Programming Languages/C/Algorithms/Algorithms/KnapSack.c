#include <stdio.h>

void swapFloat(float *n1, float *n2)
{
    float temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

void swapInt(int *n1, int *n2)
{
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

void fractional_knapsack(int W, int n, int val[], int wt[])
{
    float kept = 0, value = 0;
    float pi_wi[n];
    for (short i = 0; i < n; i++)
        pi_wi[i] = (float)val[i] / (float)wt[i];

    for (short i = 0; i < n - 1; i++)
    {
        for (short j = 0; j < n - 1 - i; j++)
        {
            if (pi_wi[j] < pi_wi[j + 1])
            {
                swapFloat(&pi_wi[j], &pi_wi[j + 1]);
                swapInt(&wt[j], &wt[j + 1]);
                swapInt(&val[j], &val[j + 1]);
            }
        }
    }

    printf("\nProfit\t");
    for (short i = 0; i < n; i++)
        printf("\t%d", val[i]);
    printf("\nWeight\t");
    for (short i = 0; i < n; i++)
        printf("\t%d", wt[i]);
    printf("\nFraction");
    for (short i = 0; i < n; i++)
        printf("\t%.2f", pi_wi[i]);

    short iterator = 0;
    while (kept < W)
    {
        int storage_left = W - kept;
        if (wt[iterator] <= storage_left)
        {
            kept += wt[iterator];
            value += val[iterator];
        }
        else
        {
            float profit = (float)val[iterator] * storage_left / wt[iterator];
            value += profit;
            kept += storage_left;
        }
        iterator++;
    }
    printf("\n\nGot PROFIT: %.2f, Total wight: %.f\n\n", value, kept);
}

int main()
{
    int val[] = {25, 24, 15};
    int wt[] = {18, 15, 10};
    int W = 20;
    int n = sizeof(val) / sizeof(val[0]); // no. of elements in the array

    // printf("The maximum value that can be put in a knapsack of capacity %d is: %d\n", W, knapSack_01(W, wt, val, n));

    fractional_knapsack(W, n, val, wt);
    return 0;
}
