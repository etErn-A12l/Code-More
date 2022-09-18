#include<stdio.h>

int main()
{
    char letter = 'A';
    // printf("The letter is %c and it's ASCII value is %d\n",letter,letter);

    while(letter!='b')
    {
        printf("The letter is %c and it's ASCII value is %d\n",letter,letter);
        letter ++;
    }
    return 0;
}
