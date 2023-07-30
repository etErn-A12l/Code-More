#include <stdio.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void populate()
{
    struct node *newnode;
    int n;
    printf("Enter no. of nodes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = 100;
        newnode->next = NULL;
        if (head != NULL)
        {
            newnode->next = head;
            head = newnode;
        }
        else
            head = newnode;
    }
}

void end()
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter data for the last node: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    struct node *pointer = head;

    while (pointer->next != NULL)
        pointer = pointer->next;

    pointer->next = newnode;
}

int main(int argc, char const *argv[])
{
    populate();
    end();
    struct node *pointer = head;
    printf("\nThe stored Nodes are below: \n");
    while (pointer != NULL)
    {
        printf("\t%d", pointer->data);
        pointer = pointer->next;
    }

    return 0;
}
