#include<stdio.h>
#include<conio.h>
int main()
{
	int x[10],i;
	int s=0;
	printf("Enter 10 elements for Array: ");
	for(i=0;i<10;i++)
	{
		scanf("%d",&x[i]);
	}
	for(i=0;i<10;i++)
	{
		if (x[i]%2==0)
		s=s+x[i];
		else
		continue;
	}
	printf("The sum of even numbers are %d",s);
	return 0;
}
