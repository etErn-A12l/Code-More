#include<stdio.h>
int main()
{
	int j,i,x;
	printf("Type the number until multiplication: ");
	scanf("%d",&x);
	j=1;
	do
	{
		i=1;
		do
		{
			printf("%d*%d=%d\n",j,i,j*i);
			++i;
		}
		while(i<=10);
		printf(".............\n");
		j++;
	}
	while(j<=x);
	return 0;
}
