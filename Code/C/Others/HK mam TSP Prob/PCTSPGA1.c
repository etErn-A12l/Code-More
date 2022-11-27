/*Truth Is Beauty*/
/*  crisp(simple)TSP solve by GA With RW selection,Cyclic Cross Over without any constraint*/
/*  node=85,maxgen=500,pc=0.4,pm=0.3,seed=9,the optimum result found at the generation=470,optimal cost=99.00,pat:5-3-2-6-7-1-9-4-8-0*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>

#define node 10
#define noc 85 // noc= no of chromosome//
#define maxgen 500
#define pc 0.4
#define pm 0.3

/*float COST[node][node][3]={{{1000,1100,1200},{15,16,17},{30,32,35},{4,4.5,5}},
{{6,7,8},{1000,1100,1200},{4,4.5,5},{1,1.24,1.5}},
{{10,12,13},{15,17,18},{1000,1100,1200},{16,17,18}},
{{7,8,9},{18,20,22},{13,14,15},{1000,1100,1200}}};*/
/*float COST[node][node]={{1000,2,5,7,1},{6,1000,3,8,2},{8,7,1000,4,7},{12,4,6,1000,5},{1,3,2,8,1000}}; */
/*float COST[node][node]={{1000,12,15,10,8},{8,1000,15,12,8},{9,11,1000,15,11},{7,12,19,1000,11},{9,12,16,10,1000}}; */

float COST[node][node] = {{1000, 25, 28, 32, 20, 6, 35, 37, 40, 30}, {37, 1000, 20, 28, 35, 40, 30, 42, 28, 4}, {42, 28, 1000, 30, 25, 35, 9, 32, 40, 30}, {28, 30, 7, 1000, 20, 25, 30, 35, 22, 37}, {37, 22, 35, 30, 1000, 20, 25, 30, 9, 28}, {25, 30, 25, 8, 28, 1000, 32, 40, 32, 30}, {28, 25, 30, 22, 37, 40, 1000, 10, 32, 20}, {20, 5, 32, 40, 35, 25, 40, 1000, 22, 37}, {30, 40, 35, 25, 20, 22, 37, 32, 1000, 28}, {28, 30, 28, 20, 11, 32, 37, 40, 30, 1000}};
float cumuprob[50], prob[50];

int nparr[100], g; /* new population array*/

double TOU[10][10], total;

struct chrom
{
	int pt[node];
	float fitness;
} ch[noc];

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
	int seed, i, j, t2, path[20], j1, flag;
	int z, r, p, z1[node];
	int count, x, y, pv = 0;
	float y1, y2[2];
	system("cls");
	printf("\nPlease enter seed:");
	scanf("%d", &seed);

	srand(seed);
	for (i = 0; i < node; i++)
		for (j = 0; j < node; j++)
			TOU[i][j] = 1 / COST[i][j];
	for (i = 0; i < noc; i++)
	{
		t2 = 0;
		path[t2] = 1;
		t2++;
		//	 printf("\nt2=%d,i=%d",t2,i);
	v:
		r = rand() % node;
		// printf("r=%d",r);
		flag = 1;
		for (j1 = 0; j1 < t2; j1++)
			if (r == path[j1])
				flag = 0;

		if (flag == 1)
		{
			path[t2] = r;
			t2++;
		}
		// printf("tt2=%d",t2);
		if (t2 == node)
			goto k;
		goto v;

	k:
		// printf("Path=%d ",i);
		for (z = 0; z < t2; z++)
			//	printf("%d\t",path[z]);
			//	printf("\n");
			/* cheak that it is repeated path or not*/
			for (z = 0; z < node; z++)
				ch[i].pt[z] = path[z];
		for (x = 0; x < i; x++)
		{
			count = 0;
			for (y = 0; y < node; y++)
			{
				if (path[y] == ch[x].pt[y])
					count++;
			}

			if (count == node)
				goto skip;
		}

		/* for(z=0;z<node;z++)
		 ch[i].pt[z]=path[z]; */

		for (z = 0; z < node; z++)
			popu[pv].pt[z] = path[z];

		pv++;
	skip:
	
	}

	/* for(i=0;i<noc;i++)
		{
		   for(j=0;j<node;j++)
		   printf("11 %d ",ch[i].pt[j]);
		   printf("\n");
		}
		   */
	printf("\nsize of popu: %d", pv);
	printf("\n");

	//	for(i=0;i<pv;i++)  /* here pv is the  no of chromosome*/
	// {
	//	for(j=0;j<node;j++)
	//	printf(" %d ",popu[i].pt[j]);
	//	printf("\n");
	// }
	// fpopu[0]=10000;
	/* APPLY GENETIC LGORITHM */
	y2[0] = 10000;
	for (g = 1; g <= maxgen; g++)
	{
		// printf("\nGeneration=%d\n",g);
		calfitness(pv);
		selection(pv);
		crossover(pv);
		mutation(pv);
		y1 = check(pv);
		// y2[0]=y1;
		if (y2[0] > y1)
		{
			y2[0] = y1;
			p = g;
			for (j = 0; j < node; j++)
			{
				z1[j] = fpopu[0].pt[j];
			}
			// printf("\nff final fitness y2[%d]= %f\n",p,y2[0]);
		}
		printf("\nGlobal Best=%f\n", y2[0]);
		// getch();
	}

	printf("\nOptimum Result Found At TheGeneration=%d\n", p);
	printf("\nOptimum Value=%f\n", y2[0]);
	printf("\nFinal path\n");
	for (j = 0; j < node; j++)
		printf("%d\t", z1[j]);
	// getch();
}

