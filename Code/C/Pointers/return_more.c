#include <stdio.h>

void areaperi(int, float *, float *);

int main(int argc, char const *argv[])
{
    int radius;
    float area, perimeter;
    printf("Enter radius of the circle: ");
    scanf("%d", &radius);
    areaperi(radius, &area, &perimeter);
    printf("Area = %f, Perimeter = %f", area, perimeter);
    return 0;
}

void areaperi(int radius, float *a, float *p)
{
    *a = 3.14 * radius * radius;
    *p = 2 * 3.14 * radius;
}
