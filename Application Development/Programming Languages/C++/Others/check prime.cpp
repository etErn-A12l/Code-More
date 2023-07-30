//Enter a number to check the number if it is a prime number
#include<iostream>
using namespace std;
main()
{
    int number,i,b=0;
    cout<<"Enter any number to check: ";
    cin>>number;
    if(number!=1||number!=2)
    for(i=2;i<number;i++)
    {
        {
            if(number%i==0)
            {
                b=1;
                break;
            }
        }
    }
    if(b==0)
    cout<<"Your entered number "<<number<<" is prime.";
    else
    cout<<"Your entered number "<<number<<" is not prime.";
}