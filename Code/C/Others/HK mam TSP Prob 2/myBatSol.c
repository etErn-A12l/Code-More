#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

#define POP_NO 10     // 44-43       // number of bats
#define DIM 18        // number of dimensions
#define ITERATIONS 10 // number of iterations

const char *fName = "F:/Documents/TEMP/HK Mam/matrix.txt";
int ROW;

typedef struct
{
    float pulse, vel[DIM], loud, freq;
    int fit;
    int pos[DIM];
} BAT;

void Initiate(BAT bats[]);
void calFitness(BAT bats[], int **matrix);
short bestFitness(BAT bats[]);
void adjustFreq(BAT nBats[]);
void updtVel(BAT bats[], BAT nBats[], short Index);
void updtPos(BAT bats[], BAT nBats[], short B_ind, int **matrix);
void genLclSol(BAT bats[], short ind);
void updateLoudPulse(BAT bats[], int Iteration);
int **read_matrix(const char *fName, int *rows);
void posShuffle(int pos[]);
void updateGnome(BAT bats[], BAT nBats[]);
void cyclic_crossover(int pos[], int xPos[]);
void copy_pos(int pos1[], int pos2[]);

int fitness(int pos[], int **arr);
void inter_update(int pos[], int fitnss, int **matrix);
void swap(int pos[], int index);

