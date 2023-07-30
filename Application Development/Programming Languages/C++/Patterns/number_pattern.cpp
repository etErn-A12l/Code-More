#include <iostream>
using namespace std;

int main()
{
    int n, x, y;
    cout << "Enter the number of rows to show number pattern: ";
    cin >> n;
    for (x = 1; x <= n; x++)
    {
        for (y = 1; y <= n; y++)
        {
            if (y <= x)
                cout << y;
            else
                cout << " ";
        }
        for (y = n; y >= 1; y--)
        {
            if (y <= x)
                cout << y;
            else
                cout << " ";
        }
        cout << "\n";
    }
    return 0;
}

// Output :

// Enter the number of rows to show number pattern: 8
// 1              1
// 12            21
// 123          321
// 1234        4321
// 12345      54321
// 123456    654321
// 1234567  7654321
// 1234567887654321