// #include <stdio.h>

// int main()
// {
//     int a = 24, b = 8, counter = 0, i, r, max, min;
//     // printf("Enter a and b: ");
//     // scanf("%d%d", &a, &b);
//     if (a > b)
//     {
//         max = a;
//         min = b;
//     }
//     else
//     {
//         min = b;
//         max = a;
//     }
//     int x = max;
//     // printf("%d",c);
//     while (x >= min)
//     {
//         r = x - min;
//         x = r;
//         // counter += 1;
//         counter++;
//     }
//     printf("Answer = %d\nRemainder = %d", counter, r);
//     return 0;
// }

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
	
    char s[100];
    
    scanf("%[^\n]%*c", &s);
    printf("Hello, World!  ");
    printf("\n%s",s);
  	
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}