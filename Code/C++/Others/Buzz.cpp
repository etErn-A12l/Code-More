#include <iostream>
using namespace std;

int main()
{
  int n;
  cout << "Please enter a number: ";
  cin >> n;
  
  if (n % 70 == 0)     // Check if divisible by both 7 and 10
    cout << n << " is a buzz number " << endl;
  else
    cout << n << " is not a buzz number " << endl;
    
  return 0;
}
