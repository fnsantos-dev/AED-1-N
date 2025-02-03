#include <stdio.h>
#include <stdlib.h>

#define vertex int
typedef struct node *link;

typedef struct node{
    vertex w;
    int valor;
    link next;
}node;

typedef struct Graph{
    int V;
    int A;
    link *adj;
}*Graph;
typedef struct Edge {
    vertex v, w;
    int valor;  
} Edge;

static link Newnode(vertex w, int valor, link next){
    link a =malloc(sizeof(struct node));
    a->w = w;
    a->next = next;
    a->valor = valor;
    return a;
}

Graph init(int v){
    Graph novo = malloc(sizeof(struct Graph));
    novo->V = v ;
    novo->A = 0;
    novo->adj = malloc(v* sizeof(link));
    for(vertex i = 0;i < v ; i++){
        novo->adj[i] = NULL;
    }
    return novo;
}
void inserir(Graph G, vertex v, vertex w, int valor){
    G->adj = Newnode(w,valor,G->adj[v]);
    G->adj = Newnode(v,valor,G->adj[w]);
    G->A++;
}
int find(int parent[], int i) {
    if (parent[i] == i) return i; // Se for o próprio representante, retorna ele
    return parent[i] = find(parent, parent[i]); // Aplica compressão de caminho
}

// Função para unir dois conjuntos (Union-Find com rank)
void unir(int parent[], int rank[], int x, int y) {
    int rootX = find(parent, x);
    int rootY = find(parent, y);
    if (rank[rootX] < rank[rootY]) // Se o rank de rootX for menor, anexa a rootX a rootY
        parent[rootX] = rootY;
    else if (rank[rootX] > rank[rootY]) // Se o rank de rootY for menor, anexa rootY a rootX
        parent[rootY] = rootX;
    else { // Se forem iguais, escolhe um e incrementa seu rank
        parent[rootY] = rootX;
        rank[rootX]++;
    }
}

// Função de comparação para ordenar as arestas pelo peso
int comparar(const void *a, const void *b) {
    return ((Edge *)a)->valor - ((Edge *)b)->valor;
}

// Implementação do Algoritmo de Kruskal para encontrar a Árvore Geradora Mínima
int kruskal(Graph G, Edge edges[], int E) {
    qsort(edges, E, sizeof(Edge), comparar); // Ordena as arestas por peso crescente
    int parent[G->V], rank[G->V];
    for (int i = 0; i < G->V; i++) { // Inicializa os conjuntos disjuntos
        parent[i] = i;
        rank[i] = 0;
    }
    int mst_cost = 0, edges_added = 0;
    for (int i = 0; i < E && edges_added < G->V - 1; i++) { // Percorre as arestas ordenadas
        int v = edges[i].v, w = edges[i].w, valor = edges[i].valor;
        if (find(parent, v) != find(parent, w)) { // Se não formam um ciclo
            unir(parent, rank, v, w); // Une os conjuntos dos vértices
            mst_cost += valor; // Adiciona o peso da aresta ao custo total
            edges_added++; // Incrementa o número de arestas adicionadas à MST
        }
    }
    return mst_cost; // Retorna o custo total da MST
}