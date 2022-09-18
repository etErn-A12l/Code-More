//program to print multiples

#include<iostream>
using namespace std;

int main()
{
    int n,a,c;
    cout<<"Enter number: ";
    cin>>n;
    a=1;
    ab:
    c=0;
    c=n*a;
    cout<<c<<endl;
    a++;
    if(a<=10)
    goto ab;
    else 
    return 0;
}