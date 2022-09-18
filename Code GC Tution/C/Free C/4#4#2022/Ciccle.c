#include<stdio.h>

int main()
{
    int radius;
    int perimeter;
    printf("Enter the radius of the circle: ");
    scanf("%d",&radius);
    perimeter = 2*3.14*radius;
    printf("The perimeter of the given circle is %d\n",perimeter);
    int a = 9, b = 7;
    a = b;
    printf("%d",a);
    return 0;
    
}
