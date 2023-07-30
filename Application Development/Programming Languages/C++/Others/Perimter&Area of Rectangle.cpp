#include<iostream>
using namespace std;
main()
{
    int leftside,rightside,perimeter;
    long area;
    cout<<"Enter the left side of the rectangle: ";
    cin>>leftside;
    cout<<"Enter the right side of the rectangle: ";
    cin>>rightside;
    perimeter=2*(leftside+rightside);
    area=leftside*rightside;
    cout<<"The perimeter of the rectangle is "<<perimeter;
    cout<<endl;
    cout<<"The area of the rectangle is "<<area;
} 

