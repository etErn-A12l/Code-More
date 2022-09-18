#include <stdio.h>

struct item
{
    int val;
    int prio;
};

struct item pr[1000];

int size = -1;

void enqueue();
int peek();
void dequeue();
void display();

int main(int argc, char const *argv[])
{
    int option,val;
    do
    {
        printf("\n\n~~~~~ MENU ~~~~~");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Peek");
        printf("\n4. Display");
        printf("\n\nEnter your choice: ");
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
            val = peek();
            printf("\nThe top element with highest priority is: %d", pr[val].val);
            break;
        case 4:
            display();
            break;
        default:
            break;
        }
    } while (option < 5);

    return 0;
}

void enqueue()
{
    int val, prio;
    printf("\nEnter the value: ");
    scanf("%d", &val);
    printf("Enter the priority: ");
    scanf("%d", &prio);

    size++;

    pr[size].val = val;
    pr[size].prio = prio;
}

int peek()
{
    int ind = -1, prio = -2147483648;

    for (int i = 0; i <= size; i++)
    {
        if (prio == pr[i].prio && ind > -1 && pr[ind].val < pr[i].val)
        {
            ind = i;
            prio = pr[i].prio;
        }
        else if (prio < pr[i].prio)
        {
            ind = i;
            prio = pr[i].prio;
        }
    }
    return ind;
}

void dequeue()
{
    int ind = peek();
    printf("\n%d was eliminated", pr[ind].val);
    for (int i = ind; i < size; i++)
        pr[i] = pr[i + 1];

    size--;
}

void display()
{
    printf("\nSl No.\tValue\tPriority");
    for (int i = 0; i <= size; i++)
    {
        printf("\n%d.\t%d\t%d", i + 1, pr[i].val, pr[i].prio);
    }
}