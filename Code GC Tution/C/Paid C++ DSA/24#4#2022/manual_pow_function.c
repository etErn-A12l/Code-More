#include<stdio.h>

int manual_pow(int num,int power)
{
    int result = 1;
    for(int i=1;i<=power;i++)
    {
        result = result*num;
    }
    return result;
}

int main(int argc, char const *argv[])
{
    int num = 2;
    int result = manual_pow(num,3);

    printf("The ans is %d",result);
    return 0;
}
