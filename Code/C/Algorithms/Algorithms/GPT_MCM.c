#include <stdio.h>

int min(int a, int b) { return (a < b) ? a : b; }

int mcm(int p[], int n)
{
    int m[n][n];

    for (int i = 1; i < n; i++)
        m[i][i] = 0;

    for (int L = 2; L < n; L++)
    {
        for (int i = 1; i < n - L + 1; i++)
        {
            int j = i + L - 1;
            m[i][j] = __INT_MAX__;

            for (int k = i; k <= j - 1; k++)
            {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                m[i][j] = min(m[i][j], q);
            }
        }
    }

    return m[1][n - 1];
}

int main()
{
    int arr[] = {2, 10, 50, 40, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Minimum number of multiplications is %d", mcm(arr, size));

    return 0;
}
