#include <bits/stdc++.h>
using namespace std;

void take_input(int arr[][5])
{
    int size;
    cout << "Enter the length and height of the qube: ";
    cin >> size;
}

int main(int argc, char const *argv[])
{
    int height, length;
    int arr[height][length];

    cout << "Enter the height of the array: ";
    cin >> height;
    cout<<"Enter the lenght of the array: ";
    cin>>length;

    take_input(arr[height][length]);
    
    return 0;
}
