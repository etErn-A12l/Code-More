#include<iostream>
using namespace std;
main()
{
    int number,rem,sum=0,i;
    cout<<"Enter a Number\n";
    cin>>number;
    for(i=1;i<number;i++)
    {
        rem=number%i;
	if(rem==0)
        {
            sum=sum+i;
        }
    }
    if(sum==number)
        cout<<"\nWow! Entered Number "<<number<<" Is A Perfect Number.";
    else
        cout<<"\nSorry! Entered Number "<<number<<" Is Not A Perfect Number.";
    return 0;
}