#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{
	int n,s,m,c,p,i,j;
	int X[10];
	printf("Enter 10 elements of the array:\n  ");
	for(i=0;i<10;i++)
	{
		scanf("%d",&X[i]);
	}
	printf("The Armstrong numbers are: ");
	for(i=0;i<10;i++)
	{
		s=0;
		c=0;
		m=p=X[i];
		while(p!=0)
		{
			p=p/10;
			c=c+1;
		}
		while(m!=0)
		{
			n=m%10;
			s=s+pow(n,c);
			m=m/10;
		}
		if(X[i]==s)
		printf("%d",s);
	}
	getch();
}
