#include <iostream>
using namespace std;

int factorial(int n)
{
   int fact = 1;
   while (n != 0)
   {
      fact = fact * n;
      n--;
   }
   return fact;
}

void isKrishnamurthy(int n)
{
   int sum = 0;
   int temp = n;
   while (temp != 0)
   {
      sum += factorial(temp % 10);
      temp = temp / 10;
   }
   if (sum == n)
      cout << "Yes. Input no is a Krishnamurthy";
   else
      cout << "No. Input no is not a Krishnamurthy";
}

int main()
{
   int n;
   cout << "\n Input any no : ";
   cin >> n;
   isKrishnamurthy(n);
   return 0;
}
