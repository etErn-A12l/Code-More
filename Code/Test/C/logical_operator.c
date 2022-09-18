#include "stdio.h"

int main(int argc, char const *argv[])
{
    int a = 10, b = 20;
    if (a && b)
        printf("\n&& !");
    else
        printf("\n&& Else !");
    if (a || b)
        printf("\n|| !");
    else
        printf("\n|| Else !");

    return 0;
}
