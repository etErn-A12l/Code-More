#include<stdio.h>

int main()
{
    int *popcorn;
    int **ty;
    ty = &popcorn;
    int a = 90;
    popcorn = &a;
    printf("%u\n",popcorn);
    printf("%u\n",&popcorn);
    // printf("%u",popcorn + &popcorn);
    printf("%d",*popcorn+23); // This points to variable a
    printf("%d",**ty+23); // This also points to variable a

    return 0;
}
