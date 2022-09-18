#include<bits/stdc++.h>
using namespace std;

int main()
{
    float a,b,c,r1,r2,check;
    cout<<"Enter the values of a,b,c: ";
    cin>>a>>b>>c;
    cout<<endl;
    check=b*b-(4*a*c);
    if(check>0)
    {
        r1=(-b+sqrt(check))/(2*a);
        r1=(-b-sqrt(check))/(2*a);
        cout<<"The roots are "<<r1<<" and "<<r2<<endl<<"The roots are real and unequal";
    }
    else if(check==0)
    {
        r1=-b/(2*a);
        r2=-b/(2*a);
        cout<<"The roots are "<<r1<<" and "<<r2<<endl<<"The roots are real and equal";
    }
    else
    {
        cout<<"Roots are imaginary and complex"<<endl;
    }
    return 0;
}