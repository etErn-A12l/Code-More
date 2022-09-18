#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
} * last;

void create_list(int num);
void display();
void addatbeg(int num);
void addafter(int num, int pos);
void del(int num);

int main(int argc, char const *argv[])
{
    int choice, n, m, o, p, i;
    last = NULL;

    while (1)
    {
        printf("\n\n ***** MENU *****");
        printf("\n1. Create List");
        printf("\n2. Add at beg");
        printf("\n3. Add after");
        printf("\n4. Delete");
        printf("\n5. Display");
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("How many nodes do you want: ");
            scanf("%d", &n);
            for (i = 0; i < n; i++)
            {
                printf("\nEnter the element: ");
                scanf("%d", &m);
                create_list(m);
            }
            break;
        case 2:
            printf("\nEnter the element: ");
            scanf("%d", &m);
            addatbeg(m);
            break;
        case 3:
            printf("\nEnter the element: ");
            scanf("%d", &m);
            printf("\nEnter the position after which the element is inserted: ");
            scanf("%d", &p);
            break;
        case 4:
            if (last == NULL)
            {
                printf("\nList UNDERFLOW !");
                continue;
            }
            printf("Enter the number for deletion: ");
            scanf("%d", &m);
            del(m);
            break;
        case 5:
            display();
            break;
        default:
            printf("\nWrong Choice !");
            break;
        }
    }
    return 0;
}

void create_list(int num)
{
    struct node *q, *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->info = num;
    if (last == NULL)
    {
        last = temp;
        temp->next = last;
    }
    else
    {
        temp->next = last->next;
        last->next = temp;
        last = temp;
    }
}

void display()
{
    struct node *q;
    if (last == NULL)
    {
        printf("\nList is empty !");
        return;
    }
    q = last;
    printf("List is: \n");
    while (q != last)
    {
        printf("%d\t", q->info);
        q = q->next;
    }
    printf("%d\t", q->info);
}

void addatbeg(int num)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->info = num;
    temp->next = last->next;
    last->next = temp;
}

void addafter(int num, int po)
{
    struct node *q, *tmp;
    int i;
    q = last->next;
    for (i = 0; i < po - 1; i++)
    {
        q = q->next;
        if (q == last->next)
        {
            printf("\nThere are less than %d elements", po);
            return;
        }
    }
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->next = q->next;
    tmp->info = num;
    q->next = tmp;
    if (q == last) // Element inserted at the end
        last = tmp;
}

void del(int num)
{
    struct node *tmp, *q;
    if (last->next == last && last->info == num)
    {
        tmp = last;
        last = NULL;
        free(tmp);
        return;
    }
    q = last->next;
    if (q->info == num)
    {
        tmp = q;
        last->next = q->next;
        free(tmp);
        return;
    }
    while (q->next != last)
    {
        if (q->next->info == num)
        {
            tmp = q->next;
            q->next = tmp->next;
            free(tmp);
            printf("%d deleted\n", num);
            return;
        }
        q = q->next;
    }
    if (q->next->info == num)
    {
        tmp = q->next;
        q->next = last->next;
        free(tmp);
        last = q;
        return;
    }
    printf("\nElement %d not found", num);
}
