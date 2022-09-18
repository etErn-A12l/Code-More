#include <iostream>
using namespace std;

int main()
{
    int row = 7, k;

    for (int i = 1; i <= (row / 2); ++i, k = 0)
    {
        for (int space = 1; space <= (row / 2) - i + 1; ++space)
        {
            cout << "  ";
        }
        while (k != 2 * i - 1)
        {
            cout << "* ";
            ++k;
        }
        cout << endl;
    }
    for (int i = 0; i < row; i++)
    {
        cout << "* ";
    }
    cout << endl;
    for (int i = row / 2; i >= 1; --i, k = 0)
    {
        for (int space = 1; space <= (row / 2) - i + 1; ++space)
        {
            cout << "  ";
        }
        while (k != 2 * i - 1)
        {
            cout << "* ";
            k++;
        }
        cout << endl;
    }

    return 0;
}

/*

        *
      * * *
    * * * * *
  * * * * * * *
    * * * * *
      * * *
        *

*/
