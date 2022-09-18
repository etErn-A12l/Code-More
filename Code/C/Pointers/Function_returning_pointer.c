#include<stdio.h>

int *fun();

int main(int argc, char const *argv[])
{
    int *p;
    p = fun();
    printf("%d",*p);
    return 0;
}

int *fun()
{
    int u = 90;
    return (&u);
}