void calfitness(int pv)
{
	int i, j;
	float sum;

	for (i = 0; i < pv; i++)
	{
		sum = 0;
		for (j = 0; j < node - 1; j++)
			sum = sum + COST[popu[i].pt[j]][popu[i].pt[j + 1]];
		sum = sum + COST[popu[i].pt[node - 1]][popu[i].pt[0]];
		popu[i].fitness = sum;
		//	 fpopu[i].fitness=sum;
	}

	for (i = 0; i < pv; i++)
	{
		fpopu[i].fitness = 1000;
		for (j = 0; j < node; j++)
			printf("%d\t", popu[i].pt[j]);
		printf("\nfittness  %d=%f\n", i, popu[i].fitness);
	}
	// getch();
}

void selection(int pv)
{

	float r, b[10], a, k;
	double p, t;
	int i, j, z, t0;
	b[0] = 10000;
	for (i = 1; i < pv; i++)
	{
		if (popu[i].fitness < b[0])
		{
			b[0] = popu[i].fitness;
			z = i;
		}
	}
	printf("\nBest Fitted String %d=%f\n", z, b[0]);
a1:
	// t0 = random(101);
	srand(101);
	t0 = rand();
	if (t0 == 0 || t0 == 1 || t0 == 2 || t0 == 3 || t0 == 4 || t0 == 5)
		goto a1;
	r = (rand() % 1000) / 1000.;
	a = r;
	printf("\nG= %d  A=%f    T0  =%d", g, a, t0);
	p = (float)((float)g / (float)maxgen);
	k = (1 + 100.0 * p);
	t = t0 * pow((1 - a), k);
	printf("  T=%f   k=%f p=%1.5f\n", t, k, p);
	for (i = 0; i < pv; i++)
	{
		r = (rand() % 1000) / 1000.;
		if ((b[0] - popu[i].fitness) >= 0)
		{
			//	printf("i=%d first\n",i);
			npopu[i].fitness = popu[i].fitness;
			for (j = 0; j < node; j++)
				npopu[i].pt[j] = popu[i].pt[j];
		}

		else if (exp((b[0] - popu[i].fitness) / t) > r)
		{
			// printf("i=%d2nd\n",i);
			npopu[i].fitness = popu[i].fitness;
			for (j = 0; j < node; j++)
				npopu[i].pt[j] = popu[i].pt[j];
		}
		else
		{
			// printf("i=%dthird\n",i);
			npopu[i].fitness = popu[z].fitness;
			for (j = 0; j < node; j++)
				npopu[i].pt[j] = popu[z].pt[j];
		}
	}

	/* RW Selection*/
	/* for( i=0;i<pv;i++)
				s+=popu[i].fitness;

	 for( i=0;i<pv;i++)
		   prob[i]=popu[i].fitness/s;

		s=0;
	   for(i=0;i<pv;i++)
		 {
		   s=s+prob[i];
		 cumuprob[i]=s;
		}
		for(i=0;i<pv;i++)
		// printf("cump=%f\t ",cumuprob[i]);

	   count=0;

		   for(i=0;i<pv;i++)
	   {
		   r=(rand()%1000)/1000.	;
		 //	printf("%f",r);
			for(k=0;k<pv;k++)
			{
			   if(r<cumuprob[k])
			 {
				nparr[count]=k;
			 //	printf("%d",k);
				count++;
				goto u;
			   }
		   }
		 u:
	   } */
	/*printf("pos:");
   for(i=0;i<pv;i++)
   printf("%d\t",nparr[i]);   */

	/*	 for(i=0;i<pv;i++)
		  {
			   p=nparr[i];
			  for(j=0;j<node;j++)
			   npopu[i].pt[j]=popu[p].pt[j];
		   }   */
	// display //
	// printf("\nSelective population\n");
	//	  for(i=0;i<pv;i++)
	// {
	//	printf(" after f%d=%f\n",i,npopu[i].fitness);
	//	 printf("pos=%d  ",nparr[i]);
	//	for(j=0;j<node;j++)

	//	printf("%d\t",npopu[i].pt[j]);
	//	printf("\n");

	// }
	// getch();
}

