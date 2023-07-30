// Write a program to create a linked list and perform insertions and deletions of all cases.
// Write functions to sort and finally delete the entire list at once.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *start = NULL;

struct node *create_ll(struct node *);
struct node *display(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *insert_before(struct node *);
struct node *insert_after(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_node(struct node *);
struct node *delete_after(struct node *);
struct node *delete_list(struct node *);
struct node *sort_list(struct node *);
void search(struct node *);
void count(struct node *);
struct node *reverse(struct node *);
int CheckUnderflow(struct node *);

int main(int argc, char *argv[])
{
    int option;
    system("cls");
    do
    {
        printf("\n\n ***** MAIN MENU *****\n");
        printf("\n\t(1)   Create a list");
        printf("\n\t(2)   Display the list");
        printf("\n\t(3)   Add a node at the beginning");
        printf("\n\t(4)   Add a node at the end");
        printf("\n\t(5)   Add a node before a given node");
        printf("\n\t(6)   Add a node after a given node");
        printf("\n\t(7)   Delete a node from the beginning");
        printf("\n\t(8)   Delete a node from the end");
        printf("\n\t(9)   Delete a given node");
        printf("\n\t(10)  Delete a node after a given node");
        printf("\n\t(11)  Delete the entire list");
        printf("\n\t(12)  Sort the list");
        printf("\n\t(13)  Search for an element");
        printf("\n\t(14)  Count total nodes");
        printf("\n\t(15)  Reverse the list");
        printf("\n\t(16)  EXIT");

        printf("\n\n Enter your option: ");
        scanf("%d", &option);

        system("cls");

        switch (option)
        {
        case 1:
            start = create_ll(start);
            printf("\n LINKED LIST CREATED");
            break;
        case 2:
            start = display(start);
            break;
        case 3:
            start = insert_beg(start);
            break;
        case 4:
            start = insert_end(start);
            break;
        case 5:
            start = insert_before(start);
            break;
        case 6:
            start = insert_after(start);
            break;
        case 7:
            start = delete_beg(start);
            break;
        case 8:
            start = delete_end(start);
            break;
        case 9:
            start = delete_node(start);
            break;
        case 10:
            start = delete_after(start);
            break;
        case 11:
            start = delete_list(start);
            printf("\n LINKED LIST DELETED");
            break;
        case 12:
            start = sort_list(start);
            break;
        case 13:
            search(start);
            break;
        case 14:
            count(start);
            break;
        case 15:
            start = reverse(start);
            break;
        }
    } while (option < 16);

    return 0;
}

struct node *create_ll(struct node *start)
{
    struct node *new_node, *ptr;
    int num;
    printf("\n Enter - 1 to end");
    printf("\n Enter the data: ");
    scanf("%d", &num);
    while (num != -1)
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = num;
        if (start == NULL)
        {
            new_node->next = NULL;
            start = new_node;
        }
        else
        {
            ptr = start;
            while (ptr->next != NULL)
                ptr = ptr->next;
            ptr->next = new_node;
            new_node->next = NULL;
        }
        printf("\n Enter the data: ");
        scanf("%d", &num);
    }
    return start;
}

struct node *display(struct node *start)
{
    if (CheckUnderflow(start))
        return start;
    struct node *ptr;
    ptr = start;
    while (ptr != NULL)
    {
        printf("\t %d", ptr->data);
        ptr = ptr->next;
    }
    return start;
}

struct node *insert_beg(struct node *start)
{
    struct node *new_node;
    int num;
    printf("\n Enter the data: ");
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    new_node->next = start;
    start = new_node;
    return start;
}

struct node *insert_end(struct node *start)
{
    struct node *ptr, *new_node;
    int num;
    printf("\n Enter the data: ");
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    new_node->next = NULL;
    ptr = start;
    while (ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = new_node;
    return start;
}

struct node *insert_before(struct node *start)
{
    struct node *new_node, *ptr, *preptr;
    int num, val;
    printf("\n Enter the data: ");
    scanf("%d", &num);
    printf("\n Enter the value before which the data has to be inserted: ");
    scanf("%d", &val);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    ptr = start;
    while (ptr->data != val)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = new_node;
    new_node->next = ptr;
    return start;
}

struct node *insert_after(struct node *start)
{
    struct node *new_node, *ptr, *preptr;
    int num, val;
    printf("\n Enter the data: ");
    scanf("%d", &num);
    printf("\n Enter the value after which the data has to be inserted: ");
    scanf("%d", &val);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    ptr = start;
    preptr = ptr;
    while (preptr->data != val)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = new_node;
    new_node->next = ptr;
    return start;
}

struct node *delete_beg(struct node *start)
{
    if (CheckUnderflow(start))
        return start;
    struct node *ptr;
    ptr = start;
    start = start->next;
    free(ptr);
    return start;
}

struct node *delete_end(struct node *start)
{
    if (CheckUnderflow(start))
        return start;
    struct node *ptr, *preptr;
    ptr = start;
    while (ptr->next != NULL)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = NULL;
    free(ptr);
    return start;
}

struct node *delete_node(struct node *start)
{
    if (CheckUnderflow(start))
        return start;
    struct node *ptr, *preptr;
    int val;
    printf("\n Enter the value of the node which has to be deleted: ");
    scanf("%d", &val);
    ptr = start;
    if (ptr->data == val)
    {
        start = delete_beg(start);
        return start;
    }
    else
    {
        while (ptr->data != val)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = ptr->next;
        free(ptr);
        return start;
    }
}

struct node *delete_after(struct node *start)
{
    if (CheckUnderflow(start))
        return start;
    struct node *ptr, *preptr;
    int val;
    printf("\n Enter the value after which the node has to deleted: ");
    scanf("%d", &val);
    ptr = start;
    preptr = ptr;
    while (preptr->data != val)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = ptr->next;
    free(ptr);
    return start;
}

struct node *delete_list(struct node *start)
{
    if (CheckUnderflow(start))
        return start;
    struct node *ptr;
    // Lines 252-254 were modified from original code to fix unresposiveness in output window

    ptr = start;
    while (ptr != NULL)
    {
        printf("\n %d is to be deleted next", ptr->data);
        start = delete_beg(ptr);
        ptr = start;
    }

    return start;
}

struct node *sort_list(struct node *start)
{
    if (CheckUnderflow(start))
        return start;
    struct node *ptr1, *ptr2;
    int temp;
    ptr1 = start;
    while (ptr1->next != NULL)
    {
        ptr2 = ptr1->next;
        while (ptr2 != NULL)
        {
            if (ptr1->data > ptr2->data)
            {
                temp = ptr1->data;
                ptr1->data = ptr2->data;
                ptr2->data = temp;
            }
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
    return start; // Had to be added
}

void search(struct node *start)
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

void count(struct node *start)
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

struct node *reverse(struct node *start)
{
    if (CheckUnderflow(start))
        return start;
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
    return start;
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