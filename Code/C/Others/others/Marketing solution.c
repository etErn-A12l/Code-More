#include <stdio.h>
int main()
{
	int price;
	float total,amount;
	printf("Type the price of the thing per kilograme =");
	scanf("%d",&price);
	printf("Type the amount you require in kilograme =");
	scanf("%f",&amount);
	total=price*amount;
	printf("You have to pay %f rupees",total);
	return 0;
}
