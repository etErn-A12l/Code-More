#include <stdio.h>

int main(int argc, char const *argv[])
{
    int i = 54;
    float a = 3.14;
    char *ii, *aa;

    ii = (char *)&i;
    aa = (char *)&a;

    printf("%u\n", ii);
    printf("%u\n", aa);
    printf("%d\n", *ii);
    printf("%f\n", *aa);

    return 0;
}
