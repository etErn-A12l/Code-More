#include<stdio.h>
int main()
{
	int A[3][3],B[3][3],C[3][3],i,j;
	printf("Enter Elements For First Array: ");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			scanf("%d",&A[i][j]);
		}
	}
	printf("Enter Elements For Second Array: ");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			scanf("%d",&B[i][j]);
		}
	}
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			C[i][j]=A[i][j]+B[i][j];
		}
	}
	printf("\n\nElements For First Matrix: ");
	for(i=0;i<3;i++)
	{
		printf("\n");
		for(j=0;j<3;j++)
		{
			printf("%d ",A[i][j]);
	    }
	}
	printf("\n\nElements For Second Matrix: ");
	for(i=0;i<3;i++)
	{
		printf("\n");
		for(j=0;j<3;j++)
		{
			printf("%d ",B[i][j]);
		}
	}
	printf("\n\nSum of The Above Two Matrix: ");
	for(i=0;i<3;i++)
	{
		printf("\n");
		for(j=0;j<3;j++)
		{
			printf("%d ",C[i][j]);
		}
	}
}
