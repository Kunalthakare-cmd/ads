#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PAGES 100
#define MAX_LINKS 10
#define URL_LENGTH 50
#define FILENAME "webdata.txt"

typedef struct Page {
    char url[URL_LENGTH];
    int visited;
} Page;


typedef struct WebGraph {
    Page *pages[MAX_PAGES];
    int links[MAX_PAGES][MAX_PAGES];
    int size;
} WebGraph;


typedef struct Queue {
    int items[MAX_PAGES];
    int front, rear;
} Queue;


void initQueue(Queue *q) {
    q->front = q->rear = -1;
}

void enqueue(Queue *q, int pageIndex) {
    if (q->rear == MAX_PAGES - 1) return;   
    if (q->front == -1) q->front = 0;
    q->items[++q->rear] = pageIndex;
}

int dequeue(Queue *q) {
    if (q->front == -1) return -1;   
    int item = q->items[q->front++];
    if (q->front > q->rear) q->front = q->rear = -1;   
    return item;
}

int isQueueEmpty(Queue *q) {
    return q->front == -1;
}

 
void initWebGraph(WebGraph *web) {
    web->size = 0;
    for (int i = 0; i < MAX_PAGES; i++) {
    for (int j = 0; j < MAX_PAGES; j++) {
        web->links[i][j] = 0;
    }
}}

 
int addOrGetPage(WebGraph *web, const char *url) {
    for (int i = 0; i < web->size; i++) {
        if (strcmp(web->pages[i]->url, url) == 0) {
            return i;   
        }
    }
    
    if (web->size >= MAX_PAGES) return -1;
    Page *page = (Page *)malloc(sizeof(Page));
    strcpy(page->url, url);
    page->visited = 0;
    web->pages[web->size] = page;
    return web->size++;
}


void addLink(WebGraph *web, int fromIndex, int toIndex) {
    if (fromIndex >= 0 && fromIndex < web->size && toIndex >= 0 && toIndex < web->size) {
        web->links[fromIndex][toIndex] = 1;
    }
}


void loadWebGraphFromFile(WebGraph *web, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
       
        line[strcspn(line, "\n")] = 0;
        
         
        char *fromUrl = strtok(line, ", ");
        if (fromUrl) {
             
            int fromIndex = addOrGetPage(web, fromUrl);

            
            char *toUrl = strtok(NULL, ", ");
            while (toUrl) {
                int toIndex = addOrGetPage(web, toUrl);
                addLink(web, fromIndex, toIndex);
                toUrl = strtok(NULL, ", ");
            }
        }
    }

    fclose(file);
}

 
void crawl(WebGraph *web, int startPage) {
    Queue queue;
    initQueue(&queue);
    enqueue(&queue, startPage);
    web->pages[startPage]->visited = 1;

    printf("Starting web crawl from: %s\n\n", web->pages[startPage]->url);

    while (!isQueueEmpty(&queue)) {
        int pageIndex = dequeue(&queue);
        Page *currentPage = web->pages[pageIndex];
        printf("Visiting page: %s\n", currentPage->url);

        int linkCount = 0;
        for (int i = 0; i < web->size; i++) {
            if (web->links[pageIndex][i]) {
                printf("  Found link to: %s", web->pages[i]->url);
                if (!web->pages[i]->visited) {
                    web->pages[i]->visited = 1;
                    enqueue(&queue, i);
                    printf(" - Added to crawl queue.\n");
                } else {
                    printf(" - Already visited.\n");
                }
                linkCount++;
            }
        }
        if (linkCount == 0) {
            printf("  No links found on this page.\n");
        }
        printf("\n");
    }
}

 
void freeWebGraph(WebGraph *web) {
    for (int i = 0; i < web->size; i++) {
        free(web->pages[i]);
    }
}

int main() {
    WebGraph web;
    initWebGraph(&web);

   
    loadWebGraphFromFile(&web,FILENAME);

    
    if (web.size > 0) {
        crawl(&web, 0);
    } else {
        printf("No pages found in the file.\n");
    }

    freeWebGraph(&web);
    return 0;
}
