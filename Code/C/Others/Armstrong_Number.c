// #include<stdio.h>
// #include<conio.h>
// int main()
// {
// 	int number, originalNumber, remainder, result = 0;
// 	printf("Enter a three digit integer: ");
//     scanf("%d", &number);
// 	originalNumber = number;
// 	while (originalNumber != 0)
// 	    {
// 	        remainder = originalNumber%10;
// 	        result += remainder*remainder*remainder;
// 	        originalNumber /= 10;
// 	    }
	
// 	if(result == number)
// 	    printf("%d is an Armstrong number.",number);
// 	else
// 	    printf("%d is not an Armstrong number.",number);
	
// 	return 0;
// }

#include<stdio.h>
#include<stdlib.h>

int main()
{
    int number, originalNumber, remainder, result = 0;
    printf("Enter a three digit integer: ");
    scanf("%d", &number);
    originalNumber = number;
    while (originalNumber != 0)
    {
        remainder = originalNumber%10;
        result += remainder*remainder*remainder;
        originalNumber /= 10;
    }
    printf("%d is %s an Armstrong number.", number, (result == number) ? "" : "not");
    return 0;
}