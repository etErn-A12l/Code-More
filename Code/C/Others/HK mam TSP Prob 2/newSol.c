#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

#define POP_NO 800      // 44-43       // number of bats
#define DIM 100        // number of dimensions
#define ITERATIONS 20000 // number of iterations

const char *fName = "F:/Documents/TEMP/HK Mam/ft53.txt";
int ROW;

typedef struct
{
    float pulse, vel[DIM], loud, freq;
    int fit;
    int pos[DIM];
} BAT;

void Initiate(BAT bats[]);
void calFitness(BAT bats[], int **matrix);
int bestFitness(BAT bats[]);
void adjustFreq(BAT nBats[]);
void updtVel(BAT bats[], BAT nBats[], int Index);
void updtPos(BAT bats[], BAT nBats[], int B_ind, int **matrix);
void genLclSol(BAT bats[], int ind);
void updateLoudPulse(BAT bats[], int Iteration);
int **read_matrix(const char *fName, int *rows);
void posShuffle(int pos[]);
void updateGnome(BAT bats[], BAT nBats[]);

int fitness(int pos[], int **arr);

int main(int argc, char const *argv[])
{
    int **matrix = read_matrix(fName, &ROW);

    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < ROW; j++)
            printf("%d\t", matrix[i][j]);
        printf("\n\n");
    }

    BAT x[POP_NO];

    srand(time(NULL)); // seedind with the value of current time

    // Generate random frequencies and loud
    float A = (float)rand() / (float)RAND_MAX;

    int Itr = 0, bestGen = 0;

    Initiate(x);

    for (int i = 0; i < POP_NO; i++)
    {
        for (int j = 0; j < ROW; j++)
            printf("%i ", x[i].pos[j]);

        printf("\n\n");
    }

    calFitness(x, matrix);

    int bst_IDX = bestFitness(x);
    BAT bestBat = x[bst_IDX];
    // Best fit in solutions

    // =================================

    int test_count = 0;

    while (Itr++ < ITERATIONS)
    {
        system("cls");
        BAT y[POP_NO]; // New Solutions

        printf("\n\n\n\t\t======= ITERATION: %d FITNESS =======\n\n\n", Itr);
        for (int i = 0; i < POP_NO; i++)
            printf("\n  BAT %d : \t%d  ", i + 1, x[i].fit);

        printf("\n\n  Best Fitness : %d  From BAT %d\n", x[bst_IDX].fit, bst_IDX + 1);

        adjustFreq(y);
        updtVel(x, y, bst_IDX);
        updtPos(x, y, bst_IDX, matrix);
        // posShuffle(x[bst_IDX].pos, ROW);

        // for (int i = 0; i < POP_NO; i++)
        // {
        //     // printf("\n");
        //     // for (int j = 0; j < ROW; j++)
        //     //     printf("%i ", y[i].pos[j]);

        //     // printf("\n");
        //     // for (int j = 0; j < ROW; j++)
        //     //     printf("%i ", x[i].pos[j]);

        //     // y[i].fit = fitness(y[i].pos, matrix);
        //     printf("\n  Old Fitness : %d", x[i].fit);
        //     printf("\n  New Fitness : %d", y[i].fit);
        // }

        for (int i = 0; i < POP_NO; i++)
        {
            float r = (float)rand() / (float)(RAND_MAX);

            if (x[i].pulse > r)
            {
                // Generating new local solutions
                // genLclSol(x, i, ROW);
                test_count++;
            }

            if (r < x[i].loud && y[i].fit < x[i].fit)
                // reduce loud and increase puse rate
                updateLoudPulse(x, Itr);
        }

        // ==== RANKING THE NEW SOLUTIONS ====

        for (int i = 0; i < POP_NO; i++)
        {
            // printf("\n%d < %d ?\n", y[i].fit, x[i].fit);
            if (y[i].fit < x[i].fit) // Conditionally accept New Solution
            {
                x[i].pulse = y[i].pulse;
                x[i].loud = y[i].loud;
                x[i].freq = y[i].freq;
                x[i].fit = y[i].fit;
                for (int j = 0; j < ROW; j++)
                {
                    x[i].pos[j] = y[i].pos[j];
                    x[i].vel[j] = y[i].vel[j];
                }
            }
        }

        bst_IDX = bestFitness(x);

        if (x[bst_IDX].fit < bestBat.fit)
        {
            bestGen = Itr;
            bestBat.pulse = x[bst_IDX].pulse;
            bestBat.loud = x[bst_IDX].loud;
            bestBat.freq = x[bst_IDX].freq;
            bestBat.fit = x[bst_IDX].fit;
            for (int i = 0; i < DIM; i++)
            {
                bestBat.vel[i] = x[bst_IDX].vel[i];
                bestBat.pos[i] = x[bst_IDX].pos[i];
            }
        }
    }

    printf("\n\nBEST FIT WAS FOUND AT %d ITERATION WITH %d FITNESS !\n\n", bestGen + 1, bestBat.fit);
    printf("\nThe GNOME WAS\n\n");
    for (int i = 0; i < ROW; i++)
        printf(" %i", bestBat.pos[i]);
    printf("\n\nTest_count = %d\n", test_count);

    return 0;
}

