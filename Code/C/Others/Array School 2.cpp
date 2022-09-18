#include<stdio.h>
#include<conio.h>
main()
{
	int a[5],i;
	printf("Enter Five Numbers: \n");
	for(i=0;i<5;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("The Numbers in Reverse order are: \n");
	for(i=4;i>=0;i--)
	printf("%d\n",a[i]);
}
