#include <stdio.h>

struct node
{
    int data;
    struct node *left, *right;
};

void iterativePostorder(struct node *tree);
void iterativePreorder(struct node *tree);

int main(int argc, char const *argv[])
{

    return 0;
}

void iterativePostorder(struct node *tree)
{
    for (;;)
    {
        if (tree)
        {
            push(tree);
            tree = tree->left;
        }
        else
        {
            if (stackEmpty())
                break;
            else
            {
                if (peek()->right == NULL)
                {
                    tree = pop();
                    printf("%d ", tree->data);
                    while (tree == peek()->right)
                    {
                        print("%d ", peek()->data);
                        tree = pop();
                    }
                }
                if (!stackEmpty())
                    tree = peek()->right;
                else
                    tree = NULL;
            }
        }
    }
}

void iterativePreorder(struct node *tree)
{
    for(;;)
    {
        while(tree)
        {
            printf("%d",tree->data);
            push(tree);
            tree = tree->left;
        }
        if(stackEmpty())
            break;
        tree = pop();
        tree = tree->right;
    }
}