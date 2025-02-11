#include <stdio.h>
#include <stdlib.h>

#define vertex int

struct Graph{
    int v;
    int A;
    link *adj;
};

typedef struct Graph *Graph;
typedef struct node *link;

struct node{
    vertex w;
    int valor;
    link next;
};

static link Newnode(vertex w,int valor, link next){
    link a = malloc(sizeof(struct node));
    a->w = w;
    a->next = next;
    a->valor = valor;
    return a;
}

Graph inicializa(int v){
    Graph novo = malloc(sizeof(struct *novo));
    novo-> v = v;
    novo->a = NULL;
    novo->adj = malloc(v * sizeof(link));
    for(vertex i = 0; i < v ; i++){
        novo->adj[i]= NULL;
    }
    return novo;
}

void inserir(Graph novo , vertex v, vertex w, int valor){
    for(link a = novo->adj[v];a != NULL; a = a->next){
        if(a->w == w){
            return;
        }
        novo->adj[v] = Newnode(w , novo->adj[v]);
        novo->adj[w] = Newnode(w, , nobo->adj[w]);
        novo->A++;
    }
}

int busca(Graph g , vertex ma, vertex na, int valor){
    bool mature[1000];
    for( vertex i = 0 ; i< g->v; i++){
        na[i] = -1;
        mature[i] = false;
        dist[i]= INT_MAX;
    }
    na[ma] =ma;
    dist[ma] = 0;

    while (true)
    {
        int min = INT_MAX;
        vertex y;
        for(vertex z = 0 ; z<g->v;z++){
            if (mature[z])
            {
                continue;
            }
            if (dist[z]<min)
            {
                min = dist[z];
                y = z;
            }
        }
        if (min ==INT_MAX){
            break;
        }
        for(link a = g->adj[y];a != NULL; a =a->next){
            if(mature[a->w]){
                continue;
            }
            if(dist[y]+ a->c < dist[a->w]){
                dist[a->w] = dist[y] + a->c;
                na[a->w] = y;
            }
        }
        mature[y]=true;

    }
    
}