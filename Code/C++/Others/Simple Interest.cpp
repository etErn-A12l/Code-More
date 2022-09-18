#include<iostream>
using namespace std;
main()
{
    int i,p,r,t,s;
    cout<<"Enter Principle: ";
    cin>>p;
    cout<<"Enter Rate: ";
    cin>>r;
    cout<<"Enter Time: ";
    cin>>t;
    i=p*r*t/100;
    cout<<"Interest will be "<<i;
    s=i+p;
    cout<<"\nNow the final principle is "<<s;
}
