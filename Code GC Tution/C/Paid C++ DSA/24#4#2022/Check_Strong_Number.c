#include <stdio.h>

int main(int argc, char const *argv[])
{
    int num, result = 0;
    printf("Dada doya kore number ta dao: ");
    scanf("%d", &num);
    int temp = num;
    while (temp > 0)
    {
        int fact = 1;
        int Narkel_gach = temp % 10;
        for (int i = 1; i <= Narkel_gach; i++)
        {
            fact = fact*i;
        }
        result = result + fact;
        temp /= 10;
    }
    if(result == num)
    {
        printf("The number is Strong number !");
    }
    else
    {
        printf("The number is not a Strong number !");
    }

    return 0;
}
