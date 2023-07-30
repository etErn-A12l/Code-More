//Enter a number to check prime number or not
#include <iostream>
using namespace std;
int main()
{
    int n, check;
    cout << "Enter a number: ";
    cin >> n;
    if (n > 2)
    {
        for (int i = 2; i < n; i++)
        {
            check = n % i;
            if (check == 0)
                break;
        }
    }
    if (check == 0)
        cout << "Your entered number " << n << " is not a prime number !";
    else
        cout << "Your entered number " << n << " is a prime number !";
    return 0;
}