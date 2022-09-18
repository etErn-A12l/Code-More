#include <iostream>
using namespace std;
main()
{
    int number, originalno, a, b = 0;
    cout << "Enter a number to check the number: ";
    cin >> number;
    originalno = number;
    while (number != 0)
    {
        a = number % 10;
        b += a * a * a;
        number /= 10;
    }
    if (b == originalno)
        cout << "Entered no. is an armstrong number.";
    else
        cout << "Entered no. is not an armstrong number.";
    return 0;
}