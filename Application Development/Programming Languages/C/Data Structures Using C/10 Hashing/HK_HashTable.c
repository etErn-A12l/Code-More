#include <stdio.h>
#include <stdlib.h>

#define size 10

int hashtable[size] = {0};

void insert()
{
    int key, h_index, i, h_inn;
    printf("\nEnter your key: ");
    scanf("%d", &key);
    h_inn = key % size;
    for (i = 0; i < size; i++)
    {
        h_index = (h_inn + i) % size;
        if (hashtable[h_index] == 0)
        {
            hashtable[h_index] = key;
            break;
        }
    }
    if (i == size)
        printf("\nNO SPACE left");

}

void search()
{
    int key, h_index, i, h_inn;
    printf("\nEnter your key: ");
    scanf("%d", &key);
    h_inn = key % size;
    for (i = 0; i < size; i++)
    {
        h_index = (h_inn + i) % size;
        if (hashtable[h_index] == key)
        {
            printf("Key Found at index %d\n", h_index);
            break;
        }
    }
    if (i == size)
        printf("Key Not Found \n");
}

void Display()
{
    printf("\nThe HashTable is :\n");
    for (int i = 0; i < size; i++)
    {
        printf("\nHash Index %d is %d", i, hashtable[i]);
    }
}

int main()
{
    int op = 0;
    system("cls");
    while (op < 4)
    {
        printf("\n\n1. Insert\n2. Search\n3. Display\n");
        printf("\nEnter your option : ");
        scanf("%d", &op);
        system("cls");
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