#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char first_name[7], middle_name[7], last_name[7];
    printf("............Now enter the name of the user............\n");
    printf("Enter the First name of the user: ");
    scanf("%s",first_name);
    printf("Enter the middle name of the user: ");
    scanf("%s",middle_name);
    printf("Enter the last name of the user: ");
    scanf("%s",last_name);

    printf("The short form of the user is: \n");
    printf("%s %s %s  %c.%c.%c",first_name,middle_name,last_name, first_name[0], middle_name[0], last_name[0]);
    return 0;
}
