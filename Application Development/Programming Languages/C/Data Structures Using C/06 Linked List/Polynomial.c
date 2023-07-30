#include <stdio.h>
#include <stdlib.h>

struct node
{
	int exp;
	float coeff;
	struct node *next;
};

struct node *create(struct node *);
struct node *insertNode(struct node *, float co, int ex);
void display(struct node *);
void polyAdd(struct node *, struct node *);
struct node *insertRes(struct node *, float co, int ex);

int main()
{
	struct node *head1 = NULL, *head2 = NULL;

	printf("\nEnter the first polynomial :\n");
	head1 = create(head1);
	printf("\nEnter the second polynomial :\n");
	head2 = create(head2);

	printf("\n\nThe Polynomial 1 is below\n");
	display(head1);
	printf("\n\nThe Polynomial 2 is below\n");
	display(head2);

	polyAdd(head1, head2);

	return 0;
}

struct node *create(struct node *head)
{
	int ex, n, i;
	float co;
	printf("\nEnter the number of terms: ");
	scanf("%d", &n);

	for (i = 1; i <= n; i++)
	{
		printf("\n\tEnter the coefficient for %dth term: ", i);
		scanf("%f", &co);
		printf("\n\tEnter the exponent for %dth term: ", i);
		scanf("%d", &ex);

		head = insertNode(head, co, ex);
	}
	return head;
}

struct node *insertNode(struct node *head, float co, int ex)
{
	struct node *tmp;
	tmp = (struct node *)malloc(sizeof(struct node));
	tmp->coeff = co;
	tmp->exp = ex;

	if (head == NULL || ex > head->exp)
	{
		tmp->next = head;
		head = tmp;
	}
	else
	{
		struct node *ptr = head;
		while (ptr->next != NULL && ptr->next->exp >= ex)
			ptr = ptr->next;
		tmp->next = ptr->next;
		ptr->next = tmp;
	}
	return head;
}

void display(struct node *ptr)
{
	if (ptr == NULL)
	{
		printf("\nPolynomial is EMPTY !");
		return;
	}
	else
	{
		while (ptr != NULL)
		{
			printf("%.1fx^%d", ptr->coeff, ptr->exp);

			if (ptr->next != NULL)
				printf(" + ");
			// else if(ptr->next != NULL && ptr->next->coeff >= 0)
			// 	printf(" + ");
			ptr = ptr->next;
		}
	}
}

void polyAdd(struct node *ptr1, struct node *ptr2)
{
	struct node *resNode = NULL;
	while (ptr1 != NULL && ptr2 != NULL)
	{
		if (ptr1->exp > ptr2->exp)
		{
			resNode = insertRes(resNode, ptr1->coeff, ptr1->exp);
			ptr1 = ptr1->next;
		}
		else if (ptr2->exp > ptr1->exp)
		{
			resNode = insertRes(resNode, ptr2->coeff, ptr2->exp);
			ptr2 = ptr2->next;
		}
		else if (ptr1->exp == ptr2->exp)
		{
			resNode = insertRes(resNode, ptr1->coeff + ptr2->coeff, ptr1->exp);
			ptr1 = ptr1->next;
			ptr2 = ptr2->next;
		}
	}

	while (ptr1 != NULL)
	{
		resNode = insertRes(resNode, ptr1->coeff, ptr1->exp);
		ptr1 = ptr1->next;
	}

	while (ptr2 != NULL)
	{
		resNode = insertRes(resNode, ptr2->coeff, ptr2->exp);
		ptr2 = ptr2->next;
	}

	printf("\n\n\nThe Added Polynomial is below: \n");
	display(resNode);
}

struct node *insertRes(struct node *head, float co, int ex)
{
	struct node *tmp;
	tmp = (struct node *)malloc(sizeof(struct node));
	tmp->coeff = co;
	tmp->exp = ex;
	if (head == NULL)
	{
		head = tmp;
		head->next = NULL;
	}
	else
	{
		struct node *ptr = head;

		while (ptr->next != NULL)
			ptr = ptr->next;

		tmp->next = ptr->next;
		ptr->next = tmp;
	}

	return head;
}
