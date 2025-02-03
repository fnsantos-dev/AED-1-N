#include <stdio.h>
#include <stdlib.h>
#define vertex int
typedef struct Graph *Graph;
typedef struct node *link;
struct Graph{
    int V;
    int A;
    link *adj;
};
struct node{
    vertex w;
    int valor;
    link next;
};

static link Newnode(vertex w, int valor, link next){
    link a = malloc(sizeof(struct node));
    a->w = w;
    a->next = next;
    a->valor = valor;
    return a;
}

Graph init(ini v){
    Graph *novo = malloc(sizeof(struct Graph));
    novo->v = v;
    novo-> a = NULL;
    novo->adj = malloc(v *sizeof(link));
    for(vertex i = 0;i<v; i++){
        novo ->adj[i] = NULL;
    }
    return novo;
}
void insert(Graph G, vertex v, vertex w, int valor){
    G->adj[v]=Newnode(w,valor,novo->adj[v]);
    G->adj[w] = Newnode(w,valor, novo->adj[w]);
    novo->A++;
}
void dfs(Graph G, vertex v, int visitados[]){
    visitados[v] = 1;
    for(link l = G->adj[v]; l != NULL; l= l->next){
        if(!visitados[l->w]){
            dfs(G, l->,visitados);
        }
    }
}
int main(){
    int N,L;
    scanf("%d %d", &N , &L);
    Graph G = init(&N);
    for(int i = 0;i<L; i++){
        int X,Y;
        scanf("%d %d", &X , &Y);
        insert(G, X-1, Y-1);
    }
    int visitado[N];
    for (int i = 0; i < N; i++) {
        visitado[i] = 0; 
    }
    
    dfs(G, 0, visitado);
    for (int i = 0; i < N; i++) {
        if (!visitado[i]) {
            printf("INCOMPLETO\n");
            return 0;
        }
    }
    
    printf("COMPLETO\n");
    return 0;
}

