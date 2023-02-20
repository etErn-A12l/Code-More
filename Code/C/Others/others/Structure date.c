#include<stdio.h>
#include<conio.h>
struct date
{
    int d,m,y;
};
main(void)
{
    struct date today,d1;
    today.d=26;
    today.m=7;
    today.y=2015;
    d1=today;
    printf("Date:%d/%d/%d",d1.d,d1.m,d1.y);
    printf("\nEnter today's date: ");
    scanf("%d/%d/%d",&d1.d,&d1.m,&d1.y);
    printf("\nDate:%d/%d/%d",d1.d,d1.m,d1.y);
    getch();
}
