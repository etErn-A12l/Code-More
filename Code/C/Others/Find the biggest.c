#include<stdio.h>
main ()
{
	int a,b,c;
	printf("Enter three diffeent numbers: ");
	scanf("%d%d%d",&a,&b,&c);
	if(a>b)
	if(b>c)
	printf("%d is the greatest number",a);
	if(b>a)
	if(a>c)
	printf("%d is the greatest number",b);
	else
	printf("%d is the greatest number",c);
	return 0;
}
