#include <stdio.h>
#include <stdlib.h>
#define INFINITY 9999
#define MAX 20

int G[MAX][MAX], spanning[MAX][MAX], n;

int prims();

int main() {
    int i, j, total_cost;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("\nEnter the adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &G[i][j]);

    total_cost = prims();

    printf("\nSpanning tree matrix:\n");
    for (i = 0; i < n; i++) {
        printf("\n");
        for (j = 0; j < n; j++)
            printf("%d\t", spanning[i][j]);
    }

    printf("\n\nTotal cost of the spanning tree = %d", total_cost);

    return 0;
}

int prims() {
    int cost[MAX][MAX], distance[MAX], from[MAX], visited[MAX];
    int u, v, min_distance, min_cost = 0, no_of_edges = n - 1, i, j;

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) {
            cost[i][j] = (G[i][j] == 0) ? INFINITY : G[i][j];
            spanning[i][j] = 0;
        }

    distance[0] = 0;
    visited[0] = 1;

    for (i = 1; i < n; i++) {
        distance[i] = cost[0][i];
        from[i] = 0;
        visited[i] = 0;
    }

    while (no_of_edges > 0) {
        min_distance = INFINITY;

        for (i = 1; i < n; i++) {
            if (!visited[i] && distance[i] < min_distance) {
                v = i;
                min_distance = distance[i];
            }
        }

        u = from[v];
        spanning[u][v] = spanning[v][u] = distance[v];
        no_of_edges--;
        visited[v] = 1;

        for (i = 1; i < n; i++) {
            if (!visited[i] && cost[i][v] < distance[i]) {
                distance[i] = cost[i][v];
                from[i] = v;
            }
        }

        min_cost += cost[u][v];
    }

    return min_cost;
}
