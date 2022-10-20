#include<stdio.h>
#include<stdlib.h>
int main()
{
    FILE *fs,*ft;
    char ch,source[30],target[30];
    printf("\nEnter the source file name: ");
    gets(source);
    printf("\nEnter the target file name: ");
    gets(target);
    fs=fopen(source,"r");
    if (fs==NULL)
    {
        fopen(source,"a");
    }
    ft=fopen(target,"w");
    if (ft==NULL)
    {
        puts("Cannot open target file");/* code */
        fclose(fs);
        exit(2);
    }
    while(1)
    {
        ch=fgetc(fs);
        if (ch==EOF)
        {
            puts("Copy successful !");
            break;
        }
        else
        {
            fputc(ch,ft);
        }
    }
    fclose(fs);
    fclose(ft);
    return 0;
}
