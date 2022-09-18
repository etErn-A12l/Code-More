#include <bits/stdc++.h>
using namespace std;

const int MAX = 7;

int Lower_Bound(int arr[], int key)
{
    int ans = -1;
    int low = 0, high = (MAX - 1);

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
        {
            ans = mid;
            high = mid - 1;
        }
        else if (arr[mid] > key)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int Upper_Bound(int arr[], int key)
{
    int ans = -1;
    int low = 0, high = (MAX - 1);

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
        {
            ans = mid;
            low = mid + 1;
        }
        else if (arr[mid] > key)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    int key, arr[MAX] = {10, 12, 12, 12, 56, 56, 77};

    cout << "Enter the number you wanna found: ";
    cin >> key;

    int Low_Bound = Lower_Bound(arr, key);
    int Up_Bound = Upper_Bound(arr, key);

    cout << "The Lowest index of " << key << " is " << Low_Bound << endl;
    cout << "The Highest index of " << key << " is " << Up_Bound << endl;

    return 0;
}
