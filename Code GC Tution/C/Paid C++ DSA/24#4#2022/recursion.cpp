#include <iostream>
using namespace std;

int add(int num)
{
    if(num>0)
    {
        return (num + add(num-1));
    }
    else
    {
        return 0;
    }
}

int main()
{
    int a = 10;
    int result = add(a);
    cout << result;
    return 0;
}
