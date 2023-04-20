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
    int i, j;

    int n = 9;

    Job jobs[9] = {
        {"T1", 15, 7},
        {"T2", 20, 2},
        {"T3", 30, 5},
        {"T4", 18, 3},
        {"T5", 18, 4},
        {"T6", 10, 5},
        {"T7", 23, 2},
        {"T8", 16, 7},
        {"T9", 25, 3}};

    Job temp;

    for (i = 1; i < n; i++)
    {
        for (j = 0; j < n - i; j++)
        {
            if (jobs[j + 1].profit > jobs[j].profit)
            {
                temp = jobs[j + 1];
                jobs[j + 1] = jobs[j];
                jobs[j] = temp;
            }
        }
    }

    printf("%10s %10s %10s\n\n", "Job", "Profit", "Deadline");
    for (i = 0; i < n; i++)
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