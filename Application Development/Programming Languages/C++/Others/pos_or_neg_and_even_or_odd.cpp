//Check a number if it is positive or negative and even or odd
#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int number;
    cout<<"Enter the number to check: ";
    cin>>number;
    if(number%2==0)
    {
        cout<<"Your entered number is even";
    }
    else
    {
        cout<<"Your entered number is odd";
    }
    cout<<endl;
    if(number>0)
    {
        cout<<"Entered number is positive";
    }
    else
    {
        cout<<"And entered number is negative";
    }
    return 0;
}    
    
        