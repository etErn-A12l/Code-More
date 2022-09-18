#include<stdio.h>
int main()
{
    int num[]={24,34,12,44,56,17};
    int i,*j;
    int as=89;
    float er;
    er = as;
    printf("%f",er);
    j=&num[0];//assign address of zeroth element
    for (i=0;i<=5;i++)
    {
        printf("address =%u element =%d\n",j,*j);
        j++;//increment pointer to point to next location 
    }
    return 0;
}
