#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N_BATS 5
#define N_DIMENSIONS 10
#define LOWER_BOUND -5.12
#define UPPER_BOUND 5.12

double sphere_function(double pos[], int dimensions)
{
    double sum = 0;
    for (int i = 0; i < dimensions; i++)
    {
        sum += pow(pos[i], 2);
    }
    return sum;
}

void initialize_positions(double positions[][N_DIMENSIONS], int n_bats)
{
    for (int i = 0; i < n_bats; i++)
    {
        for (int j = 0; j < N_DIMENSIONS; j++)
        {
            positions[i][j] = LOWER_BOUND + (double)rand() / RAND_MAX * (UPPER_BOUND - LOWER_BOUND);
        }
    }
}

void calculate_fitness(double fitness_values[], double positions[][N_DIMENSIONS], int n_bats)
{
    for (int i = 0; i < n_bats; i++)
    {
        fitness_values[i] = sphere_function(positions[i], N_DIMENSIONS);
    }
}

int main()
{
    srand(time(NULL));

    double positions[N_BATS][N_DIMENSIONS];
    double fitness_values[N_BATS];

    initialize_positions(positions, N_BATS);
    calculate_fitness(fitness_values, positions, N_BATS);

    printf("Positions:\n");
    for (int i = 0; i < N_BATS; i++)
    {
        for (int j = 0; j < N_DIMENSIONS; j++)
        {
            printf("%f ", positions[i][j]);
        }
        printf("\n");
    }

    printf("\nFitness Values:\n");
    for (int i = 0; i < N_BATS; i++)
    {
        printf("%f\n", fitness_values[i]);
    }

    return 0;
}
