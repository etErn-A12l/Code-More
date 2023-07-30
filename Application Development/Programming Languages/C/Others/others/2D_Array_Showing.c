#include <stdio.h>

int main()
{
	int x, i, j;
	printf("Enter he number of dimensionn you wanna see in the array: ");
	scanf("%d",&x);
	// int z = x;
	int ab[x][x];
	
	for (i = 0; i < x; i++)
	{
		for (j = 0; j < x; j++)
		{
			printf("Enter the element of %dth row and %dth coloumn: ",i+1,j+1);
			scanf("%d", &ab[i][j]);
		}
	}
	printf("Here Is Your Array Structure: ");
	for (i = 0; i < x; i++)
	{
		printf("\n");
		for (j = 0; j < x; j++)
		{
			printf("%d ", ab[i][j]);
		}
	}
	printf("\n");

	return 0;
}
