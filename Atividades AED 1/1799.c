#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_PONTOS 4005
#define INF INT_MAX

typedef struct {
    int destino, peso;
} Aresta;

typedef struct {
    Aresta arestas[MAX];
    int tamanho;
} ListaAdj;

ListaAdj grafo[MAX];
int dist[MAX];
int visitado[MAX];


void adicionarAresta(int u, int v) {
    grafo[u].arestas[grafo[u].tamanho++] = (Aresta){v, 1};
    grafo[v].arestas[grafo[v].tamanho++] = (Aresta){u, 1};
}

void dijkstra(int origem) {
    for (int i = 0; i < MAX; i++) {
        dist[i] = INF;
        visitado[i] = 0;
    }
    dist[origem] = 0;
    
    for (int i = 0; i < MAX; i++) {
        int u = -1;
        for (int j = 0; j < MAX; j++) {
            if (!visitado[j] && (u == -1 || dist[j] < dist[u])) {
                u = j;
            }
        }
        
        if (dist[u] == INF) break;
        visitado[u] = 1;
        
        for (int j = 0; j < grafo[u].tamanho; j++) {
            int v = grafo[u].arestas[j].destino;
            if (dist[u] + 1 < dist[v]) {
                dist[v] = dist[u] + 1;
            }
        }
    }
}

int obterIndice(char *nome, int *contador, char nomes[MAX][32]) {
    for (int i = 0; i < *contador; i++) {
        if (strcmp(nomes[i], nome) == 0) return i;
    }
    strcpy(nomes[*contador], nome);
    return (*contador)++;
}

int main() {
    int pontos, ligacoes;
    scanf("%d %d", &pontos, &ligacoes);
    
    char nomes[MAX][32];
    int contador = 0;
    
    int entrada = -1, saida = -1, queijo = -1;
    
    for (int i = 0; i < ligacoes; i++) {
        char origem[32], destino[32];
        scanf("%s %s", origem, destino);
        
        int u = obterIndice(origem, &contador, nomes);
        int v = obterIndice(destino, &contador, nomes);
        
        if (strcmp(origem, "Entrada") == 0) entrada = u;
        if (strcmp(destino, "Entrada") == 0) entrada = v;
        if (strcmp(origem, "Saida") == 0) saida = u;
        if (strcmp(destino, "Saida") == 0) saida = v;
        if (strcmp(origem, "*") == 0) queijo = u;
        if (strcmp(destino, "*") == 0) queijo = v;
        
        adicionarAresta(u, v);
    }
    
    dijkstra(entrada);
    int caminho_entrada_queijo = dist[queijo];
    
    dijkstra(queijo);
    int caminho_queijo_saida = dist[saida];
    
    printf("%d\n", caminho_entrada_queijo + caminho_queijo_saida);
    
    return 0;
}