#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define COLOR_BOLD "\e[1m"
#define COLOR_OFF "\e[m"
#define COLOR_RED "\033[31m"
#define COLOR_YELLOW "\033[33m"
#define COLOR_BLUE "\033[34m"
#define COLOR_GREEN "\033[32m"

struct node
{
    int data;
    struct node *next;
};

struct node *start = NULL;

void add_at_beg();
void add_at_end();
void add_at_pos();
void del_beg();
void del_end();
void del_pos();
void display();
void del_list();
void sort();
bool CheckUnderflowCondition(struct node *);
bool CheckIfMemoryAllocated(struct node *);

int main(int argc, char const *argv[])
{
    int option;
    system("cls");
    do
    {
        printf(COLOR_YELLOW "\n\n  ******* MENU *******");
        printf("\n1. Add node at beginning");
        printf("\n2. Add node at end");
        printf("\n3. Add node at given Position");
        printf("\n4. Delete the first Node");
        printf("\n5. Delete the last Node");
        printf("\n6. Delete Node from given Position");
        printf("\n7. Delete all nodes at once");
        printf("\n8. Sort the Entire list");
        printf("\n9. Display all nodes");

        printf(COLOR_BLUE "\n\nEnter your choice: ");
        scanf("%d", &option);
        system("cls");

        switch (option)
        {
        case 1:
            add_at_beg();
            break;
        case 2:
            add_at_end();
            break;
        case 3:
            add_at_pos();
            break;
        case 4:
            del_beg();
            break;
        case 5:
            del_end();
            break;
        case 6:
            del_pos();
            break;
        case 7:
            del_list();
            break;
        case 8:
            sort();
            break;
        case 9:
            display();
            break;
        default:
            break;
        }
    } while (option < 10);

    return 0;
}

void add_at_beg()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    // Checking if memory allocated
    if (CheckIfMemoryAllocated(temp))
    {
        temp->next = NULL;
        printf("\nEnter the data: ");
        scanf("%d", &temp->data);
        temp->next = start;
        start = temp;
    }
    printf(COLOR_GREEN "\n%d is INSERTED !",temp->data,COLOR_BLUE);
}

void add_at_end()
{
    // cheching if start is empty
    if (start == NULL)
    {
        add_at_beg();
        return;
    }
    struct node *temp, *ptr;
    temp = (struct node *)malloc(sizeof(struct node));
    // Checking if memory allocated
    if (CheckIfMemoryAllocated(temp))
    {
        temp->next = NULL;
        printf("\nEnter the data: ");
        scanf("%d", &temp->data);
        // Traversing the linked list till the last node
        ptr = start;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
        printf(COLOR_GREEN "\n%d is INSERTED !",temp->data,COLOR_BLUE);
    }
}

void add_at_pos()
{
    struct node *temp, *ptr = start;
    int pos;
    temp = (struct node *)malloc(sizeof(struct node));
    // Checking if memory allocated
    if (CheckIfMemoryAllocated(temp))
    {
        temp->next = NULL;
        printf("\nEnter the data: ");
        scanf("%d", &temp->data);
        printf("\nEnter the position: ");
        scanf("%d", &pos);
        if (pos == 0)
        {
            temp->next = start;
            start = temp;
        }
        else
        {
            // Traversing to the position
            for (int i = 0; i < pos - 1; i++)
            {
                if (ptr == NULL)
                {
                    printf("\nPosition NOT FOUND !");
                    return;
                }
                else
                    ptr = ptr->next;
            }
            temp->next = ptr->next;
            ptr->next = temp;
        }
        printf(COLOR_GREEN "\n%d is INSERTED !",temp->data,COLOR_BLUE);
    }
}

void del_beg()
{
    if (!CheckUnderflowCondition(start))
    {
        struct node *temp = start;
        start = start->next;
        printf(COLOR_RED "\n%d is DELETED !" COLOR_OFF, temp->data);
        free(temp);
    }
}

void del_end()
{
    if (!CheckUnderflowCondition(start))
    {
        struct node *temp = start, *preptr;
        if (temp->next == NULL)
            del_beg();
        else
        {
            while (temp->next != NULL)
            {
                preptr = temp;
                temp = temp->next;
            }
            printf(COLOR_RED "\n%d is DELETED !" COLOR_OFF, temp->data);
            preptr->next = NULL;
            free(temp);
        }
    }
}

void del_pos()
{
    if (!CheckUnderflowCondition(start))
    {
        int pos;
        display();
        printf("\nEnter the position: ");
        scanf("%d", &pos);
        if (pos == 0)
            del_beg();
        else
        {
            struct node *temp = start, *preptr = temp;
            for (int i = 0; i < pos; i++)
            {
                if (temp == NULL)
                {
                    printf(COLOR_RED "\nPosition NOT FOUND !" COLOR_BLUE);
                    return;
                }
                preptr = temp;
                temp = temp->next;
            }
            preptr->next = temp->next;
            printf(COLOR_RED "\n%d is DELETED !" COLOR_OFF, temp->data);
            free(temp);
        }
    }
}

void del_list()
{
    if (!CheckUnderflowCondition(start))
    {
        while (start != NULL)
            del_beg();
        printf(COLOR_RED "\n\nAll nodes are DELETED !" COLOR_BLUE);
    }
}

void display()
{
    if (!CheckUnderflowCondition(start))
    {
        struct node *temp = start;
        printf("\nAll nodes of the Linked List:\n");
        int count = 0;
        while (temp != NULL)
        {
            printf("\n%d. %d", count, temp->data);
            temp = temp->next;
            count++;
        }
    }
}

void sort()
{
    if (!CheckUnderflowCondition(start))
    {
        struct node *temp1 = start, *temp2 = temp1;
        while (temp1->next != NULL)
        {
            temp2 = temp1->next;
            while (temp2 != NULL)
            {
                if (temp1->data > temp2->data)
                {
                    int temp = temp1->data;
                    temp1->data = temp2->data;
                    temp2->data = temp;
                }
                temp2 = temp2->next;
            }
            temp1 = temp1->next;
        }
        printf(COLOR_GREEN "\nLinked-List is SORTED !" COLOR_BLUE);
    }
}

bool CheckUnderflowCondition(struct node *temp)
{
    if (temp == NULL)
    {
        printf(COLOR_RED "\nLinked-List is EMPTY !" COLOR_BLUE);
        return true;
    }
    else
        return false;
}

bool CheckIfMemoryAllocated(struct node *temp)
{
    if (temp == NULL)
    {
        printf(COLOR_RED "\nMEMORY ERROR !" COLOR_BLUE);
        return false;
    }
    else
        return true;
}