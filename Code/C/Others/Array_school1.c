#include <stdio.h>
main()
{
	int a[10], i, s = 0, avg;
	printf("Enter Ten Numbers: ");
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &a[i]);
		s = s + a[i];
	}
	avg = s / 10;
	printf("Numbers are: \n");
	for (i = 0; i < 10; i++)
		printf("%d ", a[i]);
	printf("Sum of Numbers is %d", s);
	printf("\n Average number is %d", avg);
}
