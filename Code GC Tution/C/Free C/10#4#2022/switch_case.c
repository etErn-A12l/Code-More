#include <stdio.h>

int main()
{
    char a;
    goto muri;

switch(a)
{
    case 'y':
    case 'Y':
        printf("Sorry for disturbance ");
        break;
    case 'N':
    case 'n':
        printf("I love you !");
        break;
    default :
        printf("YOu are naughty !");
        break;
}

muri:
    printf("Do you have a boyfriend ? (Y/N): ");
    scanf("%c", &a);
    return 0;
}
