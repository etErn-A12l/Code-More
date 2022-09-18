#include <stdio.h>
int main()
{
	int n;
	printf("Type the year:\n");
	scanf("%d",&n);
	if(n>365)
	printf("the year %d is leap year !",n);
	else
	printf("the year %d is not leap year !",n);
}
