#include <iostream>
using namespace std;


#define ILU(x) #x

void dec2bin(int num);

int main()
{
    cout << ILU(Hello Programmer Good Morning 2 u) << endl;

    int a = 20, b = 45;
    dec2bin(a);
    cout << endl;
    // dec2bin(b);
    a = a >> 2;
    dec2bin(a);
    
    return 0;
}

void dec2bin(int num)
{
    int arr[50];
    int i = 0;
    while (num > 0)
    {
        arr[i] = num % 2;
        num /= 2;
        i++;
    }
    i--;
    while (i >= 0)
    {
        cout << arr[i] << " ";
        i--;
    }
}
