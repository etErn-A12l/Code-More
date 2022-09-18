#include <stdio.h>
// #include <conio.h>

void input(int *p)
{
    int i;
    for (i = 0; i <= 4; i++)
    {
        printf("\nEnter the %dth value: ",i+1);
        scanf("%d", p + i);
    }
}

void display(int *p)
{
    int i;
    for (i = 0; i <= 4; i++)
        printf("%d ", *(p + i));
}

void sort(int *p)
{
    int round, t, i;
    for (round = 1; round <= 4; round++)
    {
        for (i = 0; i <= 3; i++)
            if (*(p + i) > *(p + i + 1))
            {
                t = *(p + i); //a[i]*(p+i);
                *(p + i) = *(p + i + 1);
                *(p + i + 1) = t;
            }
    }
}

int main()
{
    int a[5];

    input(a);
    display(a);
    sort(a);
    printf("\n");
    display(a);

    return 0;
}