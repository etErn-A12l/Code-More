#include<stdio.h>
int main()
{
    FILE *fp;
    char ch;
    int nol = 0, not = 0, nob = 0, noc = 0 ;
    fp = fopen ("Test.txt","r");
    while(1)
    {
        ch = fgetc(fp);
        if( ch == EOF )
            break;
        noc++;
        if( ch == ' ')
            nob++;
        if( ch =='\n')
            nol++;
        if( ch == '\t')
            not++;
    }
    fclose (fp);
    printf("\nNumber of characters = %d\n",noc);
    printf("Number of blanks = %d\n",nob);
    printf("Number of tabs = %d\n",not);
    printf("Number of lines = %d\n",nol);
    return 0;
}