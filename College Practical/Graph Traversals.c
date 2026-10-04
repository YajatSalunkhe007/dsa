/* This is a Simple code for Graph Traversals which includes Breadth-First Search
(BFS) and Depth-First Search (DFS) */


#include <stdio.h>

#define MAX 10

int graph[MAX][MAX];
int visited[MAX];
int n;

/* DFS Function */
void DFS(int vertex)
{
    int i;

    visited[vertex] = 1;
    printf("%d ", vertex);

    for (i = 0; i < n; i++)
    {
        if (graph[vertex][i] == 1 && visited[i] == 0)
        {
            DFS(i);
        }
    }
}

/* BFS Function */
void BFS(int start)
{
    int queue[MAX];
    int front = 0;
    int rear = 0;
    int i;

    /* Reset visited array */
    for (i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    /* Add starting vertex to queue */
    queue[rear] = start;
    rear++;

    visited[start] = 1;

    while (front < rear)
    {
        int vertex = queue[front];
        front++;

        printf("%d ", vertex);

        for (i = 0; i < n; i++)
        {
            if (graph[vertex][i] == 1 && visited[i] == 0)
            {
                queue[rear] = i;
                rear++;

                visited[i] = 1;
            }
        }
    }
}

int main()
{
    int edges;
    int u, v;
    int start;
    int i;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    /* Initialize graph */
    for (i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            graph[i][j] = 0;
        }
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v):\n");

    for (i = 0; i < edges; i++)
    {
        scanf("%d %d", &u, &v);

        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    /* DFS */
    for (i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    printf("\nDFS Traversal: ");
    DFS(start);

    /* BFS */
    printf("\nBFS Traversal: ");
    BFS(start);

    return 0;
}