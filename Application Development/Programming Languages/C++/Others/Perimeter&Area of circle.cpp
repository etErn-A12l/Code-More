#include<iostream>
using namespace std;
main()
{
    float radius,perimeter,area;
    cout<<"Enter the radius of the circle: ";
    cin>>radius;
    perimeter=(2*3.1415926535897932384626433832795*radius);
    area=(3.1415926535897932384626433832795*radius*radius);
    cout<<"The perimeter of the circle is "<<perimeter<<" meter";
    cout<<endl;
    cout<<"The area of the circle is "<<area<<" sq.meter";
}