#include<stdio.h>
#include<conio.h>
main(void)
{
	int i,j;
	long int f;
	int x[10];
	printf("Enter 10 elements of the array for factorial: ");
	for(i=0;i<10;i++)
	{
		scanf("%d",&x[i]);
	}
	for(i=0;i<10;i++)
	{
		f=1;
		for(j=1;j<=x[i];j++)
		{
			f=f*j;
		}
		printf("\n %d!=%ld",x[i],f);
	}
	getch();
}
