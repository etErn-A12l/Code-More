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

int knapSack_01(int W, int wt[], int val[], int n)
{
    // Declare loop variables i (for items) and w (for capacity)
    int i, w;

    // Create a 2D array K to store optimal solutions for subproblems (n+1 rows and W+1 columns)
    int K[n + 1][W + 1];

    // Loop through all items (0 to n) and all capacities (0 to W)
    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            // Initialize the first row and column of the array K to 0
            if (i == 0 || w == 0)
                K[i][w] = 0;
            // If the current item's weight is less than or equal to the current capacity,
            // choose the maximum value between including the current item or not
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            // If the current item's weight is greater than the current capacity,
            // the optimal solution is the same as the previous row (excluding the current item)
            else
                K[i][w] = K[i - 1][w];
        }
    }

    // Return the maximum value that can be put in a knapsack of capacity W
    return K[n][W];
}

int fractional_knapsack(int W, int n, int val[], int wt[])
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

    for (short i = 0; i < n; i++)
        printf("val = %d\t", val[i]);
    printf("\n");
    for (short i = 0; i < n; i++)
        printf("wt = %d\t\t", wt[i]);
    printf("\n");
    for (short i = 0; i < n; i++)
        printf("fr = %f\t", pi_wi[i]);

    short iterator = 0;
    while (kept <= W)
    {
        int storage_left = W - kept;
        if (wt[iterator] <= storage_left){
            kept += wt[iterator];
            value += val[iterator];
        }
    }

    return 0;
}

int main()
{
    int val[] = {25, 24, 15};
    int wt[] = {18, 15, 10};
    int W = 20;
    int n = sizeof(val) / sizeof(val[0]); // no. of elements in the array

    // printf("The maximum value that can be put in a knapsack of capacity %d is: %d\n", W, knapSack_01(W, wt, val, n));

    int ab = fractional_knapsack(W, n, val, wt);
    return 0;
}
