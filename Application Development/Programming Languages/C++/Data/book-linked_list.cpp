//Implementing a singly linked list
#include <stdio.h>
#include <cstdlib>


typedef struct record
{
    int value;
    struct record *next;
} NODE;

void append(int data);
void display();

NODE *start = NULL;

int main()
{
    int data, prompt;
    do
    {
        printf("\nEnter <1> to add New Node to list, <0> to End list: ");
        scanf("%d", &prompt);
        if (prompt == '1')
        {
            printf("\nEnter data: ");
            scanf("%d", &data);
            append(data);
        }
    } while (prompt != '0');
    display();
    return 0;
}

void append(int data)
{
    NODE *temp, *curr;
    temp = (NODE *)malloc(sizeof(NODE));
    temp->value = data;
    temp->next = NULL;
    if (start == NULL)
        start = temp;
    else
    {
        curr = start;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = temp;
    }
}

void display()
{
    int count = 0;
    NODE *curr = start;
    printf("\nCurrent list: \n");
    while (curr != NULL)
    {
        printf("Data %d = %d\n", ++count, curr->value);
        curr = curr->next;
    }
}
