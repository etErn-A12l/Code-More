#include <stdio.h>

// parameters //
typedef struct Params_
{
    double A;
    double r, a;
    double fmin, fmax;
    int n;
} Params;

// bat population/populations //
typedef struct Bats_
{
    double *x, *v;
    double fitness;
} Bats;

// function to be optimized //
double objectiveFunc(double x[], params);

int main()
{
    // define parameters //
    Params param;
    // initializing structures and values required for the bat algorithm //
    int k, i;
    double b, tmpFitness, bestFitness = 0;
    double *new_velocity;
    new_velocity = (double *)malloc(D * sizeof(double));
    double *best;
    best = (double *)malloc(D * sizeof(double));
    Bats *bats = (Bats *)malloc(param.n * sizeof(Bats));

    // randomly initialize bats population //
    srand(clock());
    for (k = 0; k < param.n; k++)
    {
        for (i = 0; i < D; i++)
        {
            bats[k].x[i] = rand() % (int)(param.fmax - param.fmin + 1) + param.fmin;
            bats[k].v[i] = rand() / (double)(RAND_MAX);
        }

        bats[k].fitness = objectiveFunc(bat[k].x, param);
    }

    // start iterations //
    while (/* some criteria */)
    {
        // loop over bats //
        for (k = 0; k < param.n; k++)
        {
            // compute new velocity vector //
            for (i = 0; i < D; i++)
            {
                b = rand() / (double)(RAND_MAX);
                new_velocity[i] = b * param.a * (best[i] - bats[k].x[i]) + param.A * bats[k].v[i];
            }

            // update position and velocity vector //
            for (i = 0; i < D; i++)
            {
                bats[k].x[i] += new_velocity[i];
                bats[k].v[i] = new_velocity[i];

                if (bats[k].x[i] > param.fmax)
                    bats[k].x[i] = param.fmax;

                if (bats[k].x[i] < param.fmin)
                    bats[k].x[i] = param.fmin;
            }

            // evaluate new fitness //
            bats[k].fitness = objectiveFunc(bat[k].x, param);

            // update best //
            tmpFitness = objectiveFunc(bat[k].x, param);
            if (tmpFitness > bestFitness)
            {
                bestFitness = tmpFitness;
                for (i = 0; i < D; i++)
                    best[i] = bat[k].x[i];
            }
        }
    }

    return 0;
}