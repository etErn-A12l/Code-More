#include<stdio.h>
int main()
{
	int a[3],i;
	printf("Enter Three Different Numbers: \n");
	for(i=0;i<=2;i++)
		{
			scanf("%d",&a[i]);
		}
	{
	for(i=0;i<=1;i++)
	if(a[i]>a[i+1])
		{
		printf("%d is max",a[i]);
		}
	for(i=1;i<=2;i++)
	else(a[i-1]>a[i])
	     {
	        printf("%d is max",a[i]);	
	     }
    }
}