int main(int argc, char const *argv[])
{
    int **matrix = read_matrix(fName, &ROW);

    // for (int i = 0; i < ROW; i++)
    // {
    //     for (int j = 0; j < ROW; j++)
    //         printf("%d\t", matrix[i][j]);
    //     printf("\n\n");
    // }

    BAT x[POP_NO];

    srand(time(NULL)); // seedind with the value of current time

    // Generate random frequencies and loud
    float A = (float)rand() / (float)RAND_MAX;

    short Itr = 0, bestGen = 0;

    Initiate(x);

    for (short i = 0; i < POP_NO; i++)
    {
        for (short j = 0; j < ROW; j++)
            printf("%i ", x[i].pos[j]);

        printf("\n\n");
    }

    calFitness(x, matrix);

    short bst_IDX = bestFitness(x);
    BAT bestBat = x[bst_IDX];
    // Best fit in solutions

    // =================================

    short test_count = 0;

    while (Itr++ < ITERATIONS)
    {
        BAT y[POP_NO]; // New Solutions

        printf("\n\n\n\t\t======= ITERATION: %hu FITNESS =======\n\n\n", Itr);
        for (short i = 0; i < POP_NO; i++)
            printf("\n  BAT %hu : \t%d  ", i + 1, x[i].fit);

        printf("\n\n  Best Fitness : %d  From BAT %hu\n", x[bst_IDX].fit, bst_IDX + 1);

        adjustFreq(y);
        updtVel(x, y, bst_IDX);
        updtPos(x, y, bst_IDX, matrix);
        // posShuffle(x[bst_IDX].pos, ROW);

        for (short i = 0; i < POP_NO; i++)
        {
            // printf("\n");
            // for (short j = 0; j < ROW; j++)
            //     printf("%i ", y[i].pos[j]);

            // printf("\n");
            // for (short j = 0; j < ROW; j++)
            //     printf("%i ", x[i].pos[j]);

            y[i].fit = fitness(y[i].pos, matrix);
            printf("\n  New Fitness : %d", y[i].fit);
        }

        for (short i = 0; i < POP_NO; i++)
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

        for (short i = 0; i < POP_NO; i++)
        {
            // printf("\n%d < %d ?\n", y[i].fit, x[i].fit);
            if (y[i].fit < x[i].fit) // Conditionally accept New Solution
            {
                x[i].pulse = y[i].pulse;
                x[i].loud = y[i].loud;
                x[i].freq = y[i].freq;
                x[i].fit = y[i].fit;
                for (short j = 0; j < ROW; j++)
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
            for (short i = 0; i < DIM; i++)
            {
                bestBat.vel[i] = x[bst_IDX].vel[i];
                bestBat.pos[i] = x[bst_IDX].pos[i];
            }
        }
    }

    printf("\n\nBEST FIT WAS FOUND AT %hu ITERATION WITH %d FITNESS !\n\n", bestGen + 1, bestBat.fit);
    printf("\nThe GNOME WAS\n\n");
    for (short i = 0; i < ROW; i++)
        printf(" %i", bestBat.pos[i]);
    printf("\n\nTest_count = %hu\n", test_count);
    return 0;
}

// =================================================================
//                       Initiator Functions
// =================================================================

int **read_matrix(const char *fName, int *rows)
{
    FILE *file = fopen(fName, "r");
    if (file == NULL)
    {
        printf("Error opening file\n");
        return NULL;
    }

    // Count rows and columns
    int row_count = 1, col_count = 1;
    int ch;
    while ((ch = fgetc(file)) != EOF)
    {
        if (ch == '\n')
            row_count++;
    }
    col_count = row_count;

    printf("\nRows: %d\nCols: %d\n\n\n", row_count, col_count);

    // Allocate memory for the 2D array
    int **matrix = (int **)malloc(row_count * sizeof(int *));
    for (int i = 0; i < row_count; i++)
    {
        matrix[i] = (int *)malloc(col_count * sizeof(int));
    }

    // Reset file pointer to beginning
    fseek(file, 0L, SEEK_SET);

    // Read the matrix values
    for (int i = 0; i < row_count; i++)
    {
        for (int j = 0; j < col_count; j++)
        {
            fscanf(file, "%d", &matrix[i][j]);
        }
    }

    fclose(file);

    *rows = row_count;
    return matrix;
}

void Initiate(BAT bats[])
{
    // Assigning random values
    for (short i = 0; i < POP_NO; i++)
    {
        short count = 0;

        for (short j = 0; j < ROW; j++) // Initializing 0 - ROW
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
    for (short i = 0; i < POP_NO; i++)
    {
        // int fitness = 0;
        // for (short j = 0; j < ROW - 1; j++)
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
    for (short i = 0; i < POP_NO; i++)
        nBats[i].fit = ((float)rand() / (float)(RAND_MAX)) * (2 - 0) + 0;
}

void updtVel(BAT bats[], BAT nBats[], short Index)
{
    for (short i = 0; i < POP_NO; i++)
        for (short j = 0; j < DIM; j++)
            nBats[i].vel[j] = bats[i].vel[j] + (bats[i].pos[j] - bats[Index].pos[j]) * bats[i].freq;
}

void updtPos(BAT bats[], BAT nBats[], short B_ind, int **matrix)
{
    for (short i = 0; i < POP_NO; i++)
    {
        for (short j = 0; j < ROW; j++)
        {
            nBats[i].pos[j] = bats[i].pos[j];
        }
        nBats[i].fit = bats[i].fit;
    }

    for (short i = 0; i < POP_NO; i++)
    {
        // if (i != B_ind)
        //     cyclic_crossover(nBats[i].pos, nBats[B_ind].pos, ROW);
        // // posShuffle(nBats[i].pos, ROW);

        inter_update(nBats[i].pos, nBats[i].fit, matrix);
    }
}

void inter_update(int pos[], int fitnss, int **matrix)
{
    // printf("\nEntered New Function !\n");
    int min_fit = fitnss;
    int index = 0, temp;
    // printf("\n\nBefore Change     ");
    // for (short j = 0; j < ROW; j++)
    //     printf("%i ", pos[j]);

    for (int i = 0; i < ROW / 2; i++)
    {

        temp = pos[i];
        pos[i] = pos[ROW - 1 - i];
        pos[ROW - 1 - i] = temp;
        // printf("\nChange   ");
        // for (short j = 0; j < ROW; j++)
        //     printf("%i ", pos[j]);

        int anew_fit = fitness(pos, matrix);
        // printf("\t%d < %d ?\n", anew_fit, min_fit);
        if (anew_fit < min_fit)
        {
            index = i;
            min_fit = anew_fit;
        }

        // Revert
        temp = pos[i];
        pos[i] = pos[ROW - 1 - i];
        pos[ROW - 1 - i] = temp;
        // for (short j = 0; j < ROW; j++)
        //     printf("%i ", pos[j]);
    }

    if (min_fit != fitnss)
    {
        temp = pos[index];
        pos[index] = pos[ROW - 1 - index];
        pos[ROW - 1 - index] = temp;
        // printf("\nNew Fitness %d",min_fit);
    }
    // printf("\nPermanant Change  ");
    // for (short j = 0; j < ROW; j++)
    //     printf("%i ", pos[j]);
}

void swap(int pos[], int index)
{
    int temp = pos[index];
    pos[index] = pos[index - 1 - index];
    pos[index - 1 - index] = temp;
}

int fitness(int pos[], int **arr)
{
    int fit = 0;
    for (int i = 0; i < ROW - 1; i++)
    {
        fit += arr[pos[i]][pos[i + 1]];
    }
    fit += arr[pos[ROW - 1]][pos[0]];
    return fit;
}

void genLclSol(BAT bats[], short ind)
{
    float avgLoud, sum = 0;
    for (short i = 0; i < POP_NO; i++)
        sum += bats[i].loud;

    avgLoud = sum / POP_NO;

    /*

    float Eta = ((float)rand() / (float)(RAND_MAX)) * 2.0f - 1.0f; // Random number between 1 and -1
    // float Eta = 0.6294;

    for (short j = 0; j < DIM; j++)
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

    for (short i = 0; i < POP_NO; i++)
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
    for (short i = 0; i < POP_NO; i++)
    {
        for (short j = 0; j < ROW; j++)
            nBats[i].pos[j] = bats[i].pos[j];

        posShuffle(nBats[i].pos);
    }
}

void cyclic_crossover(int pos[], int xPos[])
{
    // printf("\n\nSTARTING cyclic crossover\n");
    int child[ROW];

    // Initialize child with -1
    for (short i = 0; i < ROW; i++)
        child[i] = -1;

    child[0] = pos[0];
    short i = 0, j, a = xPos[i];
    while (a != pos[0])
    {
        a = xPos[i];
        for (j = 0; j < ROW; j++)
        {
            if (pos[j] == a)
            {
                i = j;
                child[i] = pos[i];
            }
        }
    }

    for (i = 1; i < ROW; i++)
    {
        if (-1 == child[i])
            child[i] = xPos[i];
    }

    copy_pos(pos, child);
}

// =================================================================
//                       Helper Functions
// =================================================================

short bestFitness(BAT bats[])
{
    // Finding the best fit
    short Index = 0;
    for (short i = 0; i < POP_NO; i++)
        Index = (bats[i].fit < bats[Index].fit) ? i : Index;

    return Index;
}

void posShuffle(int pos[])
{
    for (short j = ROW - 1; j > 0; j--)
    {
        int u = rand() % (j + 1);
        int temp = pos[j];
        pos[j] = pos[u];
        pos[u] = temp;
    }
}

void copy_pos(int pos1[], int pos2[])
{
    for (int i = 0; i < ROW; i++)
        pos1[i] = pos2[i];
}
