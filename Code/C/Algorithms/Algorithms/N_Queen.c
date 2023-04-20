#include <stdbool.h>
#include <stdio.h>

// Function prototypes
bool isValidMove(int board[][10], int row, int col, int n);
void solveNQueen(int board[][10], int col, int n, int *solution_count);

int main()
{
    int n;
    printf("Enter the value of N: ");
    scanf("%d", &n);

    int board[10][10] = {0}; // Initialize the chessboard
    int solution_count = 0;

    solveNQueen(board, 0, n, &solution_count);

    if (solution_count > 0)
    {
        printf("\nNumber of %d-Queens solutions found: %d\n", n, solution_count);
    }
    else
    {
        printf("No solution exists for %d-Queens problem.\n", n);
    }

    return 0;
}

bool isValidMove(int board[][10], int row, int col, int n)
{
    // Check for any other queen in the same row on the left side
    for (int i = 0; i < col; i++)
        if (board[row][i])
            return false;

    // Check upper diagonal on the left side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check lower diagonal on the left side
    for (int i = row, j = col; j >= 0 && i < n; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

void solveNQueen(int board[][10], int col, int n, int *solution_count)
{
    // Base case: If all queens are placed
    if (col >= n)
    {
        printf("\n%d-Queens solution #%d:\n\n", n, *solution_count + 1);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                printf("%d ", board[i][j]);
            printf("\n");
        }

        (*solution_count)++;
        return;
    }

    // For each row, place the queen and check if it's a valid position
    for (int i = 0; i < n; i++)
    {
        if (isValidMove(board, i, col, n))
        {
            board[i][col] = 1;

            // Continue to place queens in next column
            solveNQueen(board, col + 1, n, solution_count);

            // Backtrack and remove the placed queen from this row
            board[i][col] = 0;
        }
    }
}
