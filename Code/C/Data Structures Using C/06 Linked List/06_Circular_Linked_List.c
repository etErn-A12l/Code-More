#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *start = NULL;

struct node *create_cll(struct node *);
struct node *display(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_after(struct node *);
struct node *delete_list(struct node *);
struct node *search(struct node *);
struct node *del(struct node *);

int main()
{
    int option;

    do
    {
        printf("\n\n ***** MAIN MENU *****");
        printf("\n 1: Create a list");
        printf("\n 2: Display the list");
        printf("\n 3: Add a node at the beginning");
        printf("\n 4: Add a node at the end");
        printf("\n 5: Delete a node from the beginning");
        printf("\n 6: Delete a node from the end");
        printf("\n 7: Delete a node after a given node");
        printf("\n 8: Delete the entire list");
        printf("\n 9: Search a Node");
        printf("\n 10: Delete a node");
        printf("\n 11: EXIT");

        printf("\n\n Enter your option : ");
        scanf("%d", &option);
        system("cls");

        switch (option)
        {
        case 1:
            start = create_cll(start);
            printf("\n CIRCULAR LINKED LIST CREATED");
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
            start = delete_beg(start);
            break;
        case 6:
            start = delete_end(start);
            break;
        case 7:
            start = delete_after(start);
            break;
        case 8:
            start = delete_list(start);
            printf("\n CIRCULAR LINKED LIST DELETED");
            break;
        case 9:
            start = search(start);
            break;
        case 10:
            start = del(start);
            break;
        default:
            break;
        }
    } while (option != 11);

    return 0;
}

struct node *create_cll(struct node *start)
{
    struct node *new_node, *ptr;
    int num;
    printf("\n Enter -1 to end");
    printf("\n Enter the data : ");
    scanf("%d", &num);
    while (num != -1)
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = num;
        if (start == NULL)
        {
            new_node->next = new_node;
            start = new_node;
        }
        else
        {
            ptr = start;
            while (ptr->next != start)
                ptr = ptr->next;
            ptr->next = new_node;
            new_node->next = start;
        }
        printf("\n Enter the data : ");
        scanf("%d", &num);
    }
    return start;
}

struct node *display(struct node *start)
{
    struct node *ptr;
    ptr = start;
    if (start == NULL)
    {
        printf("\nLinked List is EMPTY !");
        return start;
    }
    else
    {
        while (ptr->next != start)
        {
            printf("\t %d", ptr->data);
            ptr = ptr->next;
        }
        printf("\t %d", ptr->data);
        return start;
    }
}

struct node *insert_beg(struct node *start)
{
    struct node *new_node, *ptr;
    int num;
    printf("\n Enter the data : ");
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    ptr = start;
    while (ptr->next != start)
        ptr = ptr->next;
    ptr->next = new_node;
    new_node->next = start;
    start = new_node;
    return start;
}

struct node *insert_end(struct node *start)
{
    struct node *ptr, *new_node;
    int num;
    printf("\n Enter the data : ");
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    ptr = start;
    while (ptr->next != start)
        ptr = ptr->next;
    ptr->next = new_node;
    new_node->next = start;
    return start;
}

struct node *delete_beg(struct node *start)
{
    struct node *ptr;
    ptr = start;
    while (ptr->next != start)
        ptr = ptr->next;
    ptr->next = start->next;
    free(start);
    start = ptr->next;
    return start;
}

// struct node *delete_end(struct node *start)
// {
//     struct node *ptr, *preptr;
//     ptr = start;
//     while (ptr->next != start)
//     {
//         preptr = ptr;
//         ptr = ptr->next;
//     }
//     preptr->next = ptr->next;
//     free(ptr);
//     return start;
// }

struct node *delete_end(struct node *start) // My own modified function
{
    struct node *ptr;
    ptr = start;
    while (ptr->next->next != start)
    {
        ptr = ptr->next;
    }
    free(ptr->next);
    if (ptr->next == NULL)
        printf("\nDONE Bro :)");
    ptr->next = start;
    return start;
}

struct node *delete_after(struct node *start)
{
    struct node *ptr, *preptr;
    int val;
    printf("\n Enter the value after which the node has to deleted : ");
    scanf("%d", &val);
    ptr = start;
    preptr = ptr;
    while (preptr->data != val)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = ptr->next;
    if (ptr == start)
        start = preptr->next;
    free(ptr);
    return start;
}

struct node *delete_list(struct node *start)
{
    struct node *ptr;
    ptr = start;
    while (ptr->next != start)
        start = delete_end(start);
    free(start);
    return start;
}

struct node *search(struct node *start)
{
    struct node *temp = start;
    int num;
    if (start == NULL)
    {
        printf("\nLinked List EMPTY !");
    }
    printf("\nEnter the data to find: ");
    scanf("%d", &num);
    while (temp->next != start)
    {
        if (temp->data == num)
        {
            printf("\nThe number is present !");
            break;
        }
        temp = temp->next;
    }
    return start;
}

struct node *del(struct node *start)
{
    struct node *temp = start, *preptr;
    if (start == NULL)
    {
        printf("\nLinked List is EMPTY !");
        return start;
    }
    int num;
    printf("\nEnter the data you want to find: ");
    scanf("%d", &num);
    do
    {
        preptr = temp;
        temp = temp->next;
        if (temp->data == num)
        {
            if (temp == start)
            {
                preptr->next = temp->next;
                start = preptr->next;
                printf("\n%d was deleted !", temp->data);
                free(temp);
                break;
            }
            else
            {
                preptr->next = temp->next;
                printf("\n%d was deleted !", temp->data);
                free(temp);
                break;
            }
        }
        temp = temp->next;
    } while (temp != start);
    return start;
}