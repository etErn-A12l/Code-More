#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

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
void genLocalSolutions(struct bat x[], struct bat y[]);
void updateLoudPulse(struct bat x[]);

int main(int argc, char const *argv[])
{
    srand((unsigned int)time(NULL)); // seedind with the value of current time

    // Generate random frequencies and loudness
    float A = (float)rand() / (float)RAND_MAX;
    float r = (float)rand() / (float)RAND_MAX;

    short Iteration = 0, bestGen = 0;

    Initiate(x);
    calFitness(x);

    short bestIndex_X = bestFitness(x);

    while (Iteration++ < ITERATIONS)
    {
        // system('cls');
        adjustFreq(x);
        updateVelocity(x, bestIndex_X);
        updatePosition(x);
        calFitness(x);

        bestIndex_X = bestFitness(x);
        double X_bestFitness = x[bestIndex_X].fitness; // Index of Best fitness value
        double overallBestFitness = X_bestFitness;     // Best fitness in new population
        float R = (float)rand() / (float)(RAND_MAX);
        struct bat y[POP_NO];

        if (R > r)
            // Generating new local solutions
            genLocalSolutions(x, y);

        // Calculating fitness of the new local solutions
        calFitness(y);

        short bestIndex_Y = bestFitness(y);            // Index of Best fitness value
        double Y_bestFitness = y[bestIndex_Y].fitness; // Best fitness in new population

        if (A < x[bestIndex_X].loudness && y[bestIndex_Y].fitness < X_bestFitness)
        {
            // Accepting new solutions
            for (short i = 0; i < POP_NO; i++)
            {
                for (short j = 0; j < DIM; j++)
                    x[i].position[j] = y[i].position[j];
                x[i].fitness = y[i].fitness;
            }
            // reduce loudness and increase puse rate
            updateLoudPulse(x);
        }

        printf("\nBest fitness in Previous population: %lf", X_bestFitness);
        printf("\nBest fitness in Current population: %lf", Y_bestFitness);

        if (Y_bestFitness < overallBestFitness)
        {
            overallBestFitness = Y_bestFitness;
            bestGen = Iteration;
        }
        printf("\n\nBest fitness was found at %hu Iteration with %lf Fitness", bestGen, Y_bestFitness);
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

void genLocalSolutions(struct bat x[], struct bat y[])
{
    float avg_loudness, sum = 0;
    for (short i = 0; i < POP_NO; i++)
        sum += x[i].loudness;

    avg_loudness = sum / POP_NO;

    float Eta = ((float)rand() / (float)(RAND_MAX)) * (1 - (-1)) + (-1);

    for (short i = 0; i < POP_NO; i++)
        for (short j = 0; j < DIM; j++)
            y[i].position[j] = x[i].position[j] + Eta * avg_loudness;
}

void updateLoudPulse(struct bat x[])
{
    float alpha = (float)rand() / (float)(RAND_MAX); // Random float between 0 and 1.
    float t = 1, gamma = 0.9, r0;

    for (short i = 0; i < POP_NO; i++)
    {
        // Reducing Loudness
        x[i].loudness = alpha * x[i].loudness;

        // Increasing Pulse Rate
        r0 = x[i].pulse * 0.001 / 100; // 0.001 % of initial pulse rate
        x[i].pulse = r0 * (1 - exp(-gamma * t));
    }
}