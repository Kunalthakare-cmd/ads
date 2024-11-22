#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node** adjLists;
    int* visited;
};

struct Node* createNode(int v) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjLists = malloc(vertices * sizeof(struct Node*));
    graph->visited = malloc(vertices * sizeof(int));
    
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void DFS(struct Graph* graph, int vertex) {
    struct Node* adjList = graph->adjLists[vertex];
    struct Node* temp = adjList;
    
    graph->visited[vertex] = 1;
    printf("%d ", vertex);

    while (temp != NULL) {
        int connectedVertex = temp->vertex;
        if (graph->visited[connectedVertex] == 0) {
            DFS(graph, connectedVertex);
        }
        temp = temp->next;
    }
}

void BFS(struct Graph* graph, int startVertex) {
    struct Node* adjList;
    struct Node* temp;
    int* queue = malloc(graph->numVertices * sizeof(int));
    int front = 0, rear = 0;

    graph->visited[startVertex] = 1;
    queue[rear] = startVertex;
    rear++;

    while (front < rear) {
        int currentVertex = queue[front];
        printf("%d ", currentVertex);
        front++;

        adjList = graph->adjLists[currentVertex];
        temp = adjList;

        while (temp) {
            int adjVertex = temp->vertex;

            if (graph->visited[adjVertex] == 0) {
                queue[rear] = adjVertex;
                rear++;
                graph->visited[adjVertex] = 1;
            }
            temp = temp->next;
        }
    }
}

void menu() {
    int vertices = 0, choice, start, src, dest;
    struct Graph* graph = NULL;
    
    while (1) {
        printf("1. Create Graph\n");
        printf("2. Add Edge\n");
        printf("3. DFS Traversal\n");
        printf("4. BFS Traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (graph != NULL) {
                    free(graph->adjLists);
                    free(graph->visited);
                    free(graph);
                }
                printf("Enter number of vertices: ");
                scanf("%d", &vertices);
                graph = createGraph(vertices);
                printf("Graph with %d vertices created.\n", vertices);
                break;
            case 2:
                if (graph == NULL) {
                    printf("Graph not created yet! Please create the graph first.\n");
                } else {
                    printf("Enter source vertex: ");
                    scanf("%d", &src);
                    printf("Enter destination vertex: ");
                    scanf("%d", &dest);
                    addEdge(graph, src, dest);
                    printf("Edge added between %d and %d\n", src, dest);
                }
                break;
            case 3:
                if (graph == NULL) {
                    printf("Graph not created yet! Please create the graph first.\n");
                } else {
                    printf("Enter the starting vertex for DFS: ");
                    scanf("%d", &start);
                    for (int i = 0; i < vertices; i++) graph->visited[i] = 0;
                    printf("DFS Traversal: ");
                    DFS(graph, start);
                    printf("\n");
                }
                break;
            case 4:
                if (graph == NULL) {
                    printf("Graph not created yet! Please create the graph first.\n");
                } else {
                    printf("Enter the starting vertex for BFS: ");
                    scanf("%d", &start);
                    for (int i = 0; i < vertices; i++) graph->visited[i] = 0;
                    printf("BFS Traversal: ");
                    BFS(graph, start);
                    printf("\n");
                }
                break;
            case 5:
                printf("Exiting the program.\n");
                if (graph != NULL) {
                    free(graph->adjLists);
                    free(graph->visited);
                    free(graph);
                }
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
