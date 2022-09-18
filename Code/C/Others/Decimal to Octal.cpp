#include <stdio.h>
// #include<conio.h>
int main()
{
	int m, i = 0, j = 0, x = 0, k = 0;
	int no;
	int a[20], b[20];
	printf("Enter Decimal No:\n");
	scanf("%d", &no);
	while (no > 0)
	{
		m = no % 8;
		a[i] = m;
		++i;
		no = no / 8;
	}
	for (j = i - 1; j >= 0; j--)
	{
		b[x] = a[j];
		x++;
	}
	for (k = 0; k < x; k++)
	{
		printf("%d", b[k]);
	}
	return 0;
}
