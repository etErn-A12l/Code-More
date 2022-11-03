#include <stdio.h>
#include <stdlib.h>

struct bstNode
{
    int data;
    struct bstNode *left, *right;
};

struct bstNode *root = NULL, *temp = NULL;

struct bstNode *insert();
struct bstNode *allocate();
void insert_inside(struct bstNode *root);
void inorder(struct bstNode *);
void preorder(struct bstNode *);
void postorder(struct bstNode *);

int main()
{
    int option = 0;
    do
    {
        printf("\n\n**** MENU *****");
        printf("\n1. Insert Node");
        printf("\n2. Inorder Display");
        printf("\n3. Preorder Display");
        printf("\n4. Postorder Display");
        printf("\n\nEnter your choice: ");
        scanf("%d", &option);
        system("cls");
        switch (option)
        {
        case 1:
            root = insert();
            break;
        case 2:
            if (root == NULL)
                printf("\nTree is EMPTY !");
            else
            {
                printf("\nInorder Traversal: \n");
                inorder(root);
            }
            break;
        case 3:
            if (root == NULL)
                printf("\nTree is EMPTY !");
            else
            {
                printf("\nPreorder Traversal: \n");
                preorder(root);
            }
            break;
        case 4:
            if (root == NULL)
                printf("\nTree is EMPTY !");
            else
            {
                printf("\nPostorder Traversal: \n");
                postorder(root);
            }
            break;
        default:
            printf("\nWRONG Choice !");
            break;
        }
    } while (option < 5);

    return 0;
}

struct bstNode *insert()
{
    temp = allocate();
    if (root == NULL)
    {
        root = temp;
        return root;
    }
    else
    {
        insert_inside(root);
        return root;
    }
}

struct bstNode *allocate()
{
    temp = (struct bstNode *)malloc(sizeof(struct bstNode));
    printf("\nEnter the data for the new element: ");
    scanf("%d", &temp->data);
    temp->left = temp->right = NULL;
    return temp;
}

void insert_inside(struct bstNode *root)
{
    if (temp->data < root->data && root->left == NULL)
        root->left = temp;
    else if (temp->data < root->data && root->left != NULL)
        insert_inside(root->left);
    else if (temp->data > root->data && root->right == NULL)
        root->right = temp;
    else if (temp->data > root->data && root->right != NULL)
        insert_inside(root->right);
}

void inorder(struct bstNode *root)
{
    if (root != NULL)
    {
        inorder(root->left);        // 1
        printf("\t%d", root->data); // 2
        inorder(root->right);       // 3
    }
}

void preorder(struct bstNode *root)
{
    if (root != NULL)
    {
        printf("\t%d", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct bstNode *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("\t%d", root->data);
    }
}
