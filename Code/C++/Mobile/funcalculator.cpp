#include<iostream>
using namespace std;

char decision();
void add();
void sub();
void mul();
void div();
void power();
void fact();

int main()
{
    char choice,will;
    cout<<"\n\n###You have entered a calculator###\n\n";
    choice=decision();
    if(choice=='a')
    add();
    else if(choice=='s')
    sub();
    else if(choice=='m')
    mul();
    else if(choice=='d')
    div();
    else if(choice=='p')
    power();
    else if(choice=='f')
    fact();
    else{
    system("CLS");
    cout<<"\n****You have entered wrong choice****\n";
    main();}
	cout<<"\n If you want to calculate something more, then press 'y' otherwise 'n': ";
	cin>>will;
	if(will=='y')
	{
		main();
	}
    return 0; 
}

char decision()
{
    char choice;
    cout<<"\nTo add two numbers, enter 'a': ";
    cout<<"\nTo subtract two numbers, enter 's': ";
    cout<<"\nTo multiply two numbers, enter 'm': ";
    cout<<"\nTo divide two numbers, enter 'd': ";
    cout<<"\nTo get power of a number, enter 'p': ";
    cout<<"\nTo get factorial, enter 'f': \n\n\n";
    cout<<"Your choice: ";
    cin>>choice;
    return choice;
}

void add()
{
    float num1,num2;
    cout<<"\nEnter first number: ";
    cin>>num1;
    cout<<"\nEnter second number: ";
    cin>>num2;
    cout<<"\nResult is: "<<num1+num2;
}

void sub()
{
	float num1,num2;
	cout<<"\nSecond number will be substracted from the first number\n";
	cout<<"\nEnter first number: ";
	cin>>num1;
	cout<<"\nEnter second number: ";
	cin>>num2;
	cout<<"\nResult="<<num1-num2;
}

void mul()
{
	float num1,num2;
	cout<<"\nEnter first number: ";
	cin>>num1;
	cout<<"\nEnter second number: ";
	cin>>num2;
	cout<<"\nResult="<<num1*num2;
}

void div()
{
	float num1,num2;
	cout<<"\nFirst number will be divided by the second number\n";
	cout<<"\nEnter the first number: ";
	cin>>num1;
	cout<<"\nEnter the second number: ";
	cin>>num2;
	cout<<"\nResult="<<num1/num2;
}

void power()
{
	float num; int power;
	cout<<"\nEnter the number: ";
	cin>>num;
	cout<<"\nEnter the power: ";
	cin>>power;
	for(int i=1;i<power;i++)
	{
		num*=num;
	}
	cout<<"\nResult ="<<num;
}

void fact()
{
	long int num;
	cout<<"\nEnter an integer: ";
	cin>>num;
	for(int i=num;i>=1;i--)
	{
		num*=i;
	}
	cout<<"\nResult="<<num;
}
