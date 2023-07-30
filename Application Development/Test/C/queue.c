#include <stdio.h>

#define MAX 10
int queue[MAX];
int front = -1, rear = -1;

void insert();
int delete();
int peek();
void display();

int main(int argc, char const *argv[])
{
    int option, val;
    do
    {
        printf("\n\n ***** MAIN MENU *****");
        printf("\n 1. Insert an element");
        printf("\n 2. Delete an element");
        printf("\n 3. Peek");
        printf("\n 4. Display the queue");
        printf("\n 5. EXIT");
        printf("\n Enter your option: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            insert();
            break;
        case 2:
            val = delete ();
            if (val != -1)
                printf("\n The number deleted is: % d", val);
            break;
        case 3:
            val = peek();
            if (val != -1)
                printf("\n The first value in queue is: % d", val);
            break;
        case 4:
            display();
            break;
        }
    } while (option != 5);

    return 0;
}

void insert()
{
    int data;
    printf("Enter the element: ");
    scanf("%d", &data);
    if (rear = MAX - 1)
        printf("\nQUEUE OVERFLOW");
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = data;
    }
    else
    {
        rear++;
        queue[rear] = data;
    }
}

int delete()
{
    if(front = -1 || front > rear)
    {
        
    }
}
