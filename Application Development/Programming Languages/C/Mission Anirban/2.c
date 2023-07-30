#include <stdio.h>

float calculate_comission(int amount, float grade)
{
    int ans = amount * grade / 100;
    return ans;
}

int main()
{
    int amount, grade;
    float comission;

    printf("Enter the sales amount: ");
    scanf("%d", &amount);
    printf("Enter the grade: ");
    scanf("%d", &grade);

    if (amount >= 12000)
    {
        comission = calculate_comission(amount, 23.5);
    }
    else if (amount >= 12000 && grade > 3 && grade < 5)
    {
        comission = calculate_comission(amount, 23);
    }
    else if (amount < 12000 && grade > 5)
    {
        comission = calculate_comission(amount, 22.4);
    }
    else
    {
        comission = calculate_comission(amount, 21.8);
    }

    printf("The comission is: %f", comission);

    return 0;
}