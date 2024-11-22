#include <stdio.h>
#include <limits.h>

#define MAX 100
#define INF INT_MAX

void dijkstra(int n, int graph[MAX][MAX], int start) {
    int distance[MAX];
    int visited[MAX] = {0};

     
    for (int i = 0; i < n; i++) {
        distance[i] = INF;
    }
    distance[start] = 0;

    for (int count = 0; count < n - 1; count++) {
        int min = INF, min_index;
        for (int v = 0; v < n; v++) {
            if (!visited[v] && distance[v] <= min) {
                min = distance[v];
                min_index = v;
            }
        }

        int u = min_index;
        visited[u] = 1;

       
        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] != INF && distance[u] != INF &&
                distance[u] + graph[u][v] < distance[v]) {
                distance[v] = distance[u] + graph[u][v];
            }
        }
    }

    printf("Vertex\tDistance from Start\n");
    for (int i = 0; i < n; i++) {
        if (distance[i] == INF) {
            printf("%d\tINF\n", i);
        } else {
            printf("%d\t%d\n", i, distance[i]);
        }
    }
}

int main() {
    int n, start;
    int graph[MAX][MAX];

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (enter 0 if no edge exists):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == 0 && i != j) {
                graph[i][j] = INF;
            }
        }
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &start);

    dijkstra(n, graph, start);

    return 0;
}
