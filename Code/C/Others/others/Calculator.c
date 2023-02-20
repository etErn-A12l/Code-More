#include<stdio.h>
int main()
{
	int a,b,s=0,i;
	printf("Enter the first number: ");
	scanf("%d",&a);
	printf("Enter the second number: ");
	scanf("%d",&b);
	printf("........MENU........\n 1 for ADDITION\n 2 for SUBSTRACTION\n 3 for MULTIPLICATION\n 4 for DIVITION\n \n Please enter your choise: ");
	scanf("%d",&i);
	if(i==1)
	s=a+b;
	else if(i==2)
	s=a-b;
	else if(i==3)
	s=a*b;
	else if(i==4)
	s=a/b;
	else
		printf("Invalid Selection\n");
	printf("The result is %d",s);
}
