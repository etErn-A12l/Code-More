#include <stdio.h>

float Tax_charge(int amount, int tax_percent)
{
    // Calculates the tax
    float ans = ((amount * tax_percent) / 100);
    ans += amount;
    return ans;
}

int main()
{
    int amount;
    float final_bill;
    int tax_percent = 0;

    // Taking the amount from the user
    printf("Enter the amount of the electric bill: ");
    scanf("%d", &amount);

    if (amount < 800)
    {
        final_bill = Tax_charge(amount, 0);
    }
    else if (amount >= 800 && amount < 1200)
    {
        tax_percent = 10;
        final_bill = Tax_charge(amount, tax_percent);
    }
    else if (amount >= 1200 && amount < 2000)
    {
        tax_percent = 15;
        final_bill = Tax_charge(amount, tax_percent);
    }
    else if (amount > 1999)
    {
        tax_percent = 22;
        final_bill = Tax_charge(amount, tax_percent);
    }

    printf("The total payable amount is :%f.", final_bill);

    return 0;
}