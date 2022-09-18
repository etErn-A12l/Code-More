#include <stdio.h>
#include <math.h>
int main()
{
	int i,j=1,n;
	double d,c=1,sum=0;
	printf("Enter the last digit: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
	    for(j=1;j<=i;j++)
		{
			c=c*j;
		}
		d=i/c;
		c=1;
		sum+=d;
		printf("(%d/%d!)+",i,i);
	}
	printf("0\nSum is: %f",sum);
}
