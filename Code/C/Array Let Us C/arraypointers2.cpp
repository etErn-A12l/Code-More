/*Demonstration of passing an array to a function*/
#include<stdio.h>
void display1(int *,int);
void display2(int[],int);
int main()
{
    int num[6];
    printf("Enter six elements for the array: ");
    for (int i = 0; i < 6; i++)
    {
     scanf("%d",&num[i]);   
    }
    display1(&num[0],6);
    display2(&num[0],6);
    return 0;
}
void display1(int *j,int n)
{
    int i;
    for(i=0;i<=n-1;i++)
    {
        printf("element=%d\n",*j);
        j++;//increment pointer to point to next element
    }
}
void display2(int j[],int n)
{
    int i;
    for(i=0;i<=n-1;i++)
    printf("element= %d\n",j[i]);
}
