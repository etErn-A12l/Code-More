This is a C program that implements topological sorting, which is an algorithm that can be used to sort the vertices in a directed acyclic graph (DAG) such that for every directed edge uv, vertex u comes before v in the ordering.

The code starts by including two standard libraries: stdio.h and stdlib.h. It also defines a constant MAX_VERTICES as 100 using the #define preprocessor directive. 

Next, a struct called Node is defined, which has two members: an integer vertex and a pointer to another Node struct. This is a singly linked list implementation where each node represents a vertex in the graph and its next vertex. 

The code then initializes some global variables: an array of pointers to Node structs called graph, an array of integers called visited, and an array of integers called topoOrder. The variable top is initialized to -1.

The function addEdge adds an edge to the graph by creating a new Node struct with the destination vertex v and adding it to the adjacency list of the source vertex u.

The function dfs performs a depth-first search starting from vertex v. It marks v as visited, processes all adjacent vertices recursively, and adds v to the topoOrder array after all its adjacent vertices have been explored.

The function topologicalSort initializes the visited array and calls dfs on each unvisited vertex in the graph. Once all vertices have been visited, it prints the vertices in the order they were added to the topoOrder array.

In the main function, the user is prompted to enter the number of vertices and edges in the graph. The graph is then initialized by setting all elements of the graph array to NULL. The user is then prompted to enter each edge in the graph by specifying the source and destination vertices. Finally, topologicalSort is called to perform the sorting and print the resulting order.

Overall, this program takes a directed acyclic graph as input and outputs a topological ordering of its vertices.


This is a C program that implements topological sorting for a directed graph. Here is the explanation of each line of code:

1. `#include <stdio.h>`: This is a preprocessor directive that includes the standard input-output header file in the program.
2. `#include <stdlib.h>`: This is a preprocessor directive that includes the standard library header file in the program.
3. `#define MAX_VERTICES 100`: This is a macro definition that defines the maximum number of vertices that can be present in the graph as 100.
4. `typedef struct Node {...} Node;`: This defines a structure called `Node` which represents a node in the adjacency list of the graph. It contains the vertex number and a pointer to the next node.
5. `Node *graph[MAX_VERTICES];`: This declares an array of pointers to Node structures, which will represent the adjacency list of the given graph.
6. `int visited[MAX_VERTICES];`: This declares an integer array `visited` of size `MAX_VERTICES`, which will store whether a particular vertex has been visited during the depth-first search traversal or not.
7. `int topoOrder[MAX_VERTICES];`: This declares an integer array `topoOrder` of size `MAX_VERTICES`, which will store the topological order of the vertices in the graph.
8. `int top = -1;`: This initializes a variable `top` with value -1, which will be used as a pointer to the top of the `topoOrder` stack.
9. `void addEdge(int u, int v) {...}`: This is a function that takes two integers `u` and `v` as parameters, and adds an edge between the vertices `u` and `v` in the adjacency list of the graph.
10. `void dfs(int v) {...}`: This is a recursive function that performs the depth-first search traversal of the graph starting from the vertex `v`.
11. `void topologicalSort(int numVertices) {...}`: This is a function that performs the topological sorting of the given graph and prints the vertices in the topologically sorted order.
12. `int main() {...}`: This is the main function of the program, where the user inputs the number of vertices and edges of the graph, as well as the edges themselves using the `addEdge` function, and then calls the `topologicalSort` function to print the vertices in the topologically sorted order.

I hope this helps! Let me know if you have any further questions.