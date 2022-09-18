#include <stdio.h>
int main()
{
    int number,rem,sum=0,i;
    printf("Enter a Number\n");
    scanf("%d",&number);
    for(i=1;i<=(number-1);i++)
    {
        rem=number%i;
	if(rem==0)
        {
            sum=sum+i;
        }
    }
    if(sum==number)
        printf("\nWow! Entered Number %d Is A Perfect Number.",number);
    else
        printf("\nSorry! Entered Number Is Not A Perfect Number.",number);
    return 0;
}
