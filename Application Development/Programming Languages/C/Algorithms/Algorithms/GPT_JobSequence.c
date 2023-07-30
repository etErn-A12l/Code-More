#include <stdio.h>
#include <stdlib.h>

// Define a Job structure
typedef struct
{
    int id;
    int deadline;
    int profit;
} Job;

// Function prototypes
void sortJobsByProfit(Job jobs[], int n);
int findMaxDeadline(Job jobs[], int n);
void jobSequencing(Job jobs[], int n);

int main()
{
    int n, i;

    printf("Enter the number of jobs: ");
    scanf("%d", &n);

    Job jobs[n];
    for (i = 0; i < n; i++)
    {
        printf("Enter job ID, deadline, and profit for job %d: ", i + 1);
        scanf("%d %d %d", &jobs[i].id, &jobs[i].deadline, &jobs[i].profit);
    }

    jobSequencing(jobs, n);

    return 0;
}

// Function to sort jobs based on their profits in non-increasing order
void sortJobsByProfit(Job jobs[], int n)
{
    int i, j;
    Job temp;

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (jobs[i].profit < jobs[j].profit)
            {
                temp = jobs[i];
                jobs[i] = jobs[j];
                jobs[j] = temp;
            }
        }
    }
}

// Function to find the maximum deadline among all jobs
int findMaxDeadline(Job jobs[], int n)
{
    int max = 0, i;

    for (i = 0; i < n; i++)
    {
        if (jobs[i].deadline > max)
        {
            max = jobs[i].deadline;
        }
    }

    return max;
}

// Function to perform job sequencing using the Greedy technique
void jobSequencing(Job jobs[], int n)
{
    sortJobsByProfit(jobs, n);

    int maxDeadline = findMaxDeadline(jobs, n);
    int timeSlot[maxDeadline + 1];

    for (int i = 0; i <= maxDeadline; i++)
        timeSlot[i] = -1; // Initialize all time slots as '-1'
    

    int totalProfit = 0;

    for (int i = 0; i < n; i++)
    {
        int j = jobs[i].deadline;

        while (j > 0)
        {
            if (timeSlot[j] == -1)
            {
                timeSlot[j] = i;
                totalProfit += jobs[i].profit;
                break;
            }
            j--;
        }
    }

    printf("Selected jobs: ");
    for (int i = 1; i <= maxDeadline; i++)
    {
        if (timeSlot[i] != -1)
        {
            printf("%d ", jobs[timeSlot[i]].id);
        }
    }

    printf("\nTotal profit: %d\n", totalProfit);
}
