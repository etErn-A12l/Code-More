#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *start;

void delete_end();
void insert_at_beg();
void insert_at_end();
void insert_at_pos();
void display();
void delete_beg();
void delete_pos();
void delete_list();
void search();
void count();
void reverse();
int CheckUnderflow(struct node *);

int main(int argc, char const *argv[])
{
    int option;
    system("cls");
    do
    {
        printf("\n\n\t***** MENU *****");
        printf("\n1.  Insert Element at Beginning");
        printf("\n2.  Insert Element at End");
        printf("\n3.  Insert Element at Given Position");
        printf("\n4.  Delete First Element");
        printf("\n5.  Delete Last Element");
        printf("\n6.  Delete element from a given Position");
        printf("\n7.  Search an element");
        printf("\n8.  Count the total numbers of element");
        printf("\n9.  Reverse the Linked_List");
        printf("\n10. Delete the Entire List");
        printf("\n11. Display Elements");
        printf("\n\nEnter your choice: ");
        scanf("%d", &option);

        system("cls");

        switch (option)
        {
        case 1:
            insert_at_beg();
            break;
        case 2:
            insert_at_end();
            break;
        case 3:
            insert_at_pos();
            break;
        case 4:
            delete_beg();
            break;
        case 5:
            delete_end();
            break;
        case 6:
            delete_pos();
            break;
        case 7:
            search();
            break;
        case 8:
            count();
            break;
        case 9:
            reverse();
            break;
        case 10:
            delete_list();
            break;
        case 11:
            display();
            break;
        default:
            printf("\nWrong Choice !");
            break;
        }
    } while (option < 12);

    return 0;
}

void insert_at_beg()
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("\nMEMORY ERROR !");
        return;
    }
    printf("\nEnter the data for node: ");
    scanf("%d", &ptr->data);
    if (start == NULL)
    {
        start = ptr;
        ptr->next = NULL;
    }
    else
    {
        ptr->next = start;
        start = ptr;
    }
    printf("\n%d was inserted !", ptr->data);
}

void insert_at_end()
{
    if (start == NULL)
    {
        insert_at_beg();
        return;
    }
    struct node *temp, *ptr = start;
    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("\nMEMORY ERROR !");
        return;
    }
    printf("\nEnter the data for node: ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = temp;
    printf("\n%d was inserted !", temp->data);
}

void insert_at_pos()
{
    int pos;
    printf("\nEnter the Position: ");
    scanf("%d", &pos);
    if (start == NULL || pos == 0)
    {
        insert_at_beg();
        return;
    }
    struct node *ptr = start;
    for (int i = 0; i < pos - 1; i++)
    {
        ptr = ptr->next;
        if (ptr == NULL)
        {
            printf("\nPosition NOT FOUND !");
            return;
        }
    }
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("\nMEMORY ERROR !");
        return;
    }
    printf("\nEnter the data: ");
    scanf("%d", &temp->data);
    temp->next = ptr->next;
    ptr->next = temp;
    printf("\n%d was inserted !", temp->data);
}

void delete_end()
{
    if (CheckUnderflow(start))
        return;

    struct node *ptr = start;

    if (start->next == NULL)
    {
        start = NULL;
        free(ptr);
        printf("\nThe only element was deleted !");
    }
    else
    {
        while (ptr->next->next != NULL)
        {
            ptr = ptr->next;
        }
        printf("\nThe %d was deleted !", ptr->next->data);
        free(ptr->next);
        ptr->next = NULL;
    }
}

void delete_beg()
{
    if (CheckUnderflow(start))
        return;
    struct node *ptr = start;
    start = start->next;
    printf("\n%d Was deleted !", ptr->data);
    free(ptr);
}

void display()
{
    struct node *ptr = start;
    if (CheckUnderflow(start))
        return;
    printf("\nHere is your Linked List: \n\n\t");
    while (ptr->next != NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("%d", ptr->data);
}

void delete_pos()
{
    if (CheckUnderflow(start))
        return;

    struct node *ptr = start, *preptr;
    int pos;
    printf("\nEnter the position: ");
    scanf("%d", &pos);
    for (int i = 1; i < pos; i++)
    {
        preptr = ptr;
        ptr = ptr->next;
        if (ptr == NULL)
        {
            printf("\nPosition NOT FOUND !");
            return;
        }
    }
    printf("\n%d was deleted !", ptr->data);
    preptr->next = ptr->next;
    free(ptr);
}

void delete_list()
{
    if (CheckUnderflow(start))
        return;

    struct node *ptr;
    while (start != NULL)
    {
        delete_beg();
    }
    printf("\n\nEntire linked-List was DELETED !");
}

void search()
{
    if (CheckUnderflow(start))
        return;

    struct node *ptr = start;
    int data, count = 1;
    printf("\nEnter the element that you want to find: ");
    scanf("%d", &data);
    while (ptr != NULL)
    {
        if (ptr->data == data)
        {
            printf("\n%d was found on position %d !", data, count);
            return;
        }
        ptr = ptr->next;
        count++;
    }
    printf("\n%d was NOT FOUND !", data);
}

void count()
{
    if (CheckUnderflow(start))
        return;

    int count = 0;
    struct node *ptr = start;
    while (ptr != NULL)
    {
        ptr = ptr->next;
        count++;
    }
    printf("\nTotal Element is %d", count);
}

void reverse()
{
    if (CheckUnderflow(start))
        return;
    struct node *p1, *p2, *p3;
    p1 = start;
    p2 = p1->next;
    p3 = p2->next;
    p1->next = NULL;
    p2->next = p1;
    while (p3 != NULL)
    {
        p1 = p2;
        p2 = p3;
        p3 = p3->next;
        p2->next = p1;
    }
    start = p2;
    printf("\nLinked-List Reversed Successfully !\n");
}

int CheckUnderflow(struct node *start)
{
    if (start == NULL)
    {
        printf("\nLIST IS EMPTY !");
        return 1;
    }
    else
        return 0;
}