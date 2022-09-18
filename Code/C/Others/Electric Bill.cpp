#include<stdio.h>
#include<conio.h>
int main()
{
	int a;
	float b;
	printf("Enter The Unit");
	scanf("%d",&a);
	if(a>=0&&a<=100)
	printf("You have to pay 150 Rs");
	else if(a>=101&&a<=200)
	{	
		b=150+(a-100)*2.50;
		printf("You have to pay %f Rs",b);
	}
		else if(a>=201&&a<=300)
	{
		b=150+100*2.50+(a-200)*3;
		printf("You have to pay %f Rs",b);
	}
	    else
	{
		b=150+100*2.50+100*3+(a-300)*4.50;
		printf("You have to pay %f Rs",b);
    }
    return 0;
}
