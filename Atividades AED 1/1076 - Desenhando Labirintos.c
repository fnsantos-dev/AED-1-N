#include <stdio.h>
#include <stdlib.h>
#define vertex int
struct Graph{
    int V;
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

static link Newnod(vertex w, int valor, link next){
    link a = malloc(sizeof(struct node));
    a->w = w;
    a->next = next;
    a->valor = valor;
    return a;
}
Graph init(int v){
    Graph novo = malloc(sizeof(struct *novo));
    novo->v = v;
    novo-> a = NULL;
    novo->adj = malloc(v *sizeof(link));
    for(vertex i =0; i<v; i++){
        novo -> adj[i] = NULL;
    }
    return novo; 
}
void insert(Graph G,  vertex v, vertex w,int valor){
    G->adj[v] = Newnode(w,valor,novo->adj[v]);
    G->adj[w] = Newnode(w,valor, novo->adj[w]);
    novo->A++;
}
busca( Graph G , vertex node, int *visitado){
    visitado[node]= 1;
    for(link a = G->adj[node]; a!= NULL; a = a->next){
        if(!visited[a->w]){
            busca(G, a->w, visitado);
        }
    }
}
int conexao(Graph G){
    int *visitado = calloc(G->V, sizeof(int));
    int inicio = -1;
    for(int i = 0; i< G->V; i++){
        inicio = i;
        break;
    }
    if( inicio == -1){
        return 1;
    }
    busca(G, inicio, visitado);
    for(int i = 0 ;i<G->V; i++){
        if(G->adj[i] !=NULL && !visitado[i]){
            free(visitado);
            return 0;
        }
    }
    free(visitado);
    return 1;
}
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int inicio, V, A;
        scanf("%d %d %d" , &inicio , &V , &A);
        Graph G = init(V);
        for(int i = 0; i<A;i++){
            int u,v, valor = 1;
            scanf("%d %d", &u, &v);
            insert(G, u,v,valor);

        }
        if(!conexao(G)){
            printf("-1\n");
        }
        else{
            printf("%d\n", A);
        }
    free(G->adj);
    free(G);
    }
    return 0;
}
