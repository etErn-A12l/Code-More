#include <stdio.h>
#include <string.h>

int main()
{
    int j = 0, k = 0;
    char ch[30], ch1[30], ch2[30];
    printf("Enter a word: ");
    scanf("%s", &ch);
    int l = strlen(ch);
    // printf("%d",l);
    for (int i = 0; i < l; i++)
    {
        if (ch[i] == 'a' || ch[i] == 'e' || ch[i] == 'i' || ch[i] == 'o' || ch[i] == 'u')
        {
            ch1[j] = ch[i];
            j++;
        }
        else
        {
            ch2[k] = ch[i];
            k++;
        }
    }
    ch1[j] = '\0';
    ch2[k] = '\0';
    printf("%s", strcat(ch1, ch2));

    return 0;
}
