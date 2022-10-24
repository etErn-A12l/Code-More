#include <stdio.h>
#include <stdlib.h>

#define MAX 5

struct node
{
    int data;
    struct node *next;
};

struct node *table[5] = {NULL};

void insert(struct node *table[]);
void search(struct node *table[]);
void delete (struct node *table[]);
int hash_function(int key);
void display(struct node *table[]);

int main(int argc, char const *argv[])
{
    int option;
    system("cls");
    do
    {
        printf("\n\n**** MENU ****");
        printf("\n1. Insert");
        printf("\n2. Search");
        printf("\n3. Delete");
        printf("\n4. Display");
        printf("\n\nEnter you choice: ");
        scanf("%d", &option);
        system("cls");

        if (option == 1)
            insert(table);
        else if (option == 2)
            search(table);
        else if (option == 3)
            delete (table);
        else if (option == 4)
            display(table);
        else
            printf("\nWrong Option !");

    } while (option < 5);

    return 0;
}

void insert(struct node *table[])
{
    int key;
    printf("\nEnter the key to insert: ");
    scanf("%d", &key);
    int hash_index = hash_function(key);

    // Inserting the node
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = key;
    ptr->next = NULL;
    if (table[hash_index] == NULL)
        table[hash_index] = ptr;
    else
    {
        ptr->next = table[hash_index];
        table[hash_index] = ptr;
    }
}

void search(struct node *table[])
{
    int key;
    printf("\nEnter the key to search: ");
    scanf("%d", &key);
    int hash_index = hash_function(key);

    // Traversing through the linked-list
    struct node *ptr = table[hash_index];
    int counter = 0, flag = 0;
    while (ptr != NULL)
    {
        if (ptr->data == key)
        {
            printf("\nKey was found at index %d and %dth position", hash_index, counter + 1);
            flag = 1;
            break;
        }
        else
            ptr = ptr->next;
        counter++;
    }

    if (flag == 0)
        printf("\nThe key was NOT FOUND !");
}

void delete (struct node *table[])
{
    int key;
    printf("\nEnter the key to delete: ");
    scanf("%d", &key);
    int hash_index = hash_function(key);

    // Traversing through the linked-list
    int flag = 0;
    struct node *ptr = table[hash_index], *preptr;
    // if key is at first node 
    if (ptr->data == key)
    {
        flag = 1;
        table[hash_index] = table[hash_index]->next;
        free(ptr);
    }
    // else
    else
    {
        while (ptr->data != key)
        {
            preptr = ptr;
            ptr = ptr->next;
            if (ptr->data == key)
                flag = 1;
        }
        preptr->next = ptr->next;
        free(ptr);
    }
    if (flag == 1)
        printf("\n%d was deleted !", key);
    else
        printf("\nThe key was NOT FOUND !");
}

void display(struct node *table[])
{
    printf("\nBelow is the Chained Hash Table\n");
    for (int i = 0; i < MAX; i++)
    {
        printf("\n[%d] ", i);

        if (table[i] != NULL)
        {
            struct node *ptr = table[i];
            while (ptr != NULL)
            {
                printf(" --> %d", ptr->data);
                ptr = ptr->next;
            }
        }
    }
}

int hash_function(int key)
{
    return key % MAX;
}