#include <stdio.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int knapSack(int W, int wt[], int val[], int n)
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

int main()
{
    int val[] = {25, 14, 15};
    int wt[] = {18, 15, 10};
    int W = 20;
    int n = sizeof(val) / sizeof(val[0]); // no. of elements in the array

    printf("The maximum value that can be put in a knapsack of capacity %d is: %d\n", W, knapSack(W, wt, val, n));

    return 0;
}
