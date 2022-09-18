#include <iostream>
#include <algorithm>
using namespace std;

// To Use this Pre-Built Functions, the array must be Sorted

int main()
{

    int arr[] = {12, 23, 56, 76, 76, 76, 87, 99};
    int key = 76;
    int n = sizeof(arr) / sizeof(int);

    bool check = binary_search(arr, arr + n, key);

    // cout << "Bool = " << check << endl;

    if (check == true)
        cout << "Element is Present !";
    else
        cout << "Element is not present !";

    cout << endl;
    int *low_bound = lower_bound(arr, arr + n, key);
    cout << "The Lower Bound is " << low_bound - arr << endl;

    int *up_bound = upper_bound(arr, arr + n, key);
    cout << "The Upper Bound is " << up_bound - arr << endl;

    cout << "And the frequency is " << up_bound - low_bound << endl;
    return 0;
    
}
