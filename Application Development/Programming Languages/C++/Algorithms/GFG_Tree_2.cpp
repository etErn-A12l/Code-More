/*
Binary Tree | Set 3 (Types of Binary Tree)
 
We have discussed Introduction to Binary Tree in set 1 and Properties of Binary Tree in Set 2. In this post, common types of Binary Trees are discussed. 

The following are common types of Binary Trees. 

Full Binary Tree A Binary Tree is a full binary tree if every node has 0 or 2 children. The following are the examples of a full binary tree. We can also say a full binary tree is a binary tree in which all nodes except leaf nodes have two children. 

               18
           /       \  
         15         30  
        /  \        /  \
      40    50    100   40

             18
           /    \   
         15     20    
        /  \       
      40    50   
    /   \
   30   50

               18
            /     \  
          40       30  
                   /  \
                 100   40
Complete Binary Tree: A Binary Tree is a Complete Binary Tree if all the levels are completely filled except possibly the last level and the last level has all keys as left as possible 

The following are examples of Complete Binary Trees 

               18
           /       \  
         15         30  
        /  \        /  \
      40    50    100   40


               18
           /       \  
         15         30  
        /  \        /  \
      40    50    100   40
     /  \   /
    8   7  9 
Practical example of Complete Binary Tree is Binary Heap. 

Perfect Binary Tree A Binary tree is a Perfect Binary Tree in which all the internal nodes have two children and all leaf nodes are at the same level. 
The following are the examples of Perfect Binary Trees. 

               18
           /       \  
         15         30  
        /  \        /  \
      40    50    100   40


               18
           /       \  
         15         30  
In a Perfect Binary Tree, the number of leaf nodes is the number of internal nodes plus 1   

 L = I + 1 Where L = Number of leaf nodes, I = Number of internal nodes.

A Perfect Binary Tree of height h (where the height of the binary tree is the number of edges in the longest path from the root node to any leaf node in the tree, height of root node is 0) has 2h+1 – 1 node. 

An example of a Perfect binary tree is ancestors in the family. Keep a person at root, parents as children, parents of parents as their children. 

Balanced Binary Tree 
A binary tree is balanced if the height of the tree is O(Log n) where n is the number of nodes. For Example, the AVL tree maintains O(Log n) height by making sure that the difference between the heights of the left and right subtrees is at most 1. Red-Black trees maintain O(Log n) height by making sure that the number of Black nodes on every root to leaf paths is the same and there are no adjacent red nodes. Balanced Binary Search trees are performance-wise good as they provide O(log n) time for search, insert and delete. 

A degenerate (or pathological) tree A Tree where every internal node has one child. Such trees are performance-wise same as linked list. 

      10
      /
    20
     \
     30
      \
      40 
*/

// C++ program for different tree traversals
#include <iostream>
using namespace std;

/* A binary tree node has data, pointer to left child
and a pointer to right child */
struct Node {
	int data;
	struct Node *left, *right;
};

//Utility function to create a new tree node
Node* newNode(int data)
{
	Node* temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

/* Given a binary tree, print its nodes according to the
"bottom-up" postorder traversal. */
void printPostorder(struct Node* node)
{
	if (node == NULL)
		return;

	// first recur on left subtree
	printPostorder(node->left);

	// then recur on right subtree
	printPostorder(node->right);

	// now deal with the node
	cout << node->data << " ";
}

/* Given a binary tree, print its nodes in inorder*/
void printInorder(struct Node* node)
{
	if (node == NULL)
		return;

	/* first recur on left child */
	printInorder(node->left);

	/* then print the data of node */
	cout << node->data << " ";

	/* now recur on right child */
	printInorder(node->right);
}

/* Given a binary tree, print its nodes in preorder*/
void printPreorder(struct Node* node)
{
	if (node == NULL)
		return;

	/* first print data of node */
	cout << node->data << " ";

	/* then recur on left subtree */
	printPreorder(node->left);

	/* now recur on right subtree */
	printPreorder(node->right);
}

/* Driver program to test above functions*/
int main()
{
	struct Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	cout << "\nPreorder traversal of binary tree is \n";
	printPreorder(root);

	cout << "\nInorder traversal of binary tree is \n";
	printInorder(root);

	cout << "\nPostorder traversal of binary tree is \n";
	printPostorder(root);

	return 0;
}
