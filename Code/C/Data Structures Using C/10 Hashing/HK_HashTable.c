#include <stdio.h>
#include <stdlib.h>

#define size 10

int hashtable[size] = {0};

void insert()
{
    int key, h_index, i, h_inn;
    printf("\nEnter your key :");
    scanf("%d", &key);
    h_inn = key % size;
    for (int i = 0; i < size; i++)
    {
        h_index = (h_inn + i) % size;
        if (hashtable[h_index] == 0)
        {
            hashtable[h_index] = key;
            break;
        }
    }
    if (i == size)
    {
        printf("No size left");
    }
}

void search()
{
    int key, h_index, i, h_inn;
    printf("\nEnter your key :");
    scanf("%d", &key);
    h_inn = key % size;
    for (int i = 0; i < size; i++)
    {
        h_index = (h_inn + i) % size;
        if (hashtable[h_index] == key)
        {
            printf("Key found\n");
            break;
        }
        if (i == size)
        {
            printf("Key Not Found \n");
        }
    }
}

void Display()
{
    printf("\nThe  HashTable is :");
    for (int i = 0; i < size; i++)
    {
        printf("Hash Index %d is %d ", i, hashtable[i]);
        printf("\n");
    }
}

int main()
{
    int op = 0;
    while (op < 4)
    {
        printf("\n1. insert\n2. search\n3. Display\n");
        printf("Enter your option : ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            insert();
            break;
        case 2:
            search();
            break;
        case 3:
            Display();
            break;
        default:
            printf("\nWrong option");
        }
    }

    return 0;
}