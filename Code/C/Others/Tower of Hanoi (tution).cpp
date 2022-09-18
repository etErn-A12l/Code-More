#include<stdio.h>
void TOH(int n,char BEG,char AUX,char END)
{
    if(n>=1)
    {
        TOH(n-1,BEG,END,AUX);
        printf("%c to %c/n",BEG,END);
        TOH(n-1,AUX,BEG,END);
    }
}
main()
{
    TOH(3,A,B,C);
    TOH(2,A,C,B);
    TOH(1,A,B,C);
    TOH(0,A,C,B);
    printf("A to C");
    TOH(0,B,A,C);
    printf("A to B");
    TOH(1,C,A,B);
    TOH(0,C,A,B);
    printf("C to B");
    TOH(0,A,C,B);
    printf("A to C");
    TOH(2,B,A,C);
    TOH(1,B,C,A);
    TOH(0,B,A,C);
    printf("B to A");
    TOH(0,C,B,A);
    printf("B to C");
    TOH(1,A,B,C);
    TOH(0,A,C,B);
    printf("A to C");
    TOH(0,B,A,C);
}
