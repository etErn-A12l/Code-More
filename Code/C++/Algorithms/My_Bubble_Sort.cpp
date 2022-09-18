#include <iostream>
using namespace std;

const int MAX = 7;

void display(int arr[])
{
    int size = MAX;
    // int size = sizeof(arr) / sizeof(int);

    for (int i = 0; i < size; i++)
    {
        cout << "The " << (i + 1) << "th element of the array is " << arr[i] << endl;
    }
}

void bubble_sort(int arr[])
{
    int size = MAX;

    // int size = sizeof(arr) / sizeof(int);

    for (int counter = 0; counter < size - 1; counter++)
    {
        for (int i = 0; i < size - 1 - counter; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
    }
    cout << endl
         << "Array Sorted successfully ! ! !" << endl;
}

int main()
{
    int arr[MAX] = {122, 856, 354, 758, 378, 543, 999};

    display(arr);
    bubble_sort(arr);
    display(arr);

    return 0;
}
