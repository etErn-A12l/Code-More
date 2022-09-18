#include <iostream>
using namespace std;

int main()
{
    int size = 2, a[size][size][size], n;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            for (int k = 0; k < size; k++)
            {
                cout << "Enter " << i << "th" << j << "th" << k << "th"
                     << " elements: ";
                cin >> n;
                a[i][j][k] = n;
            }
        }
    }
    for (int i = 0; i < size; i++)
    {
        cout << endl;
        for (int j = 0; j < size; j++)
        {
            cout << endl;
            for (int k = 0; k < size; k++)
                cout << " " << a[i][j][k];
        }
    }
    return 0;
}