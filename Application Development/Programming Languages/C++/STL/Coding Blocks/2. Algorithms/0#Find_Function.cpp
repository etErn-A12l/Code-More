#include <iostream>
#include <algorithm>
using namespace std;

int main()
{

    int arr[] = {12, 455, 543, 76, 726};
    int key = 76;
    int n = sizeof(arr) / sizeof(int);

    auto it = find(arr, arr + n, key);
    cout << it << endl;
    int Index = it - arr;
    if (Index == n)
        cout << "Element " << key << " Was not found in the array !";
    else
        cout << "The position of the element " << key << " is " << Index << endl;
    return 0;
}
