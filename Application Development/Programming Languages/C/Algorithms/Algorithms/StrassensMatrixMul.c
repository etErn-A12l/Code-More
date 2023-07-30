// Time complexity for this solution is O(n^2.8)

#include <stdio.h>
#define MAX 2

int a[MAX][MAX], b[MAX][MAX], c[MAX][MAX];

void Display(int a[MAX][MAX], char c)
{
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            printf("%c[%d][%d]: %d\t", c, i, j, a[i][j]);
        }
        printf("\n");
    }
}

void Input(int arr[MAX][MAX], char c)
{
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            printf("\tEnter Element %c[%d][%d]: ", c, i, j);
            scanf("%d", &arr[i][j]);
        }
    }
}

void StrassensMul(int a[MAX][MAX], int b[MAX][MAX], int c[MAX][MAX])
{
    int m1 = (a[0][0] + a[1][1]) * (b[0][0] + b[1][1]);
    int m2 = (a[1][0] + a[1][1]) * b[0][0];
    int m3 = a[0][0] * (b[0][1] - b[1][1]);
    int m4 = a[1][1] * (b[1][0] - b[0][0]);
    int m5 = (a[0][0] + a[0][1]) * b[1][1];
    int m6 = (a[1][0] - a[0][0]) * (b[0][0] + b[0][1]);
    int m7 = (a[0][1] - a[1][1]) * (b[1][0] + b[1][1]);

    c[0][0] = m1 + m4 - m5 + m7;
    c[0][1] = m3 + m5;
    c[1][0] = m2 + m4;
    c[1][1] = m1 - m2 + m3 + m6;
}

int main()
{
    printf("\nEnter Elements for first matrix: \n\n");
    Input(a, 'a');
    printf("\nEnter Elements for Second matrix: \n\n");
    Input(b, 'b');
    printf("\n\nElements of First matrix: \n\n");
    Display(a, 'a');
    printf("\n\nElements of Second matrix: \n\n");
    Display(b, 'b');

    StrassensMul(a, b, c);

    printf("\n\nElements of Resultant matrix: \n\n");
    Display(c, 'c');

    return 0;
}

// Doxygen is a documentation generator

// /**
//  * @brief Calculates the sum of two integers.
//  *
//  * This function takes two integer inputs and returns their sum.
//  * 
//  * @param a The first integer to add.
//  * @param b The second integer to add.
//  * @return The sum of a and b.
//  */
// int add(int a, int b) {
//     return a + b;
// }
