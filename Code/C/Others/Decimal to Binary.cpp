#include<stdio.h>
#include<conio.h>
main()
{
	int dec,bin[10],p=0;
	printf("Enter the Number: \n");
	scanf("%d",&dec);
	while(dec!=0)
	{
		bin[p]=dec%2;
		dec=dec/2;
		p++;
	}
	for(p=p-1;p>=0;p--)
	printf("%d",bin[p]);
}
