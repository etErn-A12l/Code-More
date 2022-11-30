// TSP Problem Solving by Genetic Algorithm With RW selection, Cyclic Cross Over without any constraint

#include <bits/stdc++.h>
#include <conio.h>
#include <limits.h>
using namespace std;

#define CITY 10     // number of cities
#define POP_SIZE 85 // no of chromosome or population size
#define MAX_GEN 500 // maximum generation
// #define pc 0.4
// #define pm 0.3

int COST[CITY][CITY] = {{1000, 25, 28, 32, 20, 6, 35, 37, 40, 30},
                        {37, 1000, 20, 28, 35, 40, 30, 42, 28, 4},
                        {42, 28, 1000, 30, 25, 35, 9, 32, 40, 30},
                        {28, 30, 7, 1000, 20, 25, 30, 35, 22, 37},
                        {37, 22, 35, 30, 1000, 20, 25, 30, 9, 28},
                        {25, 30, 25, 8, 28, 1000, 32, 40, 32, 30},
                        {28, 25, 30, 22, 37, 40, 1000, 10, 32, 20},
                        {20, 5, 32, 40, 35, 25, 40, 1000, 22, 37},
                        {30, 40, 35, 25, 20, 22, 37, 32, 1000, 28},
                        {28, 30, 28, 20, 11, 32, 37, 40, 30, 1000}};

struct chromosome
{
    string gnome;
    int fitness;
    float prob, qumulative_prob;
};

int rand_num(int start, int end);                                            // Function to return a random number
bool repeat(string gnome, char);                                             // Function to check if the character has already occurred in the array
string mutatedGene(string &gnome);                                           // Function to return a mutated GNOME
string create_gnome();                                                       // Function to create a valid GNOME string to create the population
int cal_fitness(string gnome);                                               // Function to return the fitness value of a gnome.
int best_fitIndex(vector<struct chromosome> population);                     // returns the index of best fitness chromosome
void rw_selection(vector<struct chromosome> &, vector<struct chromosome> &); // Perform Roulette Wheel Selection and return true if the chromosome is selected
void cyclic_crossover(string *, string *);                                   // Takes two string and performs cyclic crossover to it and changes them to child of them
void display_population(chromosome);                                         // Prints the chromosomes

int main()
{
    system("cls");

    vector<struct chromosome> population;
    struct chromosome temp;
    int i;

    /* ============= Creating Initial Population ============= */

    for (i = 0; i < POP_SIZE; i++)
    {
        temp.gnome = create_gnome();
        temp.fitness = cal_fitness(temp.gnome);

        population.push_back(temp);
    }

    /* ============= Displaying Initial Population ============= */

    cout << "\n\t\t------** Initial population **------\n"
         << endl
         << "PATH\t\t\t\t\t\t\t\tFITNESS VALUE\n"
         << endl;

    for (i = 0; i < population.size(); i++)
        display_population(population[i]);

    int best_index = best_fitIndex(population);
    cout << endl
         << "\nBest Fitted Path In This Population:\n"
         << endl;
    display_population(population[best_index]);

    cout << "\n\nPress ENTER to Continue :";
    getch();

    int best_fitness = INT_MAX, best_gen;
    struct chromosome best_chromosome;

    /* ============= APPLYING ALGORITHM ============= */

    vector<struct chromosome> new_population = population;

    int gen;

    // Generation Iteration
    for (gen = 1; gen <= 10; gen++)
    {
        vector<struct chromosome> nextGen_population;

        // Recalculating the fitness
        for (i = 0; i < new_population.size(); i++)
        {
            new_population[i].fitness = cal_fitness(new_population[i].gnome);
            if (new_population[i].fitness < best_fitness)
            {
                best_fitness = new_population[i].fitness;
                best_gen = gen;
                best_chromosome = new_population[i];
            }
        }

        // Calculating total fitness
        int total_fitness = 0;
        for (i = 0; i < new_population.size(); i++)
            total_fitness += new_population[i].fitness;

        // Calculating probability for each chromosome
        for (i = 0; i < new_population.size(); i++)
            new_population[i].prob = (float)new_population[i].fitness / (float)total_fitness;

        // Calculating qumulative probability for each chromosome
        float q_prob = 0;
        for (i = 0; i < new_population.size(); i++)
        {
            q_prob += new_population[i].prob;
            new_population[i].qumulative_prob = q_prob;
        }

        /* ============= Roulette Wheel Selection ============= */
        // Selected Parents will be pushed to nextGen_population
        for (i = 0; i < new_population.size(); i++)
            rw_selection(new_population, nextGen_population);

        /* ============= Applying Cyclic Crossover ============= */
        // Best Selected Parents are in nextGen_population
        for (i = 0; i < nextGen_population.size() - 1; i++)
            cyclic_crossover(&nextGen_population[i].gnome, &nextGen_population[i + 1].gnome);

        /* ============= Applying Mutation to the genes ============= */
        for (i = 0; i < nextGen_population.size(); i++)
            nextGen_population[i].gnome = mutatedGene(nextGen_population[i].gnome);

        /* ============= Displaying new generation Chromosomes ============= */
        system("cls");
        cout << endl
             << "\t\t------** Generation " << gen << " **------"
             << endl;

        cout << endl
             << "PATH\t\t\t\t\t\t\t\tFITNESS VALUE\n"
             << endl;

        for (i = 0; i < nextGen_population.size(); i++)
            display_population(nextGen_population[i]);

        int best_index = best_fitIndex(nextGen_population);
        cout << endl
             << "\nBest Fitted Path In This Population: \n"
             << endl;
        display_population(nextGen_population[best_index]);

        new_population = nextGen_population;
    }

    cout << endl
         << "\nBest Fitness Was Found at Generation : " << best_gen << endl
         << endl;
    display_population(best_chromosome);
    cout << endl;

    return 0;
}

