#include <bits/stdc++.h>
using namespace std;

template <typename alu> // "typename" and "class" both are same
// template <class alu>
int linear_search(alu arr[], int size, alu num)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == num)
        {
            return i;
        }
    }
    return size;
}

int main()
{
    int arr[] = {12, 5, 8, 24, 7, 2, 67, 9};
    int size = sizeof(arr) / sizeof(int);
    int num = 24;

    char n[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    size = sizeof(n) / sizeof(char);
    char key = 'd';

    int ans = linear_search(n, size, key); // This function will work for both int ,char and any data type
    cout << "Index of the given number is: " << ans << endl;
    return 0;
}
