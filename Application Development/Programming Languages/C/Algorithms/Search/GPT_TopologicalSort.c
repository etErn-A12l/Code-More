#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct Node
{
    int vertex;
    struct Node *next;
} Node;

Node *graph[MAX_VERTICES];
int visited[MAX_VERTICES];
int topoOrder[MAX_VERTICES];
int top = -1;

void addEdge(int u, int v)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = graph[u];
    graph[u] = newNode;
}

void dfs(int v)
{
    visited[v] = 1;
    Node *temp = graph[v];
    while (temp != NULL)
    {
        int adjVertex = temp->vertex;
        if (!visited[adjVertex])
        {
            dfs(adjVertex);
        }
        temp = temp->next;
    }
    topoOrder[++top] = v;
}

void topologicalSort(int numVertices)
{
    for (int i = 0; i < numVertices; i++)
    {
        visited[i] = 0;
    }
    for (int i = 0; i < numVertices; i++)
    {
        if (!visited[i])
        {
            dfs(i);
        }
    }
    printf("Topological order: ");
    while (top >= 0)
    {
        printf("%d ", topoOrder[top--]);
    }
}

int main()
{
    int numVertices, numEdges;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &numVertices, &numEdges);
    for (int i = 0; i < numVertices; i++)
    {
        graph[i] = NULL;
    }
    printf("Enter edges:\n");
    for (int i = 0; i < numEdges; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }
    topologicalSort(numVertices);
    return 0;
}
