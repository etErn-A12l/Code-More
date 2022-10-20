#include<stdio.h>
#include<conio.h>
int main()
{
	char grade;
    printf("Enter the grade: ");
	scanf("%c",&grade);
	if(grade=='A')
	{
		printf("Excellent !");
	}
	else if(grade=='B')
	{
		printf("Well done !");
	}
	else if(grade=='D')
	{
		printf("You are Passed");
	}
	else if(grade=='F')
	{
		printf("Better, try again later");
	}
	else
	{
		printf("You are failed");
	}
	return 0;
}
