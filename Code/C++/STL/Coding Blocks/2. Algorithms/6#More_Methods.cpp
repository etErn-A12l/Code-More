#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    int a = 10, b = 20;

    swap(a, b); // swaps to values
    cout << "a = " << a << ", b = " << b << endl;

    cout << max(a, b) << endl; // prints maximum value b/w two no.
    cout << min(a, b) << endl; // prints minimum value b/w two no.

    int arr[] = {12, 13, 14, 15, 16, 17, 18};
    int size = sizeof(arr) / sizeof(int);

    reverse(arr, arr + 3);    //reverses a part of the array
    reverse(arr, arr + size); //reverses the whole array

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    next_permutation(arr, arr + size); //returns next pemutation number

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
