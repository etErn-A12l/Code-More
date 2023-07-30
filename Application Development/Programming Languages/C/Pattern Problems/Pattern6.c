#include <stdio.h>

int main()
{
	int i, j, k, t = 0;
	for (i = 1; i <= 7; i++)
	{
		for (k = t; k < 7; k++)
		{
			printf(" ");
		}
		for (j = 0; j < i; j++)
		{
			printf("*");
			t++;
		}
		printf("\n");
	}

	return 0;
}
