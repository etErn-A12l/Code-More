// TSP Problem Solving by Genetic Algorithm With RW selection,Cyclic Cross Over without any constraint

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define node 10
#define noChro 85 // no of chromosome
#define maxgen 500
#define pc 0.4
#define pm 0.3

float COST[node][node] = {{1000, 25, 28, 32, 20, 6, 35, 37, 40, 30}, {37, 1000, 20, 28, 35, 40, 30, 42, 28, 4}, {42, 28, 1000, 30, 25, 35, 9, 32, 40, 30}, {28, 30, 7, 1000, 20, 25, 30, 35, 22, 37}, {37, 22, 35, 30, 1000, 20, 25, 30, 9, 28}, {25, 30, 25, 8, 28, 1000, 32, 40, 32, 30}, {28, 25, 30, 22, 37, 40, 1000, 10, 32, 20}, {20, 5, 32, 40, 35, 25, 40, 1000, 22, 37}, {30, 40, 35, 25, 20, 22, 37, 32, 1000, 28}, {28, 30, 28, 20, 11, 32, 37, 40, 30, 1000}};
float cumuprob[50], prob[50];
int newPopuArr[100], g; // new population array
double TOU[10][10], total;

struct chrom
{
    int weight[node];
    float fitness;
} ch[noChro];

struct chrom popu[100];
struct chrom npopu[100];
struct chrom fpopu[100];

void calfitness(int pv);
void selection(int pv);
void crossover(int pv);
void cross(int p0, int p1, int pv);
void mutation(int pv);
void mutate(int p, int pv);
float check(int pv);

int main()
{
    int i, j;

    // Generating Random Population for Chromosome

    for (i = 0; i < noChro; i++)
    {
        for (j = 0; j < node; j++)
            ch[i].weight[j] = rand() % 20;
    }

    // Just Printing the random chromosomes

    /*    
    for (int i = 0; i < noChro; i++)
    {
        for (int j = 0; j < node; j++)
            printf("%d ", ch[i].weight[j]);

        printf("\n");
    }
    */


    return 0;
}
