#include <stdio.h>
#include <string.h>
int main()
{
    /* String Declaration*/
    char nickname[20];

    /* Console display using puts */
    puts("Enter your Nick name: ");

    /*Input using gets*/
    gets(nickname);
    printf("You Nick name is ");
    puts(nickname);
    // printf("You Nick name is ");
    return 0;
}
