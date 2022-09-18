#include<stdio.h>
#include<conio.h>
int main()
{
	int X[10],i,m,n=0;
	printf("Enter Ten Value of Array: \n");
	for(i=0;i<10;i++)
	{
		scanf("%d",&X[i]);
	}
	printf("Enter The Value Which You Want to Find: ");
	scanf("%d",&m);
	for(i=0;i<10;i++)
	{
		if(m==X[i])
		{
			n=1;
		}
		else
		{
			continue;
		}
	}	
	if(n==1)
	{
		printf("Yes! The number has entered!");
	}
	else
	{
		printf("Sorry! The number has not entered!");
	}
	getch();
}
