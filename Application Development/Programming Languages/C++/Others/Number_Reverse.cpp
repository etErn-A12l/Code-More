#include <bits/stdc++.h>

using namespace std;

int main()
{
    long int degit;
    long int rev = 0;
    int remainder = 0;
    cin >> degit;
    while (degit > 0)
    {
        remainder = degit % 10;
        rev = (rev * 10) + remainder;
        degit = degit / 10;
    }
    cout << rev << " ";
    return 0;
}
