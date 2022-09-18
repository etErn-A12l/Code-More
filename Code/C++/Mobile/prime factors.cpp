#include <stdio.h>

void factors(int);
void prime(int r);

int main()
{
	int a;
	int a1 = 12, a2 = 14;

	printf("Enter the number: ");
	scanf("%d", &a);
	factors(a);
	return 0;
}
void factors(int x)
{
	for (int i = 1; i <= x; i++)
	{
		if (x % i == 0)
		{
			prime(i);
		}
		else
		{
			continue;
		}
	}
}
void prime(int r)
{
	int i = 2;
	while (i <= r - 1)
	{
		if (r % i == 0)
		{
			break;
		}
		i++;
	}
	if (i == r)
		printf("%d ", r);
}
