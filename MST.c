#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define INF 9999999

int parent[MAX];

int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void union1(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

void kruskalMST(int n, int cost[MAX][MAX]) {
    int mincost = 0;
    for (int i = 0; i < n; i++)
        parent[i] = i;

    int edge_count = 0;
    while (edge_count < n - 1) {
        int min = INF, a = -1, b = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (find(i) != find(j) && cost[i][j] < min) {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }

        union1(a, b);
        printf("Edge %d:(%d, %d) cost:%d \n", edge_count++, a, b, min);
        mincost += min;
    }
    printf("Minimum cost= %d\n", mincost);
}

void primMST(int n, int cost[MAX][MAX]) {
    int selected[MAX], no_edge = 0, mincost = 0;
    for (int i = 0; i < n; i++)
        selected[i] = 0;

    selected[0] = 1;

    while (no_edge < n - 1) {
        int min = INF, x = 0, y = 0;
        for (int i = 0; i < n; i++) {
            if (selected[i]) {
                for (int j = 0; j < n; j++) {
                    if (!selected[j] && cost[i][j]) {
                        if (min > cost[i][j]) {
                            min = cost[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        printf("Edge %d:(%d, %d) cost:%d\n", no_edge++, x, y, cost[x][y]);
        mincost += cost[x][y];
        selected[y] = 1;
    }
    printf("Minimum cost= %d\n", mincost);
}

void menu() {
    int n, choice;
    int cost[MAX][MAX];

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (enter 0 if no edge exists):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    while (1) {
        printf("1. Kruskal's Algorithm\n");
        printf("2. Prim's Algorithm\n");
        printf("3. Exit\n");
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Kruskal's MST Algorithm:\n");
                kruskalMST(n, cost);
                break;
            case 2:
                printf("Prim's MST Algorithm:\n");
                primMST(n, cost);
                break;
            case 3:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }
}

int main() {
    menu();
    return 0;
}
