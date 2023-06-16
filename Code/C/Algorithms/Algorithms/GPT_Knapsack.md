Sure, I'd be happy to explain the code step by step:

1. The first line `#include<stdio.h>` is a preprocessor directive that includes the standard input-output header file in the program.

2. The `max()` function is defined to find the maximum of two integers. It takes two integer arguments and returns the greater value.

3. The `knapsack()` function takes four arguments - `W`, `wt[]`, `val[]`, and `n`. Here, `W` represents the maximum weight that the knapsack can carry, `val[]` represents the values of the items, `wt[]` represents their weights, and `n` represents the number of items.

4. Inside the `knapsack()` function, an array `K[][]` of size `(n+1)x(W+1)` is declared to store the maximum possible value that can be obtained for each combination of items and weights.

5. Next, a double nested loop is used to fill the table `K[][]` in a bottom-up manner. The outer loop iterates over all the items from `i = 0` to `i = n`, while the inner loop iterates over all possible weights from `j = 0` to `j = W`.

6. For the base case when either there are no items (i.e., `i=0`) or the knapsack has no capacity (i.e., `j=0`), the maximum value that can be obtained is always zero.

7. For the remaining cases, if the weight of the current item `i-1` is less than or equal to the current weight `j`, then we have two choices: either include the item in the knapsack and add its value to the total value, or exclude it and keep the previous maximum value. We choose the option that gives us the maximum value.

8. If the weight of the current item `i-1` is greater than the current weight `j`, then we cannot include the item and the previous maximum value is kept.

9. Once all combinations have been checked, the maximum possible value that can be obtained from the given set of items and the given knapsack capacity is stored in `K[n][W]`.

10. Finally, the `knapsack()` function returns the maximum possible value.

11. In the `main()` function, an example input is provided to test the `knapsack()` function. The `val[]` array stores the values of three items, the `wt[]` array stores their weights, the maximum capacity of the knapsack `W` is set to 50, and the number of items `n` is calculated using the `sizeof()` operator. The `knapsack()` function is called with these arguments and the maximum value that can be obtained is printed using the `printf()` function.

I hope this explanation helps! Let me know if you have any further questions.