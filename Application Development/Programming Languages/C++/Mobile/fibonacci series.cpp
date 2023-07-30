#include<stdio.h>
void print(long int,long int);
int main()
{
	long int i=0,j=1;
	print(i,j);
	return 0;
}
/*void print(long int a,long int b)
{
	long int k,n;
	printf("Enter the number of fibonacci series: ");
	scanf("%ld",&n);
	for(int q=1;q<=n;q++)	[this is not 
	{						using recursion]
		k=a+b;
		a=b;
		b=k;
		printf("%ld, ",k);
	}
}*/
void print(long int i,long int j)
{
	long int k;			//{
	k=i+j;;
	i=j;
	j=k;				//using recursion
	printf("%ld ",k);
	if(k<121393)
	{
		print(i,j);		//}
	}
}
