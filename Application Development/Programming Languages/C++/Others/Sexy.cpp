#include <iostream>
#include <conio.h>
using namespace std;
int main(void)
{
	int n, a = 0, choice, i, j, o, q = 0, h = 0;
	long p;
	cout << "\n		     	    ! WELCOME !\n\n     	    -:You Have Entered A Number Checking Zone:-\n";
	cout << "\nThis Programm Has Eight Features (Given Below) To Check Your Number: \n\n1.Prime Number or not\n2.Perfect Number or not\n3.Palindrome Number or not\n4.Armstrong Number or not\n5.Strong Number or not\n6.Buzz Number or not\n7.Even Number or Odd Number\n8.Positive Number or Negative Number\n";
	do
	{
		cout << "\nTo Proceed, Please Enter Your Number: ";
		cin >> n;
		system("CLS");
		cout << "************** MENU **************\n\n";
		cout << "Press 0 To Check Prime Number or not\nPress 1 To Check Perfect Number or not\nPress 2 To Check Palindrome Number or not\nPress 3 To Check Armstrong Number or not\nPress 4 To Check Strong Number or not\nPress 5 To Check Buzz number or not\nPress 6 To Check Even Number or Odd number\nPress 7 To Check Positive Number or Negative Number";
		do
		{
			cout << "\n\n\n\nTo Check '" << n << "' Please Enter Your Appropriate Choice Seeing The Above Menu:-\n(If You Enter A Negative Number, The Process will End !)\n................................................\n\nNow, Type Your Choice And Press 'Enter' :  ";
			cin >> choice;
			system("CLS");
			if (choice > 7)
			{
				cout << "You Are Very Naughty! You are Told To Enter Appropriate Choice!\nBut Still You Have Entered Wrong Choice!";
				cout << "\n................................................\n";
				cout << "\n\n************** MENU **************\n\n";
				cout << "Press 0 To Check Prime Number or not\nPress 1 To Check Perfect Number or not\nPress 2 To Check Palindrome Number or not\nPress 3 To Check Armstrong Number or not\nPress 4 To Check Strong Number or not\nPress 5 To Check Buzz number or not\nPress 6 To Check Even Number or Odd number\nPress 7 To Check Positive Number or Negative Number";
			}
			if (choice >= 0 && choice < 8)
			{
				switch (choice)
				{
				case 0:
					cout << "\nThose numbers which are only divisible by 1 and itself, those numbers are called Prime numbers.\nExample: 1,2,3,5,7,11..........etc.\n";
					if (n != 1 || n != 2)
						for (i = 2; i < n; i++)
						{
							if (n % i == 0)
							{
								a = 1;
								break;
							}
						}
					if (a == 1)
						cout << "\nSorry! The Given Number " << n << " Is Not Prime !";
					else
						cout << "\nWelldone! The Given Number " << n << " Is Prime !";
					break;
				case 1:
					cout << "\nAny number can be the perfect number, if the sum of its positive divisors excluding the\n1, 2, 3, and 6. So, the sum of these values is 1+2+3 = 6 (Remember, we have to exclude the number itself).\n";
					for (i = 1; i <= (n - 1); i++)
					{
						p = n % i;
						if (p == 0)
						{
							q = q + i;
						}
					}
					if (q == n)
						cout << "\nWow! Entered Number " << n << " Is A Perfect Number.";
					else
						cout << "\nSorry! Entered Number " << n << " Is Not A Perfect Number.";
					break;
				case 2:
					cout << "\nA Palindrome number is one that remains the same on reversal. Some examples are\n 8, 121, 212, 12321, -454. To check if a number is a palindrome or not, we reverse it and compare\nit with the original number, if both are the same, it's a palindrome otherwise not.\n";
					o = n;
					// reversed integer is stored in reversedN
					while (o != 0)
					{
						p = o % 10;
						q = q * 10 + p;
						o /= 10;
					}
					// palindrome if orignalN and reversedN are equal
					if (n == q)
						cout << "\nWow! " << n << " Is A Palindrome Number.";
					else
						cout << "\nSorry! " << n << " Is Not A Palindrome Number.";
					break;
				case 3:
					cout << "\nArmstrong number is a number that is equal to the sum of cubes of its digits. For example:\n0, 1, 153, 370, 371 and 407 are the Armstrong numbers.\n";
					o = n;
					while (o != 0)
					{
						p = o % 10;
						q += p * p * p;
						o /= 10;
					}

					if (q == n)
						cout << "\nWow! " << n << " is an Armstrong Number.";
					else
						cout << "\nSorry! " << n << " is not an Armstrong Number.";
					break;
				case 4:
					cout << "\nA number is called strong number if sum of the factorial of its digit is equal to number itself.\nExample: 145 since 1! + 4! + 5!Jan 11, 2012\n";
					o = n;
					while (o > 0)
					{
						/* Get last digit of num */
						j = o % 10;
						/* Find factorial of last digit */
						p = 1;
						for (i = 1; i <= j; i++)
						{
							p = p * i;
						}
						/* Add factorial to sum */
						q = q + p;
						o = o / 10;
					}
					/* Check Strong number condition */
					if (q == n)
					{
						cout << "\nWow! " << n << " Is A Strong Number.";
					}
					else
					{
						cout << "\nSorry! " << n << " Is Not A Strong Number.";
					}
					break;
				case 5:
					cout << "\nA number is said to be Buzz Number if it ends with 7 OR is divisible by 7. The task is to \ncheck whether the given number is buzz number or not. Examples: Input : 63 Output : Buzz Number\nExplanation: 63 is divisible by 7, one of the condition is satisfied.\n";
					if (n % 7 == 0 || n % 10 == 7)
						cout << "\nWow! Your Enterd Number " << n << " Is A Buzz Number.";
					else
						cout << "\nSorry! Your Entered Number " << n << " Is Not A Buzz Number.";
					break;
				case 6:
					cout << "\nIf a number is divisible by 2 then it is called a even number otherwise\nit is a odd number. Example: 2,4,6............etc.\n";
					if (n % 2 == 0)
						cout << "\nWow! Your Entered Number " << n << " Is Even.";
					else
						cout << "\nSorry! Your Entered Number " << n << " Is Odd.";
					break;
				case 7:
					cout << "\nIf a number is greater than 0 then it is said to be positive otherwise it is said to be negative.\nExample: 1,2,2......... are positive but -1,-2,-3.......are negative.\n";
					if (n == 0)
					{
						cout << "\nYou Are Fool!\n'0' Is Neither Positive Nor Negative !";
					}
					while (n != 0)
					{
						if (n > 0)
							cout << "\nWow! Your Entered Number " << n << " Is Positive.";
						else
							cout << "\nSorry! Your Entered Number " << n << " Is negative.";
						break;
					}
					break;
				}
			}
		} while (choice > 7);
		cout << "\n\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		cout << "\nIf You Want To Check Another Number, Then Enter '1'\n(If You Are Not Interested, You Can Enter Any Number To Exit)\nYour Decision: ";
		cin >> h;
		system("CLS");
	} while (h < 2);
	if (h > 1)
		cout << "\n_______________________________\n\n	! Thank You !\n\n    Press 'Enter' To Exit\n\n	  Bye Bye !";
	getch();
}
