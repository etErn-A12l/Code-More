#include <iostream>
using namespace std;

int fib(int m)
{
   if ((m == 1) || (m == 0))
   {
      return (m);
   }
   else
   {
      return (fib(m - 1) + fib(m - 2));
   }
}

int main()
{
   int x, i = 0;
   cout << "Enter the number of terms of series : ";
   cin >> x;
   cout << "\nFibonnaci Series : ";
   while (i < x)
   {
      cout << " " << fib(i);
      i++;
   }
   return 0;
}