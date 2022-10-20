#include<stdio.h>
int main()
{
	int n,i,s;
	printf("Enter the last Number: ");
	scanf("%d",&n);
	for(i=1;i<=n;)
	{
		s=s+i;
		i=i+2;
	}
	printf("\n Your total sum is %d",s);
	return 0;
}