// =================================================================
//                       Initiator Functions
// =================================================================

int **read_matrix(const char *fName, int *rows)
{
    FILE *file = fopen(fName, "r");
    char line[10000];
    int row_count = 0;

    if (file == NULL)
    {
        printf("Error opening file\n");
        return NULL;
    }

    // while ((ch = fgetc(file)) != EOF)
    // {
    //     if (ch == "\n")
    //         row_count++;
    // }

    // Count rows and columns
    while (fgets(line, sizeof(line), file))
    {
        if (strstr(line, "9999999") != NULL)
            row_count++;
    }

    printf("\nRows: %d\nCols: %d\n\n\n", row_count, row_count);

    // Allocate memory for the 2D array
    int **matrix = (int **)malloc(row_count * sizeof(int *));
    for (int i = 0; i < row_count; i++)
        matrix[i] = (int *)malloc(row_count * sizeof(int));

    // Reset file pointer to beginning
    fseek(file, 0L, SEEK_SET);

    // Read the matrix values
    for (int i = 0; i < row_count; i++)
    {
        for (int j = 0; j < row_count; j++)
            fscanf(file, "%d", &matrix[i][j]);
    }

    fclose(file);

    *rows = row_count;
    return matrix;
}

void Initiate(BAT bats[])
{
    // Assigning random values
    for (int i = 0; i < POP_NO; i++)
    {
        int count = 0;

        for (int j = 0; j < ROW; j++) // Initializing 0 - ROW
        {
            bats[i].pos[j] = count++;
            bats[i].vel[j] = (float)rand() / (float)(RAND_MAX);
        }
        posShuffle(bats[i].pos);

        bats[i].pulse = ((float)rand() / (float)(RAND_MAX)) * (1 - 0) + 0;
        bats[i].loud = ((float)rand() / (float)(RAND_MAX)) * (2 - 1) + 1;
        bats[i].freq = ((float)rand() / (float)(RAND_MAX)) * (2 - 0) + 0;
    }
}

void calFitness(BAT bats[], int **matrix)
{
    for (int i = 0; i < POP_NO; i++)
    {
        // int fitness = 0;
        // for (int j = 0; j < ROW - 1; j++)
        // {
        //     // printf("\nfitness %lf += %d", fitness, matrix[bats[i].pos[j]][bats[i].pos[j + 1]]);
        //     fitness += matrix[bats[i].pos[j]][bats[i].pos[j + 1]];
        // }
        // fitness += matrix[bats[i].pos[ROW - 1]][bats[i].pos[0]];
        // bats[i].fit = fitness;
        bats[i].fit = fitness(bats[i].pos, matrix);
    }
}

// =================================================================
//                       Updater Functions
// =================================================================

void adjustFreq(BAT nBats[])
{
    for (int i = 0; i < POP_NO; i++)
        nBats[i].fit = ((float)rand() / (float)(RAND_MAX)) * (2 - 0) + 0;
}

void updtVel(BAT bats[], BAT nBats[], int Index)
{
    for (int i = 0; i < POP_NO; i++)
        for (int j = 0; j < DIM; j++)
            nBats[i].vel[j] = bats[i].vel[j] + (bats[i].pos[j] - bats[Index].pos[j]) * bats[i].freq;
}

void updtPos(BAT bats[], BAT nBats[], int B_ind, int **matrix)
{
    for (int i = 0; i < POP_NO; i++)
    {
        for (int j = 0; j < ROW; j++)
            nBats[i].pos[j] = bats[i].pos[j];

        // nBats[i].fit = bats[i].fit;
    }

    for (int i = 0; i < POP_NO; i++)
    {
        // if (i != B_ind)
        //     cyclic_crossover(nBats[i].pos, nBats[B_ind].pos, ROW);
        // // posShuffle(nBats[i].pos, ROW);

        // two_opt(nBats[i], matrix);
        // choosing a random subset from the genome
        int mid = ROW / 2;
        int max = ROW - 1;
        int lower = (rand() % (mid - 0 + 1)) + 0;
        int upper = (rand() % (max - (mid + 1) + 1)) + mid;
        // printf("\nLower: %d\nUpper: %d", lower, upper);

        // printf("\n  OLD Fitness : %d", fitness(bat.pos, matrix));
        // reverse(lower, upper, bat.pos);
        while (lower < upper)
        {
            int tmp = nBats[i].pos[lower];
            nBats[i].pos[lower++] = nBats[i].pos[upper];
            nBats[i].pos[upper--] = tmp;
        }

        // printf("\nBEFOR: ");
        // for (int j = 0; j < ROW; j++)
        //     printf("%i ", bats[i].pos[j]);
        // printf("\nAFTER: ");
        // for (int j = 0; j < ROW; j++)
        //     printf("%i ", nBats[i].pos[j]);
        nBats[i].fit = fitness(nBats[i].pos, matrix);
        // printf("\n  OLD Fitness : %d", bats[i].fit);
        // printf("\n  NEW Fitness : %d", nBats[i].fit);
    }
}

