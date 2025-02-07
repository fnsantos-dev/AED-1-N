#include <stdio.h>
#include <stdlib.h>

#define vertex int

typedef struct node *link;

typedef struct node {
    vertex w;
    int valor;
    link next;
} node;

typedef struct Graph {
    int V;
    int A;
    link *adj;
} *Graph;

typedef struct Edge {
    vertex v, w;
    int valor;
} Edge;

static link Newnode(vertex w, int valor, link next) {
    link a = malloc(sizeof(struct node));
    a->w = w;
    a->next = next;
    a->valor = valor;
    return a;
}

Graph inicializa(int v) {
    Graph novo = malloc(sizeof(struct Graph));
    novo->V = v;
    novo->A = 0;
    novo->adj = malloc(v * sizeof(link));
    for (vertex i = 0; i < v; i++) {
        novo->adj[i] = NULL;
    }
    return novo;
}

void inserir(Graph G, vertex v, vertex w, int valor) {
    G->adj[v] = Newnode(w, valor, G->adj[v]);
    G->adj[w] = Newnode(v, valor, G->adj[w]);
    G->A++;
}

int comparar(const void *a, const void *b) {
    return ((Edge *)a)->valor - ((Edge *)b)->valor;
}

int find(int parent[], int i) {
    if (parent[i] == i) return i;
    return parent[i] = find(parent, parent[i]);
}

void unir(int parent[], int rank[], int x, int y) {
    int rotax = find(parent, x);
    int rotay = find(parent, y);
    if (rank[rotax] < rank[rotay])
        parent[rotax] = rotay;
    else if (rank[rotax] > rank[rotay])
        parent[rotay] = rotax;
    else {
        parent[rotay] = rotax;
        rank[rotax]++;
    }
}

int kruskal(Edge edges[], int N, int M) {
    qsort(edges, M, sizeof(Edge), comparar);
    int parent[N], rank[N];
    for (int i = 0; i < N; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
    int custo = 0, edges_add = 0;
    for (int i = 0; i < M && edges_add < N - 1; i++) {
        int v = edges[i].v, w = edges[i].w, valor = edges[i].valor;
        if (find(parent, v) != find(parent, w)) {
            unir(parent, rank, v, w);
            custo += valor;
            edges_add++;
        }
    }
    return custo;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    Graph G = inicializa(N);
    Edge edges[M];
    for (int i = 0; i < M; i++) {
        int u, v, valor;
        scanf("%d %d %d", &u, &v, &valor);
        u--, v--;
        edges[i] = (Edge){u, v, valor};
        inserir(G, u, v, valor);
    }
    printf("%d\n", kruskal(edges, N, M));
    return 0;
}