// Function to return a random number
int rand_num(int start, int end)
{
    int r = end - start;
    int rnum = start + rand() % r;
    return rnum;
}

// Function to check if the character has already occurred in the array
bool repeat(string s, char ch)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ch)
            return true;
    }
    return false;
}

// Function to return a mutated GNOME
string mutatedGene(string &gnome)
{
    while (true)
    {
        int r = rand_num(1, CITY); // first and last index not allowed because they already have same value
        int r1 = rand_num(1, CITY);
        if (r1 != r)
        {
            char temp = gnome[r];
            gnome[r] = gnome[r1];
            gnome[r1] = temp;
            break;
        }
    }
    return gnome;
}

// Function to create a valid GNOME array to create the population
string create_gnome()
{
    string gnome = "";
    while (true)
    {
        if (gnome.size() == CITY)
        {
            gnome += gnome[0];
            break;
        }
        int temp = rand_num(0, CITY);
        if (!repeat(gnome, (char)(temp + 48)))
            gnome += (char)(temp + 48);
    }
    return gnome;
}

// Function to return the fitness value of a gnome.
int cal_fitness(string gnome)
{
    int f = 0, i = 0;
    while (i < CITY)
    {
        if (COST[gnome[i] - 48][gnome[i + 1] - 48] == 1000)
            cout << endl
                 << "1000 Found !!";
        if (COST[gnome[i] - 48][gnome[i + 1] - 48] != 1000)
        {
            f += COST[gnome[i] - 48][gnome[i + 1] - 48];
            i++;
        }
    }
    return f;
}

// returns the index of best fitness chromosome
int best_fitIndex(vector<struct chromosome> population)
{
    int best_fit = INT_MAX, i, j;
    for (i = 0; i < population.size(); i++)
    {
        if (population[i].fitness < best_fit)
        {
            best_fit = population[i].fitness;
            j = i;
        }
    }
    return j;
}

// Perform Roulette Wheel Selection and return true if the chromosome is selected
void rw_selection(vector<struct chromosome> &population, vector<struct chromosome> &new_population)
{
    // Randomly generate a float value between 0 and 1
    float r = rand() / static_cast<float>(RAND_MAX);
    int i;

    for (i = 0; i < population.size() - 1; i++)
    {
        if (r < population[0].qumulative_prob)
        {
            new_population.push_back(population[0]);
            break;
        }
        else if (r > population[i].qumulative_prob && r <= population[i + 1].qumulative_prob)
        {
            new_population.push_back(population[i + 1]);
            break;
        }
    }
}

// Takes two string and performs cyclic crossover to it and changes them to child of them
void cyclic_crossover(string *s1, string *s2)
{
    string parent1 = *s1, parent2 = *s2;
    string child1 = "-----------", child2 = "-----------";

    child1[0] = parent1[0];
    child2[0] = parent2[0];
    int i = 0, j;
    char a = parent2[i];
    while (a != parent1[0])
    {
        a = parent2[i];
        for (j = 0; j < parent1.size(); j++)
        {
            if (parent1[j] == a)
            {
                i = j;
                child1[i] = parent1[i];
                child2[i] = parent2[i];
            }
        }
    }

    for (i = 1; i < parent1.size(); i++)
    {
        if ('-' == child1[i])
            child1[i] = parent2[i];
        if ('-' == child2[i])
            child2[i] = parent1[i];
    }

    *s1 = child1;
    *s2 = child2;
}

// Prints the chromosomes
void display_population(chromosome p)
{
    int j;
    for (j = 0; j < p.gnome.size(); j++)
    {
        if (j != p.gnome.size() - 1)
            cout << p.gnome[j] << " -> ";
        else
            cout << p.gnome[j];
    }
    cout << "\t\t" << p.fitness << endl;
}