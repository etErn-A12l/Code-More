#include <iostream>
using namespace std;

void selection_sort(int arr[], int size)
{
    for (int counter = 0; counter < size; counter++)
    {
        int min = counter;
        for (int i = counter + 1; i < size; i++)
        {
            if (arr[min] > arr[i])
            {
                min = i;
            }
        }
        int temp = arr[counter];
        arr[counter] = arr[min];
        arr[min] = temp;
    }
}

void show(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "The " << i + 1 << "th value of the array is: " << arr[i] << endl;
    }
}

int main(int argc, char const *argv[])
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    int arr[size];

    for (int i = 0; i < size; i++)
    {
        cout << "Enter " << i + 1 << "th element for the array: ";
        cin >> arr[i];
    }

    show(arr, size);
    selection_sort(arr, size);
    show(arr, size);

    return 0;
}
