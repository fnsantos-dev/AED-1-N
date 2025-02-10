#include <stdio.h>
#include <stdlib.h>

#define vertex int

typedef struct node {
    vertex w;
    int valor;
    struct node *next;
} *link;

typedef struct Graph {
    int v;
    int A;
    link *adj;
} *Graph;

int pre[1000], cnt;
static link Newnode(vertex w, int valor, link next) {
    link a = malloc(sizeof(struct node));
    a->w = w;
    a->valor = valor;
    a->next = next;
    return a;
}
Graph inicializa(int v) {
    Graph novo = malloc(sizeof(struct Graph));
    novo->v = v;
    novo->A = 0;
    novo->adj = malloc(v * sizeof(link));
    for (vertex i = 0; i < v; i++) {
        novo->adj[i] = NULL;
    }
    return novo;
}
void inserir(Graph novo, vertex v, vertex w, int valor) {
    for (link a = novo->adj[v]; a != NULL; a = a->next) {
        if (a->w == w) return;
    }
    novo->adj[v] = Newnode(w, valor, novo->adj[v]);
    novo->adj[w] = Newnode(v, valor, novo->adj[w]);
    novo->A++;
}
static void dfsr(Graph G, vertex v, int depth) {
    pre[v] = cnt++;
    for (int i = 0; i < depth * 2; i++){
        printf(" ");
    }
    printf("%d", v);

    for (link a = G->adj[v]; a != NULL; a = a->next) {
        vertex w = a->w;
        if (pre[w] == -1) {
            printf("-%d pathR(G,%d)\n", v, w);
            dfsr(G, w, depth + 1);
        }
    }

    printf("\n");
}

void buscaEmProfundidade(Graph G) {
    for (vertex v = 0; v < G->v; v++){
        pre[v] = -1;
    }  
    cnt = 0;

    for (vertex v = 0; v < G->v; v++) {
        if (pre[v] == -1) {
            dfsr(G, v, 0);
            printf("\n");
        }
    }
}
int main() {
    int N;
    scanf("%d", &N);

    for (int t = 0; t < N; t++) {
        int V, E;
        scanf("%d %d", &V, &E);
        
        Graph G = inicializa(V);

        for (int i = 0; i < E; i++) {
            int u, v, valor;
            scanf("%d %d %d", &u, &v, &valor);
            inserir(G, u, v, valor);
        }

        buscaEmProfundidade(G);
    }

    return 0;
}