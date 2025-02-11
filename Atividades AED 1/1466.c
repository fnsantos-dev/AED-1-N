#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *esq;
    struct no *dir;
} no;

typedef struct no *arvore;

arvore inicializa(int x) {
    arvore novo = (arvore)malloc(sizeof(no));
    if (novo == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    novo->valor = x;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

void insere(arvore *p, int valor) {
    if (*p == NULL) {
        *p = inicializa(valor);
    } else if (valor < (*p)->valor) {
        insere(&(*p)->esq, valor);
    } else {
        insere(&(*p)->dir, valor);
    }
}
void libera(arvore p) {
    if (p != NULL) {
        libera(p->esq);
        libera(p->dir);
        free(p);
    }
}
void imprime(arvore raiz) {
    if (raiz == NULL) return;

    arvore fila[500];  
    int inicio = 0, fim = 0;

    fila[fim++] = raiz;  

    int primeiro = 1;  

    while (inicio < fim) {
        arvore atual = fila[inicio++];

        if (!primeiro) {
            printf(" ");  
        }
        printf("%d ", atual->valor);
        primeiro = 0;  

        if (atual->esq) fila[fim++] = atual->esq;
        if (atual->dir) fila[fim++] = atual->dir;
    }

    printf("\n");  
}

int main() {
    int C, N, num, caso = 1;

    scanf("%d", &C);
    for (int i = 0; i < C; i++) {
        arvore raiz = NULL;

        scanf("%d", &N);
        for (int j = 0; j < N; j++) {
            scanf("%d", &num);
            insere(&raiz, num);
        }

        printf("Case %d:\n", caso++);
        imprime(raiz);
        libera(raiz);

        if (i < C - 1) {  
            printf("\n");  // Linha em branco apenas entre casos de teste, não após o último
        }
    }

    return 0;
}