#include <iostream>
using namespace std;

int main()
{
    int first = 0, second = 1, sum = 0, n;
    cout << "Enter the number of terms: ";
    cin >> n;
    cout << first << " ";
    cout << second << " ";
    for (int i = 1; i <= n; i++) // n = 10
    {
        // cout << first << " ";
        // cout << second << " ";
        sum = first + second;
        cout << sum << " ";
        first = second;
        second = sum;
    }
    return 0;
}