#include <stdio.h>
#include <malloc.h>

struct node
{
    int val;
    struct node *left;
    struct node *right;
};

struct node *tree;

void create_tree(struct node *tree);
struct node *insert_element(struct node *tree);
void Preorder_display(struct node *tree);
void Inorder_display(struct node *tree);
void Postorder_display(struct node *tree);

int main(int argc, char const *argv[])
{
    int option;
    struct node *ptr;
    create_tree(tree);
    do
    {
        printf("\n\n ****** MENU ******* \n");
        printf("\n 1. Insert Element");
        printf("\n 2. Preorder Traversal");
        printf("\n 3. Inorder Traversal");
        printf("\n 4. Postorder Traversal");
        // printf("\n 5. Find the smallest element");
        // printf("\n 6. Find the largest element");
        // printf("\n 7. Delete an element");
        // printf("\n 8. Count the total number of nodes");
        // printf("\n 9. Count the total number of external nodes");
        // printf("\n 10. Count the total number of internal nodes");
        // printf("\n 11. Determine the height of the tree");
        // printf("\n 12. Find the mirror image of the tree");
        // printf("\n 13. Delete the tree");
        printf("\n 14. Exit");
        printf("\n\n Enter your option : ");

        scanf("%d", &option);

        switch (option)
        {
        case 1:
            tree = insert_element(tree);
            break;
        case 2:
            printf("\n The elements of the tree are : \n");
            Preorder_display(tree);
            break;
        case 3:
            printf("\n The elements of the tree are : \n");
            Inorder_display(tree);
            break;
        case 4:
            printf("\n The elements of the tree are : \n");
            Postorder_display(tree);
            break;
        }
    } while (option < 5);
    return 0;
}

void create_tree(struct node *tree)
{
    tree = NULL;
}

struct node *insert_element(struct node *tree)
{
    struct node *ptr, *nodeptr, *parentptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    int val;
    printf("Enter the value: ");
    scanf("%d",&val);
    ptr->val = val;
    ptr->left = NULL;
    ptr->right = NULL;
    if (tree == NULL)
    {
        tree = ptr;
        tree->left = NULL;
        tree->right = NULL;
    }
    else
    {
        parentptr = NULL;
        nodeptr = tree;

        while (nodeptr != NULL)
        {
            parentptr = nodeptr;
            if (val < nodeptr->val)
                nodeptr = nodeptr->left;
            else
                nodeptr = nodeptr->right;
        }
        if (val < parentptr->val)
            parentptr->left = ptr;
        else
            parentptr->right = ptr;
    }
    return tree;
}

void Preorder_display(struct node *tree)
{
    if (tree != NULL)
    {
        printf("%d\t", tree->val);
        Preorder_display(tree->left);
        Preorder_display(tree->right);
    }
}

void Inorder_display(struct node *tree)
{
    if (tree != NULL)
    {
        Preorder_display(tree->left);
        printf("%d\t", tree->val);
        Preorder_display(tree->right);
    }
}

void Postorder_display(struct node *tree)
{
    if (tree != NULL)
    {
        Preorder_display(tree->left);
        Preorder_display(tree->right);
        printf("%d\t", tree->val);
    }
}