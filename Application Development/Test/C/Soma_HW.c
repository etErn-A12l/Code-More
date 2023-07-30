// 1. Write a program to print a set of 8 even numbers in descending and ascending order

#include <stdio.h>

int main()
{
    int i = 0, a = 2;
    printf("\n----** Ascending order **----\n");
    while (i++ < 8)
    {
        printf("\n%d", a);
        a += 2;
    }
    printf("\n\n----** Descending order **----\n");
    while (--i > 0)
    {
        a -= 2;
        printf("\n%d", a);
    }
    return 0;
}

// 2. Write a Program to Check if a given stream is palindrome or not

#include <stdio.h>

int main()
{
    int n, reversedInteger = 0, remainder, originalInteger;

    printf("Enter an integer: ");
    scanf("%d", &n);

    originalInteger = n;

    // reversed integer is stored in variable
    while (n != 0)
    {
        remainder = n % 10;
        reversedInteger = reversedInteger * 10 + remainder;
        n /= 10;
    }

    // palindrome if orignalInteger and reversedInteger are equal

    if (originalInteger == reversedInteger)
        printf("%d is a palindrome number.", originalInteger);
    else
        printf("%d is not a palindrome number.", originalInteger);

    return 0;
}

// 3. Write a Program to Demonstrate a Pointer Variable

#include <stdio.h>

int main()
{
    int a = 10;
    int *a1 = &a;   // The pointer a1 contains the address of a variable which contains 10

    // We can print the address as well as value of a by using the pointer a1

    printf("The Address of a: %u",a1);    // Prints the address of a
    printf("\nThe value of a: %d", *a1);    // Prints the value of a

    return 0;
}

// 4. Write a Program to change a given temperature from fahrenheit to Celcius

#include <stdio.h>

int main()
{
    float f, c;
    printf("Enter the temperature in Fahrenheit: ");
    scanf("%f", &f);
    c = ((f - 32) * 5) / 9;
    printf("\nThe temperature in Celcius is: %f", c);
    return 0;
}
