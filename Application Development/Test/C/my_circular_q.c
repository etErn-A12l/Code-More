#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 3
int queue[MAX];
int front = -1, rear = -1;

void enqueue(void);
void dequeue(void);
void peek(void);
void display(void);
bool checkUnderflow(int front, int rear);
bool checkOverflow(int front, int rear);

int main()
{
    int option;
    system("cls");
    do
    {
        printf("\n\n ***** MAIN MENU *****");
        printf("\n 1. Insert an element");
        printf("\n 2. Delete an element");
        printf("\n 3. Peek");
        printf("\n 4. Display the queue");
        printf("\n 5. EXIT");
        printf("\n\n Enter your option : ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        default:
            printf("\nWrong Choice !");
            break;
        }

    } while (option < 5);

    return 0;
}

void enqueue()
{
    if (!checkOverflow(front, rear))
    {
        int val;
        printf("\nEnter the element: ");
        scanf("%d", &val);
        if (front == -1 && rear == -1)
            front = rear = 0;
        else if (front != 0 && rear == MAX - 1)
            rear = 0;
        else
            rear++;
        queue[rear] = val;
        printf("\n%d is Inserted !", val);
    }
}

void dequeue()
{
    if (!checkUnderflow(front, rear))
    {
        printf("\n%d is Deleted !", queue[front]);
        if (front == rear)
            front = rear = -1;
        else
        {
            if (front == MAX - 1)
                front = 0;
            else
                front++;
        }
    }
}

void display()
{
    if (!checkUnderflow(front, rear))
    {
        printf("\nElements of the Queue: \n");
        if (front < rear)
        {
            for (int i = front; i <= rear; i++)
                printf("\t%d", queue[i]);
        }
        else
        {
            for (int i = front; i < MAX; i++)
                printf("\t%d", queue[i]);
            for (int i = 0; i <= rear; i++)
                printf("\t%d", queue[i]);
        }
    }
}

void peek()
{
    if (!checkUnderflow(front, rear))
    {
        printf("\nTop element is %d", queue[front]);
    }
}

bool checkUnderflow(int front, int rear)
{
    if (front == -1 && rear == -1)
    {
        printf("\nQUEUE UNDERFLOW !");
        return true;
    }
    else
        return false;
}

bool checkOverflow(int front, int rear)
{
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
    {
        printf("\nQUEUE OVERFLOW !");
        return true;
    }
    else
        return false;
}
