#include<stdio.h>
int main()
{
	int s;
	printf("Type the year-");
	scanf("%d",&s);
	if(s%4==0)
	printf("The year %d is leap year",s);
	else
	printf("The year %d is not leap year",s);
}
