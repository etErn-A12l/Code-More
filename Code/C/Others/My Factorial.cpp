#include<stdio.h>
int main()
{
	long int s=1,n,i;
	printf("Enter The Number: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		s=s*i;
	}
	printf("This is Your Factorial: %d",s);
}
