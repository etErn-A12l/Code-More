#include<stdio.h>
#include<string.h>

int main()
{
    char name[40];
    printf("Enter your name: ");
    // scanf("%s",&name);
    gets(name);
    int size = strlen(name);
    printf("%d",size);
    return 0;
}
