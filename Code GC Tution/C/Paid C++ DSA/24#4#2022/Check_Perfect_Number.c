#include<stdio.h>

int main(int argc, char const *argv[])
{
    int num,result = 0;
    printf("Dao: ");
    scanf("%d",&num);
    for(int i = 1;i<num;i++)
    {
        if(num % i == 0)
        {
            // printf("Divisor is %d\n",i);
            result = result + i;
        }
    }
    // printf("%d",result);
    if(num == result)
    {
        printf("The number is perfect number !");
    }
    else
    {
        printf("The number is not a perfect number !");
    }
    return 0;
}
