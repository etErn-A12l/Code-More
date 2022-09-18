#include <iostream>
#include <algorithm>

using namespace std;

// Define a Comparator To Modisy Sort Function

bool compare(int a, int b)
{
    // cout << "Comparing " << a << " and " << b << endl;
    return a > b;
}

int main(int argc, char const *argv[])
{
    int n, arr[1000];

    cout << "Enter the size of the array: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the " << i + 1 << "th element: ";
        cin >> arr[i];
    }

    cout << endl
         << "Now Sorting the entire array.........." << endl;

    sort(arr, arr + n, compare);

    for (int i = 0; i < n; i++)
    {
        cout << "The " << i + 1 << "th element is: " << arr[i] << endl;
    }

    return 0;
}
