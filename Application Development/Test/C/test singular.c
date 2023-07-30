#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *create_list(struct node *start);
struct node *display_list(struct node *start);
// struct node *add_beg(struct node *start);
// struct node *add_end(struct node *start);
// struct node *add_after(struct node *start);
// struct node *add_before(struct node *start);
// struct node *del_beg(struct node *start);
// struct node *del_end(struct node *start);
// struct node *del_node(struct node *start);
// struct node *del_after(struct node *start);
// struct node *del_list(struct node *start);
// struct node *sort(struct node *start);

struct node *start = NULL;

int main(int argc, char const *argv[])
{
    int option;

    do
    {
        printf("\n\n ***** MAIN MENU *****");
        printf("\n 1: Create a list");
        printf("\n 2: Display the list");
        printf("\n 3: Add a node at the beginning");
        printf("\n 4: Add a node at the end");
        printf("\n 5: Add a node after a given node");
        printf("\n 6: Add a node before a given node");
        printf("\n 7: Delete a node from the beginning");
        printf("\n 8: Delete a node from the end");
        printf("\n 9: Delete a given node");
        printf("\n 10: Delete a node after a given node");
        printf("\n 11: Delete the entire list");
        printf("\n 12: Sort the list");
        printf("\n 13: EXIT");

        printf("\n\n Enter your option: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            start = create_list(start);
            break;
        case 2:
            start = display_list(start);
        // case 3:
        //     start = add_beg(start);
        // case 4:
        //     start = add_end(start);
        // case 5:
        //     start = add_after(start);
        // case 6:
        //     start = add_before(start);
        // case 7:
        //     start = del_beg(start);
        // case 8:
        //     start = del_end(start);
        // case 9:
        //     start = del_node(start);
        // case 10:
        //     start = del_after(start);
        // case 11:
        //     start = del_list(start);
        // case 12:
        //     start = sort(start);
        default:
            break;
        }
    } while (option != 13);

    return 0;
}

struct node *create_list(struct node *start)
{
    struct node *new_node, *ptr;
    int data;
    printf("Enter -1 to Exit.");
    printf("\nEnter the data: ");
    scanf("%d", &data);
    while (data != -1)
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = data;
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
        printf("Enter the data: ");
        scanf("%d", &data);
    }
    return start;
}

struct node *display_list(struct node *start)
{
    struct node *ptr;
    ptr = start;
    while (ptr != NULL)
    {
        printf(" %d ->", ptr->data);
        ptr = ptr->next;
    }
    return start;
}
