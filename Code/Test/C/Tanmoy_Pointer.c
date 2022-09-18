// #include <stdio.h>

// int main(int argc, char const *argv[])
// {
//     int apple;
//     int *ripple;
//     apple = 23;
//     ripple = &apple;
//     printf("%u", ripple);
//     return 0;
// }

#include <stdio.h>

void sumAndAvg(float *a, float *b, float *sum, float *avg);

int main()
{
    float i, j, sum, avg;
    i = 3;
    j = 6;
    sumAndAvg(&i, &j, &sum, &avg);
    printf("\nthe value of sum is %f ", sum);
    printf("\nthe value of avg is %f ", avg);

    // printf("\na = %f", i);
    // printf("\nb = %f", j);

    return 0;
}

void sumAndAvg(float *a, float *b, float *sum, float *avg)
{
    printf("\na = %f", *a);
    printf("\nb = %f", *b);

    *sum = *a + *b;
    *avg = *sum / 2;
}