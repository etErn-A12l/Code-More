#include <iostream>
#include <algorithm>

using namespace std;

bool compare(int a, int b)
{
    return a <= b;
}

int main()
{
    int change[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
    int size = sizeof(change) / sizeof(int);
    int amount;
    cout << "Enter the amount: ";
    cin >> amount;

    while (amount > 0)
    {
        int lb = lower_bound(change, change + size, amount, compare) - change - 1;
        int m = change[lb];
        cout << m << " ,";
        amount = amount -m;
    }

    return 0;
}
