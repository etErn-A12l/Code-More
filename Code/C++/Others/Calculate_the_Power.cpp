//Calculate the power of a entered number without using pow function
#include<iostream>
using namespace std;
main()
{
    int power,i;
    float number,result=1;
    cout<<"Enter the number: ";
    cin>>number;
    cout<<"Enter the power: ";
    cin>>power;
    for(i=1;i<=power;i++)
    {
        result*=number;
    }
    cout<<"Your result is "<<result;
}