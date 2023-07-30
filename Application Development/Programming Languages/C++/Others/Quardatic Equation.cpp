#include<iostream>
#include<math.h>
using namespace std;
main()
{
    float a,b,c,x1,x2;
    cout<<"Enter the value of a: ";
    cin>>a;
    cout<<"Enter the value of b: ";
    cin>>b;
    cout<<"Enter the value of c: ";
    cin>>c;
    x1=(-b+sqrt(b*b-4*a*c))/2*a;
    x2=(-b-sqrt(b*b-4*a*c))/2*a;
    cout<<"The first root is "<<x1;
    cout<<endl;
    cout<<"The second root is "<<x2;
}