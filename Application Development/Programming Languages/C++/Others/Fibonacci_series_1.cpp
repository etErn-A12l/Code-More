//Print Fibonacci series

//This code will print your desired number of numbers in the series

#include <iostream>
using namespace std;

int main()
{
    long int n, t1 = 0, t2 = 1, nextTerm = 0, i;
    cout << "Enter the number of terms: ";
    cin >> n;
    cout << "Fibonacci Series: ";
    for (i = 1; i <= n; ++i)
    {
        if (i == 1)
        {
            cout << " " << t1;
            continue;
        }
        if (i == 2)
        {
            cout << " " << t2;
            continue;
        }
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
        cout << " " << nextTerm;
    }
    return 0;
}