#include <stdio.h>

// Function to find the maximum of two integers
int max(int a, int b)
{
    return (a > b) ? a : b;
}

// Function to solve 0/1 knapsack problem using dynamic programming
int knapsack(int W, int wt[], int val[], int n)
{
    int i, j;
    int K[n + 1][W + 1];

    // Build table K[][] in bottom up manner
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
                K[i][j] = 0;
            else if (wt[i - 1] <= j)
                K[i][j] = max(val[i - 1] + K[i - 1][j - wt[i - 1]], K[i - 1][j]);
            else
                K[i][j] = K[i - 1][j];
        }
    }

    // Return the maximum value
    return K[n][W];
}

int main()
{
    int val[] = {35, 40, 28, 16};
    int wt[] = {4, 3, 5, 2};
    int W = 7;
    int n = sizeof(val) / sizeof(val[0]);
    printf("Maximum value: %d\n", knapsack(W, wt, val, n));
    return 0;
}
