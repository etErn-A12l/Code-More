//Enter a number and check it if it is a palindrome
#include<iostream>
using namespace std;
main()
{
    int number,orinum,a,b=0;
    cout<<"Enter any number: ";
    cin>>number;
    orinum=number;
    while(number>0)
    {
        a=number%10;
        b=b*10+a;
        number/=10;
    }
    if(b==orinum)
    cout<<"The number you have entered is a palindrome number";
    else
    cout<<"The number you have entered is not a palindrome number";
}