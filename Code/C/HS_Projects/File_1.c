#include<stdio.h>
int main()
{
    FILE *fp;
    char ch;
    fp = fopen("Test.txt","r");
    while(1)
    {
        ch = fgetc(fp);
        if(ch == EOF)
            break;
        printf("%c",ch);
    }
    printf("\n\n");
    fclose(fp);
    return 0;
}