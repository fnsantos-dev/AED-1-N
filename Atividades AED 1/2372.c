#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define vertex int

typedef struct node *link; 
typedef struct Graph *Graph;

struct node {
    vertex w;
    int valor;
    link next;
};

struct Graph {
    vertex V;
    vertex A;
    link *adj;
};

static link Newnode(vertex w, int valor , link next){
    link a = malloc(sizeof(struct node));
    a->w = w;
    a->next = next;
    a->valor = valor;
    return a;
}

Graph init(int v){
    Graph novo = malloc(sizeof(struct Graph));
    novo->V = v;
    novo->A = 0;
    novo->adj = malloc(v * sizeof(link));
    for (int i = 0; i < v; i++) {
        novo->adj[i] = NULL;
    }
    return novo;
}

void insert(Graph G, vertex v, vertex w, int valor){
    G->adj[v] = Newnode(w, valor, G->adj[v]);
    G->adj[w] = Newnode(v, valor, G->adj[w]);
    G->A++;
}

int dijkstra(Graph G, int source, int *dist){
    int V = G->V;
    int *visited = malloc(V * sizeof(int));
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }
    dist[source] = 0;

    for (int i = 0; i < V; i++) {
        int u = -1;
        for (int j = 0; j < V; j++) {
            if (!visited[j] && (u == -1 || dist[j] < dist[u])) {
                u = j;
            }
        }
        
        visited[u] = 1;
        
        link adj = G->adj[u];
        while (adj != NULL) {
            int v = adj->w;
            int weight = adj->valor;
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
            adj = adj->next;
        }
    }
    free(visited);
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    Graph G = init(N);

    for (int i = 0; i < M; i++) {
        int U, V, W;
        scanf("%d %d %d", &U, &V, &W);
        insert(G, U, V, W);
    }

    int min_max_distance = INT_MAX;
    
    for (int i = 0; i < N; i++) {
        int *dist = malloc(N * sizeof(int));
        dijkstra(G, i, dist);
        
        int max_distance = 0;
        for (int j = 0; j < N; j++) {
            if (dist[j] > max_distance) {
                max_distance = dist[j];
            }
        }
        
        if (max_distance < min_max_distance) {
            min_max_distance = max_distance;
        }

        free(dist);
    }

    printf("%d\n", min_max_distance);

    return 0;
}