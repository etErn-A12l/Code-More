#include <iostream>
// #include<conio.h>
using namespace std;

int main(void)
{
    int year, choice = 0;
    do
    {
        cout << "\nEnter the year: ";
        cin >> year;
        if (year % 4 != 0)
        {
            cout << "\nThe year " << year << " is not leap year\n\n.";
        }
        else
        {
            cout << "\nThe year " << year << " is leap year.\n\n";
        }
        cout << "....................................\n";
        cout << "If you want to check another year, enter '1': ";
        cin >> choice;
        system("CLS");
    } while (choice < 2);
    if (choice > 1)
    {
        cout << "\nYou are going to exit !";
    }
    // getch();
}
