#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define POP_NO 5       // number of bats
#define DIM 10         // number of dimensions
#define ITERATIONS 100 // number of iterations

struct bat
{
    float position[DIM], pulse, velocity[DIM], loudness, frequency;
    double fitness;
};

struct bat x[POP_NO];

void Initiate(struct bat x[]);
void calFitness(struct bat x[]);
short bestFitness(struct bat x[]);
void adjustFreq(struct bat x[]);
void updateVelocity(struct bat x[], short Index);
void updatePosition(struct bat x[]);

int main(int argc, char const *argv[])
{
    srand((unsigned int)time(NULL)); // seedind with the value of current time

    float R = (float)rand() / (float)(RAND_MAX);
    short Iteration = 0;

    Initiate(x);
    calFitness(x);

    short bestIndex = bestFitness(x);

    // for (short i = 0; i < POP_NO; i++)
    //     printf("Fitness = %lf\n", x[i].fitness);

    // printf("\n\nBest Fitness: %lf", x[bestIndex].fitness);

    while (Iteration++ < ITERATIONS)
    {
        adjustFreq(x);
        updateVelocity(x, bestIndex);
        updatePosition(x);
        calFitness(x);
        bestIndex = bestFitness(x);
    }

    return 0;
}

void Initiate(struct bat x[])
{

    for (short i = 0; i < POP_NO; i++)
    {
        for (short j = 0; j < DIM; j++)
        {
            x[i].position[j] = ((float)rand() / (float)(RAND_MAX)) * (2 - 0) + 0;
            x[i].velocity[j] = (float)rand() / (float)(RAND_MAX);
        }

        x[i].pulse = ((float)rand() / (float)(RAND_MAX)) * (1 - 0) + 0;
        x[i].loudness = ((float)rand() / (float)(RAND_MAX)) * (2 - 1) + 1;
        x[i].frequency = ((float)rand() / (float)(RAND_MAX)) * (2 - 0) + 0;
    }
}

void calFitness(struct bat x[])
{
    for (short i = 0; i < POP_NO; i++)
    {
        double sum = 0;

        for (short j = 0; j < DIM; j++)
            sum += x[i].position[j] * x[i].position[j];

        x[i].fitness = sum;
    }
}

short bestFitness(struct bat x[])
{
    // Finding the best fitness
    short Index = 0;
    for (short i = 0; i < POP_NO; i++)
        Index = (x[i].fitness < x[Index].fitness) ? i : Index;

    return Index;
}

void adjustFreq(struct bat x[])
{
    for (short i = 0; i < POP_NO; i++)
        x[i].frequency = ((float)rand() / (float)(RAND_MAX)) * (2 - 0) + 0;
}

void updateVelocity(struct bat x[], short Index)
{
    for (short i = 0; i < POP_NO; i++)
        for (short j = 0; j < DIM; j++)
            x[i].velocity[j] = x[i].velocity[j] + ((x[i].position[j] - x[Index].position[j]) * x[i].frequency);
}

void updatePosition(struct bat x[])
{
    for (short i = 0; i < POP_NO; i++)
        for (short j = 0; j < DIM; j++)
            x[i].position[j] = x[i].position[j] + x[i].velocity[j];
}