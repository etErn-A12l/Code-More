#include <stdio.h>

void print_fucking_pattern(int num);

int main(int argc, char const *argv[])
{
    int num;
    printf("Enter the weight of the diamond: ");
    scanf("%d", &num);

    print_fucking_pattern(num);
    return 0;
}

void print_fucking_pattern(int num)
{

    int space = (num - 1) * 2, letter = num + 96, base = letter - 1;

    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < space; j++)
        {
            printf(" ");
        }
        for (int k = letter; k > base; k--)
        {
            printf("%c", k);
            if (k != base + 1)
            {
                printf("-");
            }
        }
        for (int l = base + 2; l < letter + 1; l++)
        {
            if (l != letter + 1)
            {
                printf("-");
            }
            printf("%c", l);
        }
        space -= 2;
        base--;
        printf("\n");
    }
    space += 2;
    base++;
    for (int i = 0; i < num; i++)
    {
        space += 2;
        base++;
        for (int j = 0; j < space; j++)
        {
            printf(" ");
        }
        for (int k = letter; k > base; k--)
        {
            printf("%c", k);
            if (k != base + 1)
            {
                printf("-");
            }
        }
        for (int l = base + 2; l < letter + 1; l++)
        {
            if (l != letter + 1)
            {
                printf("-");
            }
            printf("%c", l);
        }
        printf("\n");
    }
}

// The reference structure of the pattern

/*
    c
  c-b-c
c-b-a-b-c
  c-b-c
    c
*/