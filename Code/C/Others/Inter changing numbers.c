#include<stdio.h>
int main()
{
	int a,b;
	printf("Type two numbers: ");
	scanf("%d%d",&a,&b);
	a=a*b;
	b=a/b;
	a=a/b;
	printf("First Interchanging number is %d\n",a);
	printf("Second Interchanging number is %d",b);
	getch();
}
	
