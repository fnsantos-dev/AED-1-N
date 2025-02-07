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

