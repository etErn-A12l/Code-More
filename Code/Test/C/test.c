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

// #include <stdio.h>
// #include <string.h>
// #include <math.h>
// #include <stdlib.h>

// int main()
// {

//     char s[100];

//     scanf("%[^\n]%*c", &s);
//     printf("Hello, World!  ");
//     printf("\n%s",s);

//     /* Enter your code here. Read input from STDIN. Print output to STDOUT */
//     return 0;
// }

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int size, element, first_digit, last_digit;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];

    printf("\nEnter the elements of the array: \n");

    for (int i = 0; i < size; i++)
    {
        printf("Enter %dth element: ", i + 1);
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < size; i++)
    {
        element = arr[i];
        first_digit = element / 10;
        last_digit = element % 10;
        if (first_digit - last_digit == 5 || first_digit - last_digit == -5)
            printf("\nGot difference 5: %d", element);
    }
    return 0;
}
