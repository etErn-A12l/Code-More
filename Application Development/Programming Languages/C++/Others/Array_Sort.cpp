#include <bits/stdc++.h>
using namespace std;
int main()
{
    const int n = 8;
    int arr[n] = {25, 56, 8, 23, 78, 32, 6, 89};
    for (int l = 0; l < n; l++)
    {
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                int data = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = data;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