void crossover(int pv)
{
	int i, pos[2], count = 0;
	float r;
	for (i = 0; i < pv; i++)
	{
		r = (rand() % 1000) / 1000.;
		//	 printf("r=%f",r);
		if (r <= pc)
		{
			pos[count] = i;
			count++;
			//	printf("count=%d",count);
			if (count == 2)
			{
				// printf("\npos[0]=%d,pos[1]=%d\n",pos[0],pos[1]);
				cross(pos[0], pos[1], pv);
				count = 0;
			}
		}
	}
	// display //
	/*  printf("\nafter cross over\n");
	 for(i=0;i<pv;i++)
	  {
		for(int j=0;j<node;j++)
		printf("%d\t",npopu[i].pt[j]);
		getch();
		printf("\n");
	 } */
}

void cross(int p0, int p1, int pv)
{
	int i, j, pos, temp, l, m;
	int pr1[node], ch1[node], pr2[node], ch2[node], pr11[node], pr21[node];
	//	 printf("\n");
	// copy 1st chromosome into pr1[]
	for (i = 0; i < pv; i++)
	{
		if (p0 == i)
		{
			for (j = 0; j < node; j++)
			{
				pr1[j] = npopu[i].pt[j];
				printf("%d ", pr1[j]);
			}
		}
	}
	printf("\n\n");

	// copy 2nd  chromosome into pr2[]
	for (i = 0; i < pv; i++)
	{
		if (p1 == i)
		{
			for (j = 0; j < node; j++)
			{
				pr2[j] = npopu[i].pt[j];
				printf("%d ", pr2[j]);
			}
		}
	}
	// printf("\n\n");
	/* for(i=0;i<node;i++)
	 {
	  printf("%d ",pr1[i]);
	  }
	  printf("\n");
		 for(i=0;i<node;i++)
		 {
		printf("%d ",pr2[i]);
		}   */

	//  cross general method//

	//	printf("cross pos=%d\n",pos);
	for (i = 0; i < node; i++)
	{
		ch1[i] = 10000;
		ch2[i] = 10000;
	}
	/* AS Crossover  */

	// pos = random(node);
	srand(node);
	pos = rand();
	printf("Pos=%d ", pos);
	for (j = 0; j < node; j++)
	{
		if (pos == pr1[j])
		{
			l = j;
		}
	}
	for (j = l; j > 0; j--)
	{
		pr1[j] = pr1[j - 1];
	}
	pr1[0] = pos;

	printf("\nThe first parents\n");
	for (j = 0; j < node; j++)
	{
		printf("%d  ", pr1[j]);
	}
	for (j = 0; j < node; j++)
	{
		if (pos == pr2[j])
		{
			l = j;
		}
	}
	for (j = l; j > 0; j--)
	{
		pr2[j] = pr2[j - 1];
	}
	pr2[0] = pos;

	printf("\nThe second parents\n");
	for (j = 0; j < node; j++)
	{
		printf("%d  ", pr2[j]);
	}
	ch1[0] = pos;
	i = 1;
	j = 1;
	m = 1;
	while ((i < node) && (j < node))
	{
		if ((COST[ch1[m - 1]][pr1[i]]) == (COST[ch1[m - 1]][pr2[j]]))
		{
			ch1[m] = pr1[i];
			i = i + 1;
			j = j + 1;
			if (i > j)
			{
				m = i;
			}
			else
			{
				m = j;
			}
		}
		else if ((COST[ch1[m - 1]][pr1[i]]) < (COST[ch1[m - 1]][pr2[j]]))
		{
			ch1[m] = pr1[i];
			i = i + 1;
			if (i > j)
			{
				m = i;
			}
			else
			{
				m = j;
			}
		}

		else
		{
			ch1[m] = pr2[j];
			j = j + 1;
			if (i > j)
			{
				m = i;
			}
			else
			{
				m = j;
			}
		}
	}
	printf("The First Child: ");
	for (j = 0; j < node; j++)
		printf("%d ", ch1[j]);
	/* For  The Second  Child*/

	// getch();
	/* AS Crossover  */
	// pos=random(node) ;
	//	printf("\nPos=%d ",pos);
	for (j = 0; j < node; j++)
	{
		if (pos == pr1[j])
		{
			l = j;
		}
	}
	for (j = l; j < node; j++)
	{
		pr1[j] = pr1[j + 1];
	}
	pr1[node - 1] = pos;

	//	printf("\nThe 2nd first parents\n");
	for (j = 0; j < node; j++)
	{
		pr11[j] = pr1[j];
	}
	temp = node;
	for (j = 0; j < node; j++)
	{
		pr1[j] = pr11[temp - 1];
		temp = temp - 1;
	}
	/*for(j=0;j<node;j++)
	{
	printf("%d  ",pr1[j]);
	}*/

	for (j = 0; j < node; j++)
	{
		if (pos == pr2[j])
		{
			l = j;
		}
	}
	for (j = l; j < node; j++)
	{
		pr2[j] = pr2[j + 1];
	}
	pr2[node - 1] = pos;

	//	printf("\nThe 2nd Second parents\n");
	for (j = 0; j < node; j++)
	{
		pr21[j] = pr2[j];
	}
	temp = node;
	for (j = 0; j < node; j++)
	{
		pr2[j] = pr21[temp - 1];
		temp = temp - 1;
	}
	/*	for(j=0;j<node;j++)
	  {
	  printf("%d  ",pr2[j]);
	  } */

	ch2[0] = pos;
	i = 1;
	j = 1;
	m = 1;
	while ((i < node) && (j < node))
	{
		if ((COST[ch1[m - 1]][pr1[i]]) == (COST[ch1[m - 1]][pr2[j]]))
		{
			ch2[m] = pr1[i];
			i = i + 1;
			j = j + 1;
			if (i > j)
			{
				m = i;
			}
			else
			{
				m = j;
			}
		}
		else if ((COST[ch1[m - 1]][pr1[i]]) < (COST[ch1[m - 1]][pr2[j]]))
		{
			ch2[m] = pr1[i];
			i = i + 1;
			if (i > j)
			{
				m = i;
			}
			else
			{
				m = j;
			}
		}

		else
		{
			ch2[m] = pr2[j];
			j = j + 1;
			if (i > j)
			{
				m = i;
			}
			else
			{
				m = j;
			}
		}
	}
	/* printf("The First Child: ");
	 for(j=0;j<node;j++)
	 printf("%d ",ch1[j]); */
	printf("The Second Child: ");
	for (j = 0; j < node; j++)
		printf("%d ", ch2[j]);
	// getch();
	/* cyclic crossover for child1*/
	/*	for(i=0;i<node;i++)
		{
		  if(pr1[i]==pos)
			 {
				k=i;
		  l1:	temp=pr1[k];
				if(ch1[k]==temp)
				{
				 goto l2;
				}
				else
				{
				  ch1[k]=temp;
				  for(j=0;j<node;j++)
				  {
					if(pr2[j]==temp)
					{
					k=j;
					temp=pr1[k];
					goto l1;
					}
				  }
				}
			 }
		}
		l2: for(j=0;j<node;j++)
		{
		 if(ch1[j]!=pr1[j])
		 {
		 ch1[j]=pr2[j];
		 }
		} */
	/* Cyclic crossover for child2*/

	/* for(i=0;i<node;i++)
	{
	  if(pr2[i]==pos)
		 {
			k=i;
	  l12:	temp=pr2[k];
			if(ch2[k]==temp)
			{
			 goto l21;
			}
			else
			{
			  ch2[k]=temp;
			  for(j=0;j<node;j++)
			  {
				if(pr1[j]==temp)
				{
				k=j;
				temp=pr2[k];
				goto l12;
				}
			  }
			}
		 }
	}
	l21: for(j=0;j<node;j++)
	{
	 if(ch2[j]!=pr2[j])
	 {
	 ch2[j]=pr1[j];
	 }
	} */
	/*	  printf("\nAfter crossover\n");

		  for(i=0;i<node;i++)
		  printf("%d\t",ch1[i]);
		  printf("\n");
		  for(i=0;i<node;i++)
		  printf("%d\t",ch2[i]);   */

	/*	for(i=0;i<=pos;i++)
		   ch1[i]=pr1[i];
	   for(i=(pos+1);i<node;i++)
		   ch1[i]=pr2[i];

		  for(i=0;i<=pos;i++)
		   ch2[i]=pr2[i];
	   for(i=(pos+1);i<node;i++)
		   ch2[i]=pr1[i];
								*/
	// again copy 1st child chromosome to the population//
	for (i = 0; i < pv; i++)
	{
		if (p0 == i)
		{
			for (j = 0; j < node; j++)
				npopu[i].pt[j] = ch1[j];
		}
	}

	// again copy 2nd child chromosome to the population//
	for (i = 0; i < pv; i++)
	{
		if (p1 == i)
		{
			for (j = 0; j < node; j++)
				npopu[i].pt[j] = ch2[j];
		}
	}
}

