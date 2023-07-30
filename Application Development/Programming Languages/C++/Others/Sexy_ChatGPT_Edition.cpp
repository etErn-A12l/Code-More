#include <iostream>
#include <cmath>

using namespace std;

bool is_prime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

bool is_perfect(int n)
{
    int sum = 0;
    for (int i = 1; i < n; i++)
    {
        if (n % i == 0)
            sum += i;
    }
    return sum == n;
}

bool is_palindrome(int n)
{
    int original = n;
    int reverse = 0;
    while (n)
    {
        reverse = reverse * 10 + n % 10;
        n /= 10;
    }
    return original == reverse;
}

bool is_armstrong(int n)
{
    int original = n;
    int sum = 0;
    int digits = log10(n) + 1;
    while (n)
    {
        sum += pow(n % 10, digits);
        n /= 10;
    }
    return sum == original;
}

bool is_strong(int n)
{
    int sum = 0;
    int temp = n;
    while (temp)
    {
        int factorial = 1;
        int i = 1;
        int last = temp % 10;
        while (i <= last)
        {
            factorial *= i;
            i++;
        }
        sum += factorial;
        temp /= 10;
    }
    return sum == n;
}

bool is_buzz(int n)
{
    return n % 7 == 0 || n % 10 == 7;
}

bool is_even(int n)
{
    return n % 2 == 0;
}

bool is_positive(int n)
{
    return n > 0;
}

int main()
{
    cout << "Welcome!\n"
         << "This program checks the properties of a number.\n"
         << "Enter a number: ";
    int n;
    cin >> n;

    cout << "\nEnter a choice from the following options:\n"
         << "0. Prime number or not\n"
         << "1. Perfect number or not\n"
         << "2. Palindrome number or not\n"
         << "3. Armstrong number or not\n"
         << "4. Strong number or not\n"
         << "5. Buzz number or not\n"
         << "6. Even number or odd number\n"
         << "7. Positive number or negative number\n"
         << "Choice: ";
    int choice;
    cin >> choice;

    switch (choice)
    {
    case 0:
        cout << "The number is " << (is_prime(n) ? "" : "not ") << "a prime number.\n";
        break;
    case 1:
        cout << "The number is " << (is_perfect(n) ? "" : "not ") << "a perfect number.\n";
        break;
    case 2:
        cout << "The number is " << (is_palindrome(n) ? "" : "not ") << "a palindrome number.\n";
        break;
    case 3:
        cout << "The number is " << (is_armstrong(n) ? "" : "not ") << "an Armstrong number.\n";
        break;
    case 4:
        cout << "The number is " << (is_strong(n) ? "" : "not ") << "a strong number.\n";
        break;
    case 5:
        cout << "The number is " << (is_buzz(n) ? "" : "not ") << "a buzz number.\n";
        break;
    case 6:
        cout << "The number is " << (is_even(n) ? "even" : "odd") << ".\n";
        break;
    case 7:
        cout << "The number is " << (is_positive(n) ? "positive" : "negative") << ".\n";
        break;
    default:
        cout << "Invalid choice!\n";
    }

    return 0;
}
