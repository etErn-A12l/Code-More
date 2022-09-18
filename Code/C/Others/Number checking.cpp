#include<stdio.h>
int main ()
{
	int n;
	printf("Enter a number: ");
	scanf("%d",&n);
	if(n>=0)
	printf("The number %d is Positive.",n);
	else
	printf("The number %d is Negative.",n);
	getch();
}