int fitness(int pos[], int **arr)
{
    int fit = 0;
    for (int i = 0; i < ROW - 1; i++)
    {
        if (pos[i] != pos[i + 1])
            fit += arr[pos[i]][pos[i + 1]];
    }
    fit += arr[pos[ROW - 1]][pos[0]];
    return fit;
}

void genLclSol(BAT bats[], int ind)
{
    float avgLoud, sum = 0;
    for (int i = 0; i < POP_NO; i++)
        sum += bats[i].loud;

    avgLoud = sum / POP_NO;

    /*

    float Eta = ((float)rand() / (float)(RAND_MAX)) * 2.0f - 1.0f; // Random number between 1 and -1
    // float Eta = 0.6294;

    for (int j = 0; j < DIM; j++)
    {
        bats[ind].pos[j] = bats[ind].pos[j] + Eta * avgLoud;

        // Boundary check
        if (bats[ind].pos[j] < 0)
            bats[ind].pos[j] = 0;
        else if (bats[ind].pos[j] > 2)
            bats[ind].pos[j] = 2;
    }

    */
    posShuffle(bats[ind].pos);
}

void updateLoudPulse(BAT bats[], int Iteration)
{
    float ALPHA = 0.9;
    float t = Iteration, GAMMA = 0.9, r0;

    for (int i = 0; i < POP_NO; i++)
    {
        // Reducing Loudness
        bats[i].loud = ALPHA * bats[i].loud;

        // Increasing Pulse Rate
        r0 = bats[i].pulse * 0.001 / 100; // 0.001 % of initial pulse rate
        bats[i].pulse = r0 * (1 - exp(-GAMMA * t));
    }
}

void updateGnome(BAT bats[], BAT nBats[])
{
    for (int i = 0; i < POP_NO; i++)
    {
        for (int j = 0; j < ROW; j++)
            nBats[i].pos[j] = bats[i].pos[j];

        posShuffle(nBats[i].pos);
    }
}

// apply the 2-opt move to the tour
// void two_opt(BAT bat, int **matrix)
// {
//     printf("\nEntered Two Opt");
//     int improved = 1;
//     while (improved)
//     {
//         improved = 0;
//         for (int i = 0; i < ROW - 2; i++)
//         {
//             for (int j = i + 2; j < ROW; j++)
//             {
//                 int delta = matrix[bat.pos[i]][bat.pos[j]] + matrix[bat.pos[i + 1]][bat.pos[j + 1]] - matrix[bat.pos[i]][bat.pos[i + 1]] - matrix[bat.pos[j]][bat.pos[j + 1]];
//                 if (delta < 0)
//                 {
//                     reverse(i + 1, j, bat.pos);
//                     improved = 1;
//                 }
//             }
//         }
//     }
// }

// apply the 2-opt move to the tour
void two_opt(BAT bat, int **matrix)
{
    // printf("\nEntered Two Opt");
    int mid = ROW / 2;
    int max = ROW - 1;
    int lower = (rand() % (mid - 0 + 1)) + 0;
    int upper = (rand() % (max - (mid + 1) + 1)) + mid;
    // printf("\nLower: %d\nUpper: %d", lower, upper);

    // printf("\n  OLD Fitness : %d", fitness(bat.pos, matrix));
    // reverse(lower, upper, bat.pos);
    while (lower < upper)
    {
        int tmp = bat.pos[lower];
        bat.pos[lower++] = bat.pos[upper];
        bat.pos[upper--] = tmp;
    }

    // printf("\n  New Fitness : %d", bat.fit);
}

// =================================================================
//                       Helper Functions
// =================================================================

int bestFitness(BAT bats[])
{
    // Finding the best fit
    int Index = 0;
    for (int i = 0; i < POP_NO; i++)
        Index = (bats[i].fit < bats[Index].fit) ? i : Index;

    return Index;
}

void posShuffle(int pos[])
{
    for (int j = ROW - 1; j > 0; j--)
    {
        int u = rand() % (j + 1);
        int temp = pos[j];
        pos[j] = pos[u];
        pos[u] = temp;
    }
}

void reverse(int i, int j, int pos[])
{
    while (i < j)
    {
        int tmp = pos[i];
        pos[i++] = pos[j];
        pos[j--] = tmp;
    }
}