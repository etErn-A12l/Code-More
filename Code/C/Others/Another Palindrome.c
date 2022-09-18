// This is not another palindrome it is the old palindrome number checking system

#include <stdio.h>

int main()
{
    int n, reversedN = 0, remainder, originalN;
    printf("Enter an integer: ");
    scanf("%d", &n);
    originalN = n;
    // reversed integer is stored in reversedN
    while (n != 0)
    {
        remainder = n % 10;
        reversedN = reversedN * 10 + remainder;
        n /= 10;
    }
    // palindrome if orignalN and reversedN are equal
    if (originalN == reversedN)
        printf("Wow! %d is a Palindrome Number.", originalN);
    else
        printf("Sorry! %d is not a Palindrome Number.", originalN);
    return 0;
}
