#include<stdio.h>
int main()
{
	int a,b,temp;
	printf("\n Enter any two numbers: ");
	scanf("%d%d",&a,&b);
	while(b!=0)
	{
		temp=(a%b);
		a=b;
		b=temp;
	}
	printf("\n Your GCD is %d",a);
	return 0;
}
