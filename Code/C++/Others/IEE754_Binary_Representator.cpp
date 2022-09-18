#include <iostream>
#include <stdlib.h>
using namespace std;

const int MAX_non_fraction = 20;
const int MAX_fraction = 10;
const int MAX_32bit_result = 32;
const int MAX_64bit_result = 64;

int non_fraction_binary(int bin[], int num, int length, int size);
int fraction_binary(int bin[], float num);
float fraction_part(float num);
void calculate_32bit_mantissa(int result[], int non_fraction[], int fraction[], int length_of_fraction, int length_of_non_fraction);
void calculate_64bit_mantissa(int result[], int non_fraction[], int fraction[], int length_of_fraction, int length_of_non_fraction);
void calculate_32bit_exponent(int result[], int exponent, float number);
void calculate_64bit_exponent(int result[], int exponent, float number);

int main(int argc, char const *argv[])
{
    char decision;
    cout << "\n-----WELCOME TO IEE754 STANDARD BINARY REPRESENTATOR-----" << endl;

    do
    {
        float number, converted_positive_number;
        int *non_fraction_binary_array = (int *)calloc(MAX_non_fraction, sizeof(int));
        int *fraction_binary_array = (int *)calloc(MAX_fraction, sizeof(int));
        int *result_32bit = (int *)calloc(MAX_32bit_result, sizeof(int));
        int *result_64bit = (int *)calloc(MAX_64bit_result, sizeof(int));

        cout << "\nEnter the Floating Number in Decimal: ";
        cin >> number;

        if (number < 0)
            converted_positive_number = number * (-1);
        else
            converted_positive_number = number;

        int length_of_fraction_binary = fraction_binary(fraction_binary_array, fraction_part(converted_positive_number));
        int exponent = non_fraction_binary(non_fraction_binary_array, int(converted_positive_number), length_of_fraction_binary, MAX_non_fraction);
        calculate_32bit_mantissa(result_32bit, non_fraction_binary_array, fraction_binary_array, length_of_fraction_binary, exponent);
        cout << endl
             << "Below is the 32 bit Representation" << endl;
        calculate_32bit_exponent(result_32bit, exponent, number);
        cout << endl;
        calculate_64bit_mantissa(result_64bit, non_fraction_binary_array, fraction_binary_array, length_of_fraction_binary, exponent);
        cout << endl
             << "Below is the 64 bit Representation" << endl;
        calculate_64bit_exponent(result_64bit, exponent, number);

        // Decision Part
        cout << endl
             << endl
             << "-----------------------------------------------"
             << "\nDo you want to check another number ? (Y/N): ";
        cin >> decision;
    } while (decision == 'y' || decision == 'Y');

    return 0;
}

int non_fraction_binary(int bin[], int num, int length, int size)
{
    long int calculation[MAX_non_fraction];
    int i;

    // initializing array for binary calculation
    calculation[size - 1] = 1;
    for (i = size - 2; i >= 0; i--)
        calculation[i] = calculation[i + 1] * 2;

    // Calculating Binary for non fraction part
    while (num > 0)
    {
        i = size - 1;
        while (num >= calculation[i] && i >= 0)
            i--;
        i++;
        bin[i - length] = 1;
        num -= calculation[i];
    }

    // Calculating Exponent
    int exponent = 0;
    for (int i = 0; i < MAX_non_fraction; i++)
    {
        if (bin[i] == 1)
        {
            exponent = MAX_non_fraction - 1 - length - i;
            break;
        }
    }

    // for (i = 0; i < MAX_non_fraction; i++)
    //     cout << bin[i] << " ";

    return exponent;
}

int fraction_binary(int bin[], float num)
{
    int i = 0;

    while (num = fraction_part(num * 2))
    {

        bin[i] = 1;
        i++;
    }
    bin[i] = 1;

    // for (int j = 0; j < MAX_fraction; j++)
    //     cout << bin[j] << " ";

    return i + 1;
}

float fraction_part(float num)
{
    float fraction = num - int(num);
    return fraction;
}

void calculate_32bit_mantissa(int result[], int non_fraction[], int fraction[], int length_of_fraction, int length_of_non_fraction)
{
    // removing 1st digit of non fraction part
    non_fraction[MAX_non_fraction - length_of_fraction - length_of_non_fraction - 1] = 0;

    // merging fraction and non fraction part
    for (int i = 0; i < length_of_fraction; i++)
    {
        non_fraction[MAX_non_fraction - length_of_fraction + i] = fraction[i];
    }

    // placing in result array
    for (int i = 9, j = MAX_non_fraction - length_of_fraction - length_of_non_fraction; i < 32, j < MAX_non_fraction; i++, j++)
    {
        if (j == MAX_non_fraction)
            break;
        result[i] = non_fraction[j];
    }
}

void calculate_64bit_mantissa(int result[], int non_fraction[], int fraction[], int length_of_fraction, int length_of_non_fraction)
{
    // removing 1st digit of non fraction part
    non_fraction[MAX_non_fraction - length_of_fraction - length_of_non_fraction - 1] = 0;

    // merging fraction and non fraction part
    for (int i = 0; i < length_of_fraction; i++)
    {
        non_fraction[MAX_non_fraction - length_of_fraction + i] = fraction[i];
    }

    // placing in result array
    for (int i = 12, j = MAX_non_fraction - length_of_fraction - length_of_non_fraction; i < 64, j < MAX_non_fraction; i++, j++)
    {
        if (j == MAX_non_fraction)
            break;
        result[i] = non_fraction[j];
    }
}

void calculate_32bit_exponent(int result[], int exponent, float number)
{
    int exer_exponent = exponent + 127;
    int *exponent_array = (int *)calloc(8, sizeof(int));
    int useless = non_fraction_binary(exponent_array, exer_exponent, 0, 8);

    // placing in result array
    if (number < 0)
        result[0] = 1;
    for (int i = 1, j = 0; i < 9, j < 8; i++, j++)
        result[i] = exponent_array[j];

    // Displaying Result
    cout << result[0] << " ";
    for (int i = 1; i < 9; i++)
    {
        cout << result[i];
    }
    cout << " ";
    for (int i = 9; i < MAX_32bit_result; i++)
    {
        cout << result[i];
    }
}

void calculate_64bit_exponent(int result[], int exponent, float number)
{
    int exer_exponent = exponent + 1023;
    int *exponent_array = (int *)calloc(11, sizeof(int));
    int useless = non_fraction_binary(exponent_array, exer_exponent, 0, 11);

    // placing in result array
    if (number < 0)
        result[0] = 1;
    for (int i = 1, j = 0; i < 12, j < 11; i++, j++)
        result[i] = exponent_array[j];

    // Displaying Result
    cout << result[0] << " ";
    for (int i = 1; i < 12; i++)
    {
        cout << result[i];
    }
    cout << " ";
    for (int i = 12; i < MAX_64bit_result; i++)
    {
        cout << result[i];
    }
}