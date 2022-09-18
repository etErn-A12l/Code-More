#include <iostream>
using namespace std;

int sum_of_n_numbers(int n)
{
    int sum = 0;
    for (int i = 0; i <= n; i++)
    {
        sum += i;
    }
    return sum;
}

int main(int argc, char const *argv[])
{
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    int result = sum_of_n_numbers(n);
    cout << "Result is: " << result;
    return 0;
}
