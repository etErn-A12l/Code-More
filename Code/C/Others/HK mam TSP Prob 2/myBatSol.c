#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define POP_NO 30      // 44-43       // number of bats
#define DIM 2          // number of dimensions
#define ITERATIONS 1000 // number of iterations

struct bat
{
    float pos[DIM], pulse, vel[DIM], loud, freq;
    double fit;
};

void Initiate(struct bat bats[]);
void calFitness(struct bat bats[]);
short bestFitness(struct bat bats[]);
void adjustFreq(struct bat bats[], struct bat nBats[]);
void updtVel(struct bat bats[], struct bat nBats[], short Index);
void updtPos(struct bat bats[], struct bat nBats[]);
void genLclSol(struct bat bats[], short index);
void updateLoudPulse(struct bat bats[], int Iteration);

int main(int argc, char const *argv[])
{
    struct bat x[POP_NO];
    srand(0); // seedind with the value of current time

    // Generate random frequencies and loud
    float A = (float)rand() / (float)RAND_MAX;

    short Itr = 0, bestGen = 0;

    Initiate(x);
    calFitness(x);

    short bst_IDX = bestFitness(x);
    double gBstFit;
    gBstFit = x[bst_IDX].fit; // Best fit in solutions

    // =================================

    while (Itr++ < ITERATIONS)
    {
        struct bat y[POP_NO]; // New Solutions

        printf("\n\n\n\t\t======= ITERATION: %hu FITNESS =======\n\n\n", Itr);
        for (short i = 0; i < POP_NO; i++)
            printf("\n  BAT %hu : \t%.3lf  ", i + 1, 1000 - x[i].fit);

        printf("\n\n  Best Fitness : %.3lf  From BAT %hu\n", 1000 - x[bst_IDX].fit, bst_IDX + 1);

        adjustFreq(x, y);
        updtVel(x, y, bst_IDX);
        updtPos(x, y);

        calFitness(y);

        for (short i = 0; i < POP_NO; i++)
        {
            float r = (float)rand() / (float)(RAND_MAX);

            if (x[i].pulse > r)
                // Generating new local solutions
                genLclSol(x, i);

            if (r < x[i].loud && y[i].fit < x[i].fit)
                // reduce loud and increase puse rate
                updateLoudPulse(x, Itr);
        }

        // ==== RANKING THE NEW SOLUTIONS ====

        for (short i = 0; i < POP_NO; i++)
        {
            if (y[i].fit < x[i].fit) // Conditionally accept New Solution
            {
                x[i].fit = y[i].fit;
                x[i].freq = y[i].freq;
                for (short j = 0; j < DIM; j++)
                {
                    x[i].pos[j] = y[i].pos[j];
                    x[i].vel[j] = y[i].vel[j];
                }
            }
        }

        bst_IDX = bestFitness(x);

        if (x[bst_IDX].fit < gBstFit)
        {
            gBstFit = x[bst_IDX].fit;
            bestGen = Itr;
        }
    }

    printf("\n\nBEST FIT WAS FOUND AT %hu ITERATION WITH %lf FITNESS !\n\n", bestGen + 1, gBstFit);

    return 0;
}

void Initiate(struct bat bats[])
{
    // Assigning random values
    for (short i = 0; i < POP_NO; i++)
    {
        for (short j = 0; j < DIM; j++)
        {
            bats[i].vel[j] = (float)rand() / (float)(RAND_MAX);
            // bats[i].pos[j] = ((float)rand() / (float)(RAND_MAX)) * (5.12 - (-5.12)) + (-5.12);
        }
        bats[i].pos[0] = ((float)rand() / (float)(RAND_MAX)) * (12.1 - (4.12)) + (4.12);
        bats[i].pos[1] = ((float)rand() / (float)(RAND_MAX)) * (7.12 - (4.12)) + (4.12);

        // bats[i].pos[0] = ((float)rand() / (float)(RAND_MAX)) * (12.1 - (3.0)) + (3.0);
        // bats[i].pos[1] = ((float)rand() / (float)(RAND_MAX)) * (5.8 - (4.1)) + (4.1);

        bats[i].pulse = ((float)rand() / (float)(RAND_MAX)) * (1 - 0) + 0;
        bats[i].loud = ((float)rand() / (float)(RAND_MAX)) * (2 - 1) + 1;
        bats[i].freq = ((float)rand() / (float)(RAND_MAX)) * (2 - 0) + 0;
    }
}

void calFitness(struct bat bats[])
{
    for (short i = 0; i < POP_NO; i++)
    {
        // double sum = 0;

        // for (short j = 0; j < DIM; j++)
        //     sum += pow(bats[i].pos[j], 2);

        // bats[i].fit = sum;
        bats[i].fit = 1000 - (21.5 + bats[i].pos[0] * sin(4 * (22 / 7) * bats[i].pos[0]) + bats[i].pos[1] * sin(20 * (22 / 7) * bats[i].pos[1]));
        // int D = 5;
        // for (short j = 0; j < DIM; j++)
        // {
        //     sum += pow(bats[i].pos[j], 2) - 10 * cos(2 * (22 / 7) * bats[i].pos[j]);
        // }
        // sum + 10 * D;
        // bats[i].fit = sum;
    }
}

short bestFitness(struct bat bats[])
{
    // Finding the best fit
    short Index = 0;
    for (short i = 0; i < POP_NO; i++)
        Index = (bats[i].fit < bats[Index].fit) ? i : Index;

    return Index;
}

void adjustFreq(struct bat bats[], struct bat nBats[])
{
    for (short i = 0; i < POP_NO; i++)
        nBats[i].fit = ((float)rand() / (float)(RAND_MAX)) * (2 - 0) + 0;
}

void updtVel(struct bat bats[], struct bat nBats[], short Index)
{
    for (short i = 0; i < POP_NO; i++)
        for (short j = 0; j < DIM; j++)
            nBats[i].vel[j] = bats[i].vel[j] + (bats[i].pos[j] - bats[Index].pos[j]) * bats[i].freq;
}

void updtPos(struct bat bats[], struct bat nBats[])
{
    for (short i = 0; i < POP_NO; i++)
        for (short j = 0; j < DIM; j++)
            nBats[i].pos[j] = bats[i].pos[j] + bats[i].vel[j];
}

void genLclSol(struct bat bats[], short index)
{
    float avgLoud, sum = 0;
    for (short i = 0; i < POP_NO; i++)
        sum += bats[i].loud;

    avgLoud = sum / POP_NO;

    float Eta = ((float)rand() / (float)(RAND_MAX)) * 2.0f - 1.0f; // Random number between 1 and -1
    // float Eta = 0.6294;

    for (short j = 0; j < DIM; j++)
    {
        bats[index].pos[j] = bats[index].pos[j] + Eta * avgLoud;

        // Boundary check
        if (bats[index].pos[j] < 0)
            bats[index].pos[j] = 0;
        else if (bats[index].pos[j] > 2)
            bats[index].pos[j] = 2;
    }
}

void updateLoudPulse(struct bat bats[], int Iteration)
{
    float ALPHA = 0.9;
    float t = Iteration, GAMMA = 0.9, r0;

    for (short i = 0; i < POP_NO; i++)
    {
        // Reducing Loudness
        bats[i].loud = ALPHA * bats[i].loud;

        // Increasing Pulse Rate
        r0 = bats[i].pulse * 0.001 / 100; // 0.001 % of initial pulse rate
        bats[i].pulse = r0 * (1 - exp(-GAMMA * t));
    }
}
