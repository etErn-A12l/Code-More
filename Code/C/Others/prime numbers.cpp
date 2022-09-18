#include<stdio.h>
int main()
{
	int i,n,r;
	int c=0;
	printf("Enter The Number To Check: ");
	scanf("%d",&n);
	if(n!=1||n!=2)
	for(i=2;i<n;i++)
	{
		if(n%i==0)
		{
			c=1;
			break;
		}
	}
	if(c==0)
	printf("Welldone !\nThe Given Number %d Is Prime !",n);
	else
	printf("Sorry !\nThe Given Number %d Is Not Prime !",n);
	return 0;
}
