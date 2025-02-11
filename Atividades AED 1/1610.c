#include <stdio.h>
#include <stdlib.h>

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

static link Newnode(vertex w, int valor, link next) {
    link a = malloc(sizeof(struct node));
    a->w = w;
    a->next = next;
    a->valor = valor;
    return a;
}

Graph init(int v) {
    Graph novo = malloc(sizeof(struct Graph));
    novo->V = v;
    novo->A = 0;
    novo->adj = malloc(v * sizeof(link));
    for (int i = 0; i < v; i++) {
        novo->adj[i] = NULL;
    }
    return novo;
}

void insert(Graph G, vertex v, vertex w, int valor) {
    G->adj[v] = Newnode(w, valor, G->adj[v]);
    G->A++;
}

int dfs(Graph G, vertex v, int *visitado, int *stack) {
    if (!visitado[v]) {
        visitado[v] = 1;
        stack[v] = 1;

        for (link a = G->adj[v]; a != NULL; a = a->next) {
            if (!visitado[a->w] && dfs(G, a->w, visitado, stack)) {
                return 1;
            } else if (stack[a->w]) {
                return 1;
            }
        }
    }
    stack[v] = 0;
    return 0;
}

int ciclo(Graph G) {
    int *visitado = calloc(G->V, sizeof(int));
    int *stack = calloc(G->V, sizeof(int));

    for (int i = 0; i < G->V; i++) {
        if (!visitado[i] && dfs(G, i, visitado, stack)) {
            free(visitado);
            free(stack);
            return 1;
        }
    }
    free(visitado);
    free(stack);
    return 0;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int N, M;
        scanf("%d %d", &N, &M);
        Graph G = init(N);

        for (int i = 0; i < M; i++) {
            int A, B;
            scanf("%d %d", &A, &B);
            insert(G, A - 1, B - 1, 1);
        }

        printf("%s\n", ciclo(G) ? "SIM" : "NAO");

        free(G->adj);
        free(G);
    }
    return 0;
}

