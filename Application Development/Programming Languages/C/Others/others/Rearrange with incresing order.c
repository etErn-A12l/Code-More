#include <stdio.h>

int main()
{
	int a, b, c;
	printf("Enter The First Number: ");
	scanf("%d", &a);
	printf("Enter The Second Number: ");
	scanf("%d", &b);
	printf("Enter The Third Number: ");
	scanf("%d", &c);

	if (a > b)
	{
		if (a > c)
		{
			if (b > c)
				printf("%d max \n %d mid \n %d small", a, b, c);
			else
				printf("%d max \n %d mid \n %d small", a, c, b);
		}
		else
			printf("%d max \n %d mid \n %d small", c, a, b);
	}

	if (b > c)
	{
		if (a > c)
		{
			if (b > a)
				printf("%d max \n %d mid \n %d small", b, a, c);
			else
				printf("%d max \n %d mid \n %d  small", b, c, a);
		}
		else
			printf("%d max \n %d mid \n %d small", c, b, a);
	}

		return 0;
}
