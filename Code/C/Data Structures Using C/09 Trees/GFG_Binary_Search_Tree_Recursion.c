// C program to demonstrate
// delete operation in binary
// search tree
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int key;
    struct node *left, *right;
};

struct node *root = NULL;


// A utility function to create a new BST node
struct node *newNode(int item)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// A utility function to do inorder traversal of BST
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        inorder(root->left);
        inorder(root->right);
    }
}

void postorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        inorder(root->right);
        printf("%d ", root->key);
    }
}

/* A utility function to
insert a new node with given key in
* BST */
struct node *insert(struct node *node, int key)
{
    /* If the tree is empty, return a new node */
    if (node == NULL)
        return newNode(key);

    /* Otherwise, recur down the tree */
    if (key < node->key)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);

    /* return the (unchanged) node pointer */
    return node;
}

/* Given a non-empty binary search
tree, return the node
with minimum key value found in
that tree. Note that the
entire tree does not need to be searched. */
struct node *minValueNode(struct node *node)
{
    struct node *current = node;

    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

/* Given a binary search tree
and a key, this function
deletes the key and
returns the new root */
struct node *deleteNode(struct node *root, int key)
{
    // base case
    if (root == NULL)
        return root;

    // If the key to be deleted
    // is smaller than the root's
    // key, then it lies in left subtree
    if (key < root->key)
        root->left = deleteNode(root->left, key);

    // If the key to be deleted
    // is greater than the root's
    // key, then it lies in right subtree
    else if (key > root->key)
        root->right = deleteNode(root->right, key);

    // if key is same as root's key,
    // then This is the node
    // to be deleted
    else
    {
        // node with only one child or no child
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        // node with two children:
        // Get the inorder successor
        // (smallest in the right subtree)
        struct node *temp = minValueNode(root->right);

        // Copy the inorder
        // successor's content to this node
        root->key = temp->key;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

// Driver Code
int main()
{
    /* Let us create following BST
            50
        /	 \
        30	 70
        / \ / \
    20 40 60 80 */

    // root = insert(root, 50);
    // root = insert(root, 30);
    // root = insert(root, 20);
    // root = insert(root, 40);
    // root = insert(root, 70);
    // root = insert(root, 60);
    // root = insert(root, 80);

    // printf("Inorder traversal of the given tree \n");
    // inorder(root);

    // printf("\nDelete 20\n");
    // root = deleteNode(root, 20);
    // printf("Inorder traversal of the modified tree \n");
    // inorder(root);

    // printf("\nDelete 30\n");
    // root = deleteNode(root, 30);
    // printf("Inorder traversal of the modified tree \n");
    // inorder(root);

    // printf("\nDelete 50\n");
    // root = deleteNode(root, 50);
    // printf("Inorder traversal of the modified tree \n");
    // inorder(root);



    int option, val;
    system("cls");
    do
    {
        printf("\n ****** MENU ******* \n");
        printf("\n 1. Insert Element");
        printf("\n 2. Preorder Traversal");
        printf("\n 3. Inorder Traversal");
        printf("\n 4. Postorder Traversal");
        printf("\n 5. Find the smallest element");
        printf("\n 6. Find the largest element");
        printf("\n 7. Delete an element");
        printf("\n 8. Count the total number of nodes");
        printf("\n 9. Count the total number of external nodes");
        printf("\n 10. Count the total number of internal nodes");
        printf("\n 11. Determine the height of the tree");
        printf("\n 12. Find the mirror image of the tree");
        printf("\n 13. Delete the tree");
        printf("\n 14. Exit");
        printf("\n\n Enter your option : ");

        scanf("%d", &option);
        system("CLS");

        switch (option)
        {
        case 1:
            printf("\n Enter the value of the new node : ");
            scanf("%d", &val);
            root = insert(root, val);
            break;
        case 2:
            printf("\n The elements of the tree are : \n");
            preorder(root);
            break;
        case 3:
            printf("\n The elements of the tree are : \n");
            inorder(root);
            break;
        case 4:
            printf("\n The elements of the tree are : \n");
            postorder(root);
            break;
        // case 5:
        //     ptr = findSmallestElement(tree);
        //     printf("\n Smallest element is :%d", ptr->data);
        //     break;
        // case 6:
        //     ptr = findLargestElement(tree);
        //     printf("\n Largest element is : %d", ptr->data);
        //     break;
        case 7:
            printf("\n Enter the element to be deleted : ");
            scanf("%d", &val);
            root = deleteNode(root, val);
            break;
        // case 8:
        //     printf("\n Total no. of nodes = %d", totalNodes(tree));
        //     break;
        // case 9:
        //     printf("\n Total no. of external nodes = %d",
        //            totalExternalNodes(tree));
        //     break;
        // case 10:
        //     printf("\n Total no. of internal nodes = %d",
        //            totalInternalNodes(tree));
        //     break;
        // case 11:
        //     printf("\n The height of the tree = %d", Height(tree));
        //     break;
        // case 12:
        //     tree = mirrorImage(tree);
        //     break;
        // case 13:
        //     tree = deleteTree(tree);
        //     break;
        }
    } while (option != 14);

    return 0;
}