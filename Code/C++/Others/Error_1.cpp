#include <bits/stdc++.h>
using namespace std;
class Student
{
private:
    long Roll;
    char Name[40];
    float Marks;

public:
    void Display();
    void GetData();
};
void Student ::GetData()
{
    cout << "Enter Roll: ";
    cin >> Roll;
    cout << "Enter Name: ";
    cin >> Name;
    cout << "Enter Marks: ";
    cin >> Marks;
}
void Student::Display()
{
    cout << endl
         << "Roll is: " << Roll;
    cout << endl
         << "Name is: " << Name;
    cout << endl
         << "Marks is: " << Marks;
    if (Marks < 0)
        cout << "\n Invalid Marks !";
}
int main()
{
    Student s;
    s.GetData();
    s.Display();
    return 0;
}