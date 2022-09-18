#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(int);

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    rotate(arr, arr + 2, arr + size);

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    vector<int> v{1, 2, 3, 4};

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    // rotate(v.begin(), v.begin() + 2, v.end());

    next_permutation(v.begin(), v.end());

    for (int x : v)
    {
        cout << x << " ";
    }
    cout << endl;

    next_permutation(v.begin(), v.end());

    for (int x : v)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
