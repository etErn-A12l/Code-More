#include <stdio.h>

int main(int argc, char const *argv[])
{
    int t_s1, t_s2, p;
    scanf("%d", &t_s1);
    scanf("%d", &t_s2);
    scanf("%d", &p);
    int max = (t_s1 > t_s2) ? t_s1 : t_s2;
    if (p < max)
        printf("-1");
    else
        printf("%d", p / max);
    return 0;
}
 