/*
 * C Program to Count Number of Words in a given Text Or Sentence
 */
#include<stdio.h>
#include<conio.h>
#include<string.h>
 
int main(void)
{
    char s[200];
    int count = 0, i;
 
    printf("Enter The Sentense: ");
    scanf("%[^\n]s", s);
    for (i = 0;s[i] != '\0';i++)
    {
        if (s[i] == ' ' && s[i+1] != ' ')
            count++;    
    }
    printf("Number of words in given sentense are: %d\n", count + 1);
    getch();
}
