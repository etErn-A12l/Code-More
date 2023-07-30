#include <iostream>
using namespace std;

bool compare(int a, int b)
{
    return a < b; // always returns true according to the condition
}

void bubble_sort(int a[], int n, bool (&cmp)(int a, int b)) // Accepting another function as a parameter
{
    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 0; j <= n - i - 1; j++)
        {
            if (cmp(a[j], a[j + 1])) // Using another function instead of ">"
            {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int a[10] = {12, 54, 89, 62, 5, 78, 24, 88, 43, 76};

    bubble_sort(a, 10, compare); // Passing another function as a parameter

    cout << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << "The " << i + 1 << "th value of the array is: " << a[i] << endl;
    }

    return 0;
}
