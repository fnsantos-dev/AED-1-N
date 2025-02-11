#include <stdio.h>
#include <stdlib.h>
#define vertex int

typedef struct node *link;
typedef struct Graph *Graph;

struct node
{
    vertex w;
    int valor;
    link next;
};
struct Graph{
    vertex V;
    vertex A;
    link *adj;
};

static link Newnode(vertex w, int valor, link next){
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
    for(vertex i = 0; i < v; i++){
        novo->adj[i] = NULL;
    }
    return novo;
}
void insert(Graph G, vertex w, vertex w ,int valor){
    G->adj[v] = Newnode(w, valor, G->adj[v]);
    G->adj[w] = Newnode(w, valor, G->adj[w]);
    G->A++;
}
