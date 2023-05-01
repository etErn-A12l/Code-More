#include <stdio.h>
#define MAX 100

typedef struct Job
{
    char id[5];
    int profit;
    int deadline;
} Job;

void jobSequenceDeadline(Job jobs[], int n);

int minValue(int x, int y)
{
    return x < y ? x : y;
}

int main()
{
    int n;
    printf("\nEnter the number of Jobs: ");
    scanf("%d", &n);

    Job jobs[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter %dth Job's Name: ", i + 1);
        scanf("%s", &jobs[i].id);
        printf("Enter %dth Job's Profit: ", i + 1);
        scanf("%d", &jobs[i].profit);
        printf("Enter %dth Job's Deadline: ", i + 1);
        scanf("%d", &jobs[i].deadline);
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (jobs[j + 1].profit > jobs[j].profit)
            {
                Job temp = jobs[j + 1];
                jobs[j + 1] = jobs[j];
                jobs[j] = temp;
            }
        }
    }

    printf("%10s %10s %10s\n\n", "Job", "Profit", "Deadline");
    for (int i = 0; i < n; i++)
        printf("%10s %10i %10i\n", jobs[i].id, jobs[i].profit, jobs[i].deadline);

    jobSequenceDeadline(jobs, n);

    return 0;
}

void jobSequenceDeadline(Job jobs[], int n)
{
    int i, j, k;

    int filledSlot = 0;

    int dmax = 0;

    for (i = 0; i < n; i++)
        dmax = (jobs[i].deadline > dmax) ? jobs[i].deadline : dmax;

    int timeslot[dmax];

    for (i = 1; i <= dmax; i++)
        timeslot[i] = -1;

    printf("\nDMAX: %d\n", dmax);

    for (i = 1; i <= n; i++)
    {
        k = minValue(dmax, jobs[i].deadline);
        while (k >= 1)
        {
            if (timeslot[k] == -1)
            {
                timeslot[k] = i;
                filledSlot++;
                break;
            }
            k--;
        }
        if (filledSlot == dmax)
            break;
    }

    printf("\nRequired Jobs: ");

    for (i = 1; i <= dmax; i++)
    {
        printf(" %s ", jobs[timeslot[i]].id);
        if (i < dmax)
            printf("-->");
    }

    int maxProfit = 0;

    for (i = 1; i <= dmax; i++)
        maxProfit += jobs[timeslot[i]].profit;

    printf("\n\nMax Profit: %d\n", maxProfit);
}