void mutation(int pv)
{
	int i, p, j, i1;
	float r;
	for (i = 0; i < pv; i++)
	{
		r = (rand() % 1000) / 1000.;
		if (r <= pm)
		{
			p = i;
			mutate(p, pv);
		}
	}
	// copy new chromosome to the new population//
	// printf("\nAfter Mutation\n");

	for (i1 = 0; i1 < pv; i1++)
	{
		for (j = 0; j < node; j++)
		{
			popu[i1].pt[j] = npopu[i1].pt[j];
			fpopu[i1].pt[j] = npopu[i1].pt[j];
			// printf("%d\t",fpopu[i1].pt[j]);
		}
		//	printf("fittness %d=%f\n",i1,popu[i1].fitness);
		//	printf("\n");
	}

	calfitness(pv);
	for (i1 = 0; i1 < pv; i1++)
	{
		for (j = 0; j < node; j++)
		{
			popu[i1].pt[j] = npopu[i1].pt[j];
			fpopu[i1].pt[j] = npopu[i1].pt[j];
			// printf("%d\t",fpopu[i1].pt[j]);
		}
		//	printf("fittness %d=%f\n",i1,popu[i1].fitness);
		//	printf("\n");
	}
}

void mutate(int p, int pv)

{

	int i, j, a, b, c;
	int pr1[node];

	for (i = 0; i < pv; i++) // copy that chromosome into pr1[]//
	{
		if (p == i)
		{
			for (j = 0; j < node; j++)
				pr1[j] = npopu[i].pt[j];
		}
	}
	// mutate//
	a = rand() % (node - 1);
	b = rand() % (node - 1);
	if (a != b)
	{
		c = pr1[a];
		pr1[a] = pr1[b];
		pr1[b] = c;
	}

	// again copy this chromosome to the population//
	for (i = 0; i < pv; i++)
	{
		if (p == i)
		{
			for (j = 0; j < node; j++)
				npopu[i].pt[j] = pr1[j];
		}
	}
}
float check(int pv)
{
	int i, j, k;
	float y1;
	fpopu[0].fitness = 10000;
	for (i = 0; i < pv; i++)
	{
		if (popu[i].fitness < fpopu[0].fitness)
		{
			fpopu[0].fitness = popu[i].fitness;
			j = i;
			//	 printf("   %d=%f\n ",j,popu[j].fitness);
			for (k = 0; k < node; k++)
			{
				fpopu[0].pt[k] = popu[j].pt[k];
			}
			y1 = fpopu[0].fitness;
		}
	}

	// printf("\n Local Best=%f ,%d\n",fpopu[0].fitness,j);
	// getch();
	// for(i=0;i<node;i++)
	// printf("%d\t",fpopu[0].pt[i]);
	return (y1);
}
