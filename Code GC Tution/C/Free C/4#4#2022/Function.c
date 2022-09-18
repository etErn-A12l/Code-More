#include<stdio.h>

float panta(int radiu)
{
    float result = 2*3.14*radiu;
    return result;
}

int main()
{
    
    int radius;
    printf("Enter the radius: ");
    scanf("%d",&radius);
    float result = panta(radius);
    printf("The perimeter = %f",result);

    /* code */
    return 0;
}

