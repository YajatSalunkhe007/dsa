/* This is the code for Prims Algorithm which is one of the algorithms to find
 the Minimum Spanning Tree */


 #include <stdio.h>

#define INF 999

int main()
{
    int n;
    int cost[10][10];
    int visited[10] = {0};
    int edges = 0;
    int totalCost = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix:\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);

            if (cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    visited[0] = 1;

    printf("\nEdges in Minimum Spanning Tree:\n");

    while (edges < n - 1)
    {
        int min = INF;
        int u = -1;
        int v = -1;

        for (int i = 0; i < n; i++)
        {
            if (visited[i])
            {
                for (int j = 0; j < n; j++)
                {
                    if (!visited[j] && cost[i][j] < min)
                    {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        visited[v] = 1;

        printf("%d - %d = %d\n", u + 1, v + 1, min);

        totalCost += min;
        edges++;
    }

    printf("\nMinimum Cost = %d\n", totalCost);

    return 0;
}