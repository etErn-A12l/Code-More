#include <iostream>
using namespace std;

int main()
{
    int number, rem, sum = 0; 
    cout << "Please enter a number: ";
    cin >> number; 
    
    for (int i = 1; i < number; i++) 
    {
        rem = number % i; 
        if (rem == 0) 
        {
            sum += i;
        }
    }
    
    string output = (sum == number)? 
        "Wow! Entered Number " + to_string(number) + " Is A Perfect Number." : 
        "Sorry! Entered Number " + to_string(number) + " Is Not A Perfect Number.";
    cout << output << endl;
    return 0;
}
