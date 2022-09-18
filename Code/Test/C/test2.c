#include <stdio.h>
#include <string.h>
// #include <stdlib.h>

struct student
{
    char name[30];
    float sum;
    float avg;
    int r;
    float m[5];
}st[10];

int main()
{
    struct student st[10];
    
    for (int i = 0; i < 10; i++)
    {
        st[i].sum = 0;
        printf("Enter name: \n");
        gets(st[i].name);
        printf("Enter roll noumber: \n");
        scanf("%d", &st[i].r);
        printf("Enter marks of 5 subjects: \n");
        for (int j = 0; j < 5; j++)
        {
            scanf("%f", &st[i].m[j]);
            st[i].sum = st[i].sum + st[i].m[j];
        }
        st[i].avg = st[i].sum / 5;
    }
    for (int i = 0; i < 10; i++)
    {
        if (st[i].avg > 90)
        {
            puts(st[i].name);
            printf("%d\n", st[i].r);
            for (int j = 0; j < 5; j++)
            {
                printf("%d ", st[i].m[j]);
            }
        }
    }
    return 0;
}