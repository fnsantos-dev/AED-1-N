#include <stdio.h>
#include <stdlib.h>

#define vertex int

typedef struct node *link;
typedef struct Graph *Graph;
struct Graph{
    vertex V,A;
    link *adj;
};  
struct node{
    vertex w;
    int valor;
    link next;
};

static link Newnode(vertex w, int valor , link next){
    link *a = malloc(sizeof(struct node));
    a->w = w;
    a->next = next;
    a->valor =valor;
    return a;
}


Graph init(int v){
    Graph *novo = malloc(sizeof(struct Graph));
    novo->V = V;
    novo->A = NULL;
    novo->adj =malloc(v*sizeof(link));
    for(vertex i = 0 ; i<v;i++){
        novo->adj[i] = NULL;
    }
    return novo;
}
void insert(Graph *p, vertex v, vertex w, int valor){
    for(link a =p->adj[v];a != NULL; a=a->next){
        if(a->w == w){
            return;
        }
        p->adj[v] = Newnode(w, valor , p->adj[w]);
        p->adj[w] = Newnode(w, valor , p->adj[v]);
        p->A++;
    }
}
