#include<iostream>
#include<conio.h>
using namespace std;
main()
{
    int n,i;
    double result=1;
    cout<<"Enter the number to get the factorial: ";
    cin>>n;
    for(i=1;i<=n;i++)
    {
        result=result*i;
    }
    cout<<"Your result is "<<result;
    getch();
}