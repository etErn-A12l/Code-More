#include <bits/stdc++.h>
using namespace std;

int main()
{
    system("CLS");
    long int bn;
    int dn, bb;
    int i;
    cout << "Enter any Binary Number: ";
    cin >> bn;
    dn = 0;
    i = 0;
    while (bn > 0)
    {
        bb = bn % 10;
        dn = dn + bb * pow(2, i);
        bn /= 10;
        i++;
    }
    cout << "\nThe equivalent decimal number: " << dn << endl;
    return 0;
}