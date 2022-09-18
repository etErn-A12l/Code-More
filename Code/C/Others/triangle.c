#include<stdio.h>
int main()
{
	int l,b,a,p ;
	printf("Enter two sides: ");
	scanf("%d",&l);
	scanf("%d",&b);
	a=l*b;
	p=2*(l+b);
	printf("The area of the rectangle is %d\n",a);
	printf("The perimeter of the rectangle is %d",p);
	return 0;
